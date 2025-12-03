#include "iostream"
#include "cmath"
using namespace std;

int a[150];
int main(){
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int cnt = 0;    // 次数
    // 循环停止条件：当求里面得最大值，也仍然为0时
    while (1){
        int max1 = 0;
        int min1 = 999;
        for (int i = 0; i < n; ++i) {
            max1 = max(max1,a[i]);
            if (a[i]!=0){
                min1 = min(min1,a[i]);
            }
        }
        if(max1 == 0){
            break;
        }
        for(int i=n-1;i>=0;i--){
            if (a[i] == max1){
                a[i] = a[i]-min1;
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}
