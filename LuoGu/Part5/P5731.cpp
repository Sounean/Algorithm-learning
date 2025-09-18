#include "iostream"
using namespace std;

// 代表方向
int dir[4][2] = {
        {0,1},{1,0},{0,-1},{-1,0}
};
int map[15][15] = {0};
int main(){
    int n = 0;
    cin >> n;
    int currentPos[2] = {0,0};  // 当前坐标
    int posDirIndex = 0;    // 当前方向
    int cnt = 1;
    while (cnt<=n*n){
        map[currentPos[0]][currentPos[1]] = cnt;
        cnt++;
        // 要转弯的情况:1.再移动一次就超出边界、2.再移动一次后的坐标上已经有值了
        if((currentPos[1]+dir[posDirIndex][1])==n || ((currentPos[0]+dir[posDirIndex][0])==n)
        ||((currentPos[1]+dir[posDirIndex][1])==-1) || ((currentPos[0]+dir[posDirIndex][0])==-1)
        || map[currentPos[0]+dir[posDirIndex][0]][currentPos[1]+dir[posDirIndex][1]]!=0){
            posDirIndex++;
            posDirIndex = posDirIndex%4;
        }
        currentPos[0] = currentPos[0]+dir[posDirIndex][0];
        currentPos[1] = currentPos[1]+dir[posDirIndex][1];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%3d" , map[i][j]);
        }
        cout << endl;
    }

    return 0;
}
