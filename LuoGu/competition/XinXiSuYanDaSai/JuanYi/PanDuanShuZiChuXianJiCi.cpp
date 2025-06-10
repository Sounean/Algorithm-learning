#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int count = 0;

    // 遍历从1到n的每一个数字
    for (int i = 1; i <= n; i++) {
        int num = i;

        // 计算数字k在当前数字中出现的次数
        while (num > 0) {
            if (num % 10 == k) {
                count++;
            }
            num /= 10;
        }
    }

    cout << count << endl;

    return 0;
}
