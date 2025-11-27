#include "iostream"
#include "string"

using namespace std;

// 判断给定字符串是否为回文串
bool isPalindrome(const string &s) {
    int left = 0, right = (int)s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str = "";
        cin >> str;

        // 两个回文串都至少为 2，整体长度至少为 4
        if (str.length() < 4) {
            cout << "No" << endl;
            continue;
        }

        bool ok = false;
        // 枚举分割点 j，使得左边长度 >= 2 且右边长度 >= 2
        for (int j = 2; j <= (int)str.length() - 2; ++j) {
            if (isPalindrome(str.substr(0, j)) && isPalindrome(str.substr(j))) {
                cout << "Yes" << endl;
                ok = true;
                break;
            }
        }
        if (!ok) cout << "No" << endl;
    }
    return 0;
}












