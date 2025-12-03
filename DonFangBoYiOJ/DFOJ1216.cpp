#include "iostream"
#include "cmath"
using namespace std;

int n;
int a[100][100];
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

    cout << a[1][1];

    return 0;
}