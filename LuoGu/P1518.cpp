//#include <iostream>
//
//using namespace std;
//
//// 这题的精髓是通过保存状态来解决" 如果 John 和牛永远不会相遇"这一条件--》将出现过的每一刻F,C的坐标和他们要走的偏移记录下来，如果未来又出现一样的，那么就是出现重复了，也就是后面就将陷入循环了；
//
//struct Bean{
//    int currentDirIndex = 0;
//    int currentDir[2] = {0,-1};
//    int currentPoint[2];
//};
//// 二维数组承接  （如何判定永远不会相遇,这个先不管，不好进行操作）  (dx,dy)表示下一次的偏移
//// 如果产生偏移时的旋转数组 每个元素为{x方向，y方向}
//int offset[4][2] = {{0,-1},
//                    {1,0},
//                    {0,1},
//                    {-1,0}};
//
//char map[10][10];
//int cnt;    // 次数
//
//// 检查是否可以移动到指定位置
//bool canMove(int x, int y) {
//    return x >= 0 && x < 10 && y >= 0 && y < 10 && map[x][y] != '*';
//}
//
//int main(){
//    // 初始化地图和角色
//    Bean F = Bean();
//    Bean C = Bean();
//    for(int i=0;i<10;i++){
//        for (int j = 0; j < 10; ++j) {
//            cin >> map[i][j];
//            if(map[i][j] == 'F'){
//                F.currentPoint[0] = i;
//                F.currentPoint[1] = j;
//            }else if(map[i][j] == 'C'){
//                C.currentPoint[0] = i;
//                C.currentPoint[1] = j;
//            }
//        }
//    }
//
//    // 记录历史状态，避免无限循环
//    bool visited[10][10][10][10][4][4] = {false};
//
//    while (1){
//        // 记录当前状态
//        int fx = F.currentPoint[0], fy = F.currentPoint[1];
//        int cx = C.currentPoint[0], cy = C.currentPoint[1];
//        int fd = F.currentDirIndex, cd = C.currentDirIndex;
//
//        // 检查是否出现循环
//        if (visited[fx][fy][cx][cy][fd][cd]) {
//            cout << 0 << endl;  // 永远不会相遇
//            return 0;
//        }
//        visited[fx][fy][cx][cy][fd][cd] = true;
//
//        // 计算下一个位置
//        int nextFx = fx + F.currentDir[0];
//        int nextFy = fy + F.currentDir[1];
//
//        if (!canMove(nextFx, nextFy)) {
//            // 不能前进，右转
//            F.currentDirIndex = (F.currentDirIndex+1)%4;
//            F.currentDir[0] = offset[F.currentDirIndex][0];
//            F.currentDir[1] = offset[F.currentDirIndex][1];
//        } else {
//            // 正常前行
//            F.currentPoint[0] = nextFx;
//            F.currentPoint[1] = nextFy;
//        }
//
//        // 计算牛的下一个位置
//        int nextCx = cx + C.currentDir[0];
//        int nextCy = cy + C.currentDir[1];
//
//        if (!canMove(nextCx, nextCy)) {
//            // 不能前进，右转
//            C.currentDirIndex = (C.currentDirIndex+1)%4;
//            C.currentDir[0] = offset[C.currentDirIndex][0];
//            C.currentDir[1] = offset[C.currentDirIndex][1];
//        } else {
//            // 正常前行
//            C.currentPoint[0] = nextCx;
//            C.currentPoint[1] = nextCy;
//        }
//
//        cnt++;
//
//        // 检查是否相遇
//        if(F.currentPoint[0] == C.currentPoint[0] && F.currentPoint[1] == C.currentPoint[1]){
//            break;
//        }
//    }
//    cout << cnt;
//
//
//    return 0;
//}

#include <iostream>
using namespace std;

struct Bean{
    int currentDirIndex = 0;
    int currentDir[2] = {0,-1};
    int currentPoint[2];
};

int offset[4][2] = {{0,-1},
                    {1,0},
                    {0,1},
                    {-1,0}};

char map[10][10];
int cnt = 0;  // 初始化计数器

// 检查是否可以移动到指定位置
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

    // 记录历史状态，避免无限循环
    bool visited[10][10][10][10][4][4] = {false};

    while (true){
        // 检查当前状态是否已访问过
        int fx = F.currentPoint[0], fy = F.currentPoint[1];
        int cx = C.currentPoint[0], cy = C.currentPoint[1];
        int fd = F.currentDirIndex, cd = C.currentDirIndex;

        if (visited[fx][fy][cx][cy][fd][cd]) {
            cout << 0 << endl;  // 永远不会相遇
            return 0;
        }

        // 标记当前状态为已访问
        visited[fx][fy][cx][cy][fd][cd] = true;

        // 计算F的下一个位置
        int nextFx = fx + F.currentDir[0];
        int nextFy = fy + F.currentDir[1];

        if (!canMove(nextFx, nextFy)) {
            // 不能前进，右转
            F.currentDirIndex = (F.currentDirIndex+1)%4;
            F.currentDir[0] = offset[F.currentDirIndex][0];
            F.currentDir[1] = offset[F.currentDirIndex][1];
        } else {
            // 正常前行
            F.currentPoint[0] = nextFx;
            F.currentPoint[1] = nextFy;
        }

        // 计算牛的下一个位置
        int nextCx = cx + C.currentDir[0];
        int nextCy = cy + C.currentDir[1];

        if (!canMove(nextCx, nextCy)) {
            // 不能前进，右转
            C.currentDirIndex = (C.currentDirIndex+1)%4;
            C.currentDir[0] = offset[C.currentDirIndex][0];
            C.currentDir[1] = offset[C.currentDirIndex][1];
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
    }

    return 0;
}
