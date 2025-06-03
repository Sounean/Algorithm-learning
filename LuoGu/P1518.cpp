#include <iostream>
using namespace std;

// 农夫和牛的实体类
struct Bean{
    int currentDirIndex = 0;
    int currentPoint[2];
};

// 移动的偏移量
int offset[4][2] = {{-1,0},  // 北（上）
                    {0,1},   // 东（右）
                    {1,0},   // 南（下）
                    {0,-1}}; // 西（左）

// 地图
char map[10][10];

// 记录历史状态，避免无限循环
bool visited[10][10][10][10][4][4] = {false};
int cnt = 0;

// 检查是否可以移动到指定位置的函数
bool canMove(int x, int y) {
    return x >= 0 && x < 10 && y >= 0 && y < 10 && map[x][y] != '*';
}

int main(){
    Bean F = Bean();
    Bean C = Bean();

    for(int i=0; i<10; i++){
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

    // 检查初始状态是否已经相遇
    if(F.currentPoint[0] == C.currentPoint[0] && F.currentPoint[1] == C.currentPoint[1]){
        cout << 0 << endl;
        return 0;
    }

    while (true){
        // 移动F
        int nextFx = F.currentPoint[0] + offset[F.currentDirIndex][0];
        int nextFy = F.currentPoint[1] + offset[F.currentDirIndex][1];

        if (!canMove(nextFx, nextFy)) {
            // 不能前进，顺时针转90度
            F.currentDirIndex = (F.currentDirIndex + 1) % 4;
        } else {
            // 正常前行
            F.currentPoint[0] = nextFx;
            F.currentPoint[1] = nextFy;
        }

        // 移动牛
        int nextCx = C.currentPoint[0] + offset[C.currentDirIndex][0];
        int nextCy = C.currentPoint[1] + offset[C.currentDirIndex][1];

        if (!canMove(nextCx, nextCy)) {
            // 不能前进，顺时针转90度
            C.currentDirIndex = (C.currentDirIndex + 1) % 4;
        } else {
            // 正常前行
            C.currentPoint[0] = nextCx;
            C.currentPoint[1] = nextCy;
        }

        cnt++;

        // 检查是否相遇
        if(F.currentPoint[0] == C.currentPoint[0] && F.currentPoint[1] == C.currentPoint[1]){
            cout << cnt << endl;
            return 0;
        }

        // 检查当前状态是否已访问过（在移动之后检查）
        int fx = F.currentPoint[0], fy = F.currentPoint[1];
        int cx = C.currentPoint[0], cy = C.currentPoint[1];
        int fd = F.currentDirIndex, cd = C.currentDirIndex;
        
        if (visited[fx][fy][cx][cy][fd][cd]) {
            cout << 0 << endl;  // 永远不会相遇
            return 0;
        }
        
        // 标记当前状态为已访问
        visited[fx][fy][cx][cy][fd][cd] = true;
    }
    return 0;
}