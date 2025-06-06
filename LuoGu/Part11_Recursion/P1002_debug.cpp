#include <iostream>
using namespace std;

// 马可能的偏移量
int horseOffset[9][2] = {
    {0,0},   // 马本身位置
    {-2,1}, {-1,2}, {1,2}, {2,1},
    {2,-1}, {1,-2}, {-1,-2}, {-2,-1}
};

int horsrPoint[30][30] = {0};    // 标记马控制的点
int mem[30][30];                 // 记忆化数组
bool visited[30][30] = {false};  // 访问标记

int B[3], FO[3]; // B是终点、FO是马的坐标

int getF(int x, int y) {
    // 边界检查：如果超出范围或到达负坐标，返回0
    if (x < 0 || y < 0) {
        return 0;
    }
    
    // 记忆化：如果已经计算过，直接返回
    if (visited[x][y]) {
        return mem[x][y];
    }
    
    // 如果是马控制的点，无法通过
    if (horsrPoint[x][y]) {
        mem[x][y] = 0;
        visited[x][y] = true;
        return 0;
    }
    
    // 到达起点：这是递归的终止条件
    if (x == 0 && y == 0) {
        mem[x][y] = 1;
        visited[x][y] = true;
        return 1;
    }
    
    // 递归计算：从左边来的路径 + 从上边来的路径
    int result = getF(x-1, y) + getF(x, y-1);
    
    // 保存结果
    mem[x][y] = result;
    visited[x][y] = true;
    
    return result;
}

void getHorsePoint(int fOldx, int fOldy) {
    for (int i = 0; i < 9; ++i) {
        int nx = fOldx + horseOffset[i][0];
        int ny = fOldy + horseOffset[i][1];
        
        // 修复边界判断：只标记在有效范围内的点
        if (nx >= 0 && nx <= B[0] && ny >= 0 && ny <= B[1]) {
            horsrPoint[nx][ny] = 1;
        }
    }
}

int main() {
    cin >> B[0] >> B[1];
    cin >> FO[0] >> FO[1];
    
    getHorsePoint(FO[0], FO[1]);
    
    int cnt = getF(B[0], B[1]);
    
    cout << cnt << endl;
    
    return 0;
}

/*
关键修复点：
1. 边界判断：x < 0 || y < 0 时返回0
2. 递归终止：x == 0 && y == 0 时返回1（到达起点）
3. 马的控制点判断：nx >= 0 && nx <= B[0] && ny >= 0 && ny <= B[1]
4. 记忆化：每次计算后都保存结果

思路：从终点(B[0], B[1])开始，递推到起点(0, 0)
*/ 