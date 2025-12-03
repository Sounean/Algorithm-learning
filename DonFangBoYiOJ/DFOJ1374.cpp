#include "iostream"
#include "cmath"
using namespace std;

int h,l;
int map[110][110];  // 存当前花生的颗数
int oldMap[110][110];  // 存原始花生的颗数
int a[10020];   // 经过的那个点的花生数量
int n = 0;  // 经过的点数
int main(){
    cin >> h >> l;
    for (int i = 1; i < h+1; ++i) {
        for (int j = 1; j < l+1; ++j) {
            cin >> oldMap[i][j];
            map[i][j] = oldMap[i][j];
        }
    }

    for (int i = 2; i < h+1; ++i) {
        for(int j=1;j<l+1;++j){
            if(j==1){
                //说明是第一列，只能直接加上面那行的
                map[i][j]+=map[i-1][j];
            }else{
                map[i][j]+=max(map[i-1][j],map[i][j-1]);
            }
        }
    }


    // 此处是刷新之后最大值的花生数

    // 从最后一个值开始，观察正左侧和正上侧看下哪个更大，就选哪个
    int i = h;
    int j = l;
    // 最后一个数肯定是右下角的值
    n++;
    a[0] = oldMap[h][l];
//    while (i!=1 && j!=1){
    while (!(i==1 && j==1)){
        if(map[i][j-1] > map[i-1][j]){
            // 如果当前元素左侧的值比上测值更大的话
            a[n] = oldMap[i][j-1];
            n++;
            i = i;
            j = j-1;
        }else{
            a[n] = oldMap[i-1][j];
            n++;
            i = i-1;
            j = j;
        }
    }

    for (int k = n-1; k >=0; --k) {
        cout << a[k] << " ";
    }

    return 0;
}
