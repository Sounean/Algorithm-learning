#include <cstring>
#include "iostream"
#include "string"
#include "cmath"
using namespace std;

int a[1010];
int main() {
    int n=0;
    cin >> n;

    a[n];

    // 1.列出这个序列所有两两相加的和的情况
    //2.判断这个和是否是完全平方数
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            .....

            int sum;...
            int a = sqrt(sum);
            for(a*a == sum){
                ans+1;
            }

        }
    }




    cout << ans << endl;
    return 0;
}