#include "iostream"
#include "cmath"
using namespace std;

int n;
int a[100][100];
int maxNum[100][5];
int main(){
    cin >> n;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < i+1; ++j) {
            cin >> a[i][j];
        }
    }

    // i行 j列
    for (int i = n-1; i>=1; i--) {
        for (int j = 1; j < n+1; ++j) {
            a[i][j] = max(a[i+1][j]+a[i][j] , a[i+1][j+1]+a[i][j] );
        }
    }

    maxNum[1][1] = 1;
    maxNum[1][2] = 1;
    for (int i = 2; i < n+1; ++i) {
        //设上一层最大的坐标为a[x][y]，则本次在a[x+1][y]和a[x+1][y+1]中查找
        maxNum[i][1] = i;
        if(a[i][maxNum[i-1][2]]  > a[i][maxNum[i-1][2]+1]){
            maxNum[i][2] = maxNum[i-1][2];
        } else{
            maxNum[i][2] = maxNum[i-1][2]+1;
        }
    }

    for (int i = n; i >0; i--) {
        cout << maxNum[i][1]<<","<<maxNum[i][2];
        if(i!=1){
            cout << "->";
        }
    }

    cout << endl;
    cout << a[1][1];

    return 0;
}