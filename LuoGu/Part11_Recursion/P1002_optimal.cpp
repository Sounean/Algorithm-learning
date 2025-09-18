#include <iostream>
#include <cstring>

using namespace std;

/**
 * 过河卒问题 - 最优解
 * 
 * 问题分析：
 * 1. 从(0,0)到(n,m)的路径数，只能向右或向下移动
 * 2. 马的位置及其控制点不能经过
 * 3. 使用动态规划，dp[i][j]表示从(0,0)到(i,j)的路径数
 * 
 * 状态转移方程：
 * dp[i][j] = dp[i-1][j] + dp[i][j-1] (如果(i,j)不被马控制)
 * dp[i][j] = 0 (如果(i,j)被马控制)
 */

const int MAXN = 25;
long long dp[MAXN][MAXN];  // 动态规划数组，使用long long避免溢出
bool blocked[MAXN][MAXN];  // 标记被马控制的点

// 马的8个可能位置相对于马当前位置的偏移量
const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

/**
 * 标记马控制的所有点
 * @param hx 马的x坐标
 * @param hy 马的y坐标
 * @param n 目标点x坐标
 * @param m 目标点y坐标
 */
void markHorseControlledPoints(int hx, int hy, int n, int m) {
    memset(blocked, false, sizeof(blocked));
    
    // 标记马本身的位置
    if (hx >= 0 && hx <= n && hy >= 0 && hy <= m) {
        blocked[hx][hy] = true;
    }
    
    // 标记马控制的8个点
    for (int i = 0; i < 8; i++) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        
        // 只标记在棋盘范围内的点
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            blocked[nx][ny] = true;
        }
    }
}

/**
 * 使用动态规划计算路径数
 * @param n 目标点x坐标
 * @param m 目标点y坐标
 * @return 从(0,0)到(n,m)的路径数
 */
long long solve(int n, int m) {
    // 初始化dp数组
    memset(dp, 0, sizeof(dp));
    
    // 如果起点被马控制，直接返回0
    if (blocked[0][0]) {
        return 0;
    }
    
    dp[0][0] = 1;  // 起点到起点的路径数为1
    
    // 填充第一行（只能从左边来）
    for (int j = 1; j <= m; j++) {
        if (!blocked[0][j]) {
            dp[0][j] = dp[0][j-1];
        }
    }
    
    // 填充第一列（只能从上面来）
    for (int i = 1; i <= n; i++) {
        if (!blocked[i][0]) {
            dp[i][0] = dp[i-1][0];
        }
    }
    
    // 填充其余位置（可以从左边或上面来）
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!blocked[i][j]) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    
    return dp[n][m];
}

int main() {
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    
    // 标记马控制的所有点
    markHorseControlledPoints(hx, hy, n, m);
    
    // 计算路径数
    long long result = solve(n, m);
    
    cout << result << endl;
    return 0;
} 