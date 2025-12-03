#include "iostream"
using namespace std;

int n;
int a[150][150];
int main() {
    cin >> n;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<i+1;j++){
            cin >> a[i][j];
        }
    }

//    for(int i=1;i<n+1;i++){
//        for(int j=1;j<i+1;j++){
//            cout<< a[i][j] << " ";
//        }
//        cout << endl;
//    }

    for (int i = n-1; i >=1 ; i--)
    {
        for(int j=1;j<n+1;j++){
            a[i][j] = max(a[i][j]+a[i+1][j] , a[i][j]+a[i+1][j+1]);
        }
    }

    cout << a[1][1];
    return 0;
}