#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 方法1：循环除以10（推荐，效率高）
int getFirstDigit1(int n) {
    if (n == 0) return 0;
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

// 方法2：使用字符串转换
int getFirstDigit2(int n) {
    string s = to_string(n);
    return s[0] - '0';
}

// 方法3：使用对数函数
int getFirstDigit3(int n) {
    if (n == 0) return 0;
    int digits = (int)log10(n);
    return n / (int)pow(10, digits);
}

int main() {
    int test_cases[] = {998, 12345, 7, 0, 1000, 999999};
    
    cout << "测试不同方法获取最高位数字：" << endl;
    cout << "数字\t方法1\t方法2\t方法3" << endl;
    cout << "--------------------------------" << endl;
    
    for (int num : test_cases) {
        cout << num << "\t" 
             << getFirstDigit1(num) << "\t"
             << getFirstDigit2(num) << "\t"
             << getFirstDigit3(num) << endl;
    }
    
    return 0;
}




