#include "iostream"
#include "cmath"
using namespace std;

int n;
int a[100][100];
int maxNum[150][5]; // 数组存储路径上的坐标
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

    // 输出更新掉的二维表
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < i+1; ++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    //1. 定义一个数组去接收路径坐标

    // 2. 从上往下遍历二维数组，去填充1点中的数组
//    maxNum[1][1] = 1;
//    maxNum[1][2] = 1;
//    for (int  i= 2;  i<=n ; i++) {
//        // 遍历行
//        maxNum[i][1] = i;
//        if(a[i][maxNum[i-1][2]]  > a[i][maxNum[i-1][2]+1]){
//            maxNum[i][2] = maxNum[i-1][2];
//        }else{
//            maxNum[i][2] = maxNum[i-1][2]+1;
//        }
//    }
//
//    for (int i = n; i >=1 ; i--) {
//        cout << maxNum[i][1] << "," << maxNum[i][2] ;
//        if(i!=1){
//            cout << "->";
//        }
//    }
//
//    cout << endl;
//    cout << a[1][1];

//    for(int i = 5;i>=1;i--){
//        for (int j = 5; j >=1 ; j--) {
//            cout << a[i][j]<< " ";
//        }
//        cout << endl;
//    }


    return 0;
}