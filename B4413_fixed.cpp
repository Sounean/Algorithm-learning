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
            if ((a[i] < min1) && (a[i]>0)) {
                min1 = a[i];
                minIndex = i;
            }
        }

        a[maxIndex] = a[maxIndex]-a[minIndex];  // 更新最大值（按题目要求最大值-最小值）

        int s = 0;
        for (int i = 0; i < n; i++) {
            s+=a[i];
        }
        if (s==0) {
            cout << cnt ;
            return 0;
        }
    }

}