#include <iostream>
#include <cmath>    // 导入这个才能用sqrt

using namespace std;

int n,k;

// 返回false表示非素数 true表示是素数
bool judgetSuShu(int a){
    bool isSuShe = true;
    int breakNum = sqrt(a);
    for(int i=2;i<=breakNum;i++){
        if (a%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    // 那不就是给所有情况列出来之后，对其求素数吗?
    cin >> n >> k;
    int a[n+2];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt = 0;

    for (int i = 0; i < n-2; ++i) {
        for (int j = i+1; j < n-1; j++) {
            for (int k = i+2; k < n; k++) {
                int sum = a[i]+a[j]+a[k];
                if(judgetSuShu(sum))cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}
