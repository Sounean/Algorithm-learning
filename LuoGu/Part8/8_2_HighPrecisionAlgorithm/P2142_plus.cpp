#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 比较两个正整数字符串的大小
// 返回: 1表示a>b, -1表示a<b, 0表示a==b
int compare(const string& a, const string& b) {
    if (a.length() > b.length()) return 1;
    if (a.length() < b.length()) return -1;
    return a.compare(b);
}

// 高精度减法，假设a >= b >= 0
string subtract(const string& a, const string& b) {
    vector<int> num1, num2, result;

    // 将字符串转换为数字数组（逆序存储）
    for (int i = a.length() - 1; i >= 0; i--) {
        num1.push_back(a[i] - '0');
    }
    for (int i = b.length() - 1; i >= 0; i--) {
        num2.push_back(b[i] - '0');
    }

    // 补齐较短的数组
    while (num2.size() < num1.size()) {
        num2.push_back(0);
    }

    // 执行减法
    int borrow = 0;
    for (int i = 0; i < num1.size(); i++) {
        int diff = num1[i] - num2[i] - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(diff);
    }

    // 去除前导零
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    // 转换回字符串
    string ans = "";
    for (int i = result.size() - 1; i >= 0; i--) {
        ans += (char)(result[i] + '0');
    }

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    int cmp = compare(a, b);

    if (cmp == 0) {
        cout << "0" << endl;
    } else if (cmp > 0) {
        cout << subtract(a, b) << endl;
    } else {
        cout << "-" << subtract(b, a) << endl;
    }

    return 0;
}