#include <iostream>
using namespace std;

// 马可能的偏移量（包括马本身的位置）
int horseOffset[9][2] = {
    {0, 0},   // 马本身的位置
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

bool blocked[25][25] = {false}; // 标记马控制的点
long long memo[25][25];         // 记忆化数组
bool visited[25][25] = {false}; // 标记是否已计算

int n, m; // 目标点坐标
int hx, hy; // 马的坐标

// 递归函数：计算从(x,y)到(n,m)的路径数
long long getF(int x, int y) {
    // 边界条件：超出棋盘
    if (x > n || y > m) {
        return 0;
    }
    
    // 边界条件：到达目标点
    if (x == n && y == m) {
        return 1;
    }
    
    // 如果这个点被马控制，无法通过
    if (blocked[x][y]) {
        return 0;
    }
    
    // 记忆化：如果已经计算过，直接返回结果
    if (visited[x][y]) {
        return memo[x][y];
    }
    
    // 递归计算：向右走 + 向下走
    memo[x][y] = getF(x + 1, y) + getF(x, y + 1);
    visited[x][y] = true;
    
    return memo[x][y];
}

// 标记马控制的所有点
void markHorseControlledPoints(int hx, int hy) {
    for (int i = 0; i < 9; i++) {
        int nx = hx + horseOffset[i][0];
        int ny = hy + horseOffset[i][1];
        
        // 只标记在棋盘范围内的点
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            blocked[nx][ny] = true;
        }
    }
}

int main() {
    cin >> n >> m >> hx >> hy;
    
    // 标记马控制的点
    markHorseControlledPoints(hx, hy);
    
    // 从起点(0,0)开始计算到终点(n,m)的路径数
    cout << getF(0, 0) << endl;
    
    return 0;
} 