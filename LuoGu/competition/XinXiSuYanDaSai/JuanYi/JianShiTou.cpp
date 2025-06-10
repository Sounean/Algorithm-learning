#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // 确定新石头质量的范围
    int lower = min(a, b) + 1;
    int upper = max(a, b) - 1;

    // 标记是否找到解决方案
    bool found = false;

    // 遍历第三块石头可能的质量
    for (int c = lower; c <= upper; c++) {
        // 计算第四块石头的质量
        int d = 30 - a - b - c;

        // 检查第四块石头的质量是否在有效范围内
        if (d >= lower && d <= upper) {
            // 确保c <= d，以便按要求排序
            if (c <= d) {
                cout << c << " " << d << endl;
                found = true;
            }
        }
    }

    // 如果没有找到解决方案，输出0 0
    if (!found) {
        cout << "0 0" << endl;
    }

    return 0;
}
