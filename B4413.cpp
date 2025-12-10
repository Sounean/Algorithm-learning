#include "iostream"
using namespace std;

int n;
int a[150];

int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;

    while (true) {

        cnt += 1;

        int max1 = 0;
        int maxIndex = 0;   // index索引 value值
        int min1 = a[0];
        int minIndex = 0;

        for (int i = 0; i < n; i++) {
            if (a[i] >= max1) {
                max1 = a[i];
                maxIndex = i;
            }
            if (a[i] < min1) {  // 题中要求最小值也需要大于0
                min1 = a[i];
                minIndex = i;
            }
        }

        a[maxIndex] = a[maxIndex]-a[minIndex];  // 更新最大值（按题目要求最大值-最小值）

        int b = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]==0) {
                b += 0; // b是用来统计0的数量的，这个时候为0的话应该+1
            }
        }
        if (b==n) {
            cout << cnt ;
            return 0;
        }
    }

}