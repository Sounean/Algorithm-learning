#include <iostream>

using namespace std;


struct Bean{
    int currentDirIndex = 0;
    int currentDir[2] = {0,-1};
    int currentPoint[2];
};
// 二维数组承接  （如何判定永远不会相遇,这个先不管，不好进行操作）  (dx,dy)表示下一次的偏移
// 如果产生偏移时的旋转数组 每个元素为{x方向，y方向}
int offset[4][2] = {{0,-1},
                    {1,0},
                    {0,1},
                    {-1,0}};

char map[10][10];
int cnt;    // 次数
int main(){
    // 初始化地图和角色
    Bean F = Bean();
    Bean C = Bean();
    for(int i=0;i<10;i++){
        for (int j = 0; j < 10; ++j) {
            cin >> map[i][j];
            if(map[i][j] == 'F'){
                F.currentPoint[0] = i;
                F.currentPoint[1] = j;
            }else if(map[i][j] == 'C'){
                C.currentPoint[0] = i;
                C.currentPoint[1] = j;
            }
        }
    }

    while (1){
        if(F.currentPoint[0]+F.currentDir[0]<0 || F.currentPoint[1]+F.currentDir[1]<0
            ||
        )


        cnt++;
        if(F.currentPoint[0]==C.currentPoint[0] && F.currentPoint[1]==C.currentPoint[1]){
            break;
        }
    }
    cout << cnt;


    return 0;
}
