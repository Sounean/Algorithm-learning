#include <iostream>
using namespace std;

int main() {
    // 读取偏移量
    int n;
    cin >> n;

    // 遍历26个大写字母
    for (int i = 0; i < 26; i++) {
        // 计算偏移后的ASCII码值
        int cur_idx = 'A' + i + n % 26;
        // 如果超出'Z'的ASCII码值，需要回环到字母表开头
        if (cur_idx > 'Z') {
            cur_idx -= 26;
        }
        // 输出偏移后的字符
        cout << char(cur_idx);
    }
    return 0;
}