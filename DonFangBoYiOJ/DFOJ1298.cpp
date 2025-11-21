#include "iostream"
#include "cmath"
using namespace std;

int h,l;
int map[110][110];  // 存当前花生的颗数
int main(){
    cin >> h >> l;
    for (int i = 1; i < h+1; ++i) {
        for (int j = 1; j < l+1; ++j) {
            cin >> map[i][j];
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

    cout << map[h][l];
    return 0;
}

