#include <iostream>
using namespace std;

int main() {
    int n, m, hx, hy;
    cin >> n >> m >> hx >> hy;
    
    // dp[i][j] 表示从起点(0,0)到点(i,j)的路径数
    long long dp[25][25];
    
    // 标记马控制的点，blocked[i][j] = true 表示点(i,j)被马控制
    bool blocked[25][25] = {false};
    
    // 马的8个可能跳跃位置 + 马本身的位置
    int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
    
    // 标记马控制的所有点（马本身位置 + 8个跳跃位置）
    for (int i = 0; i < 9; i++) {
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        
        // 只标记在棋盘范围内的点
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            blocked[nx][ny] = true;
        }
    }
    
    // 初始化dp数组
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    
    // 起点：如果起点没有被马控制，则有1种方法到达起点
    if (!blocked[0][0]) {
        dp[0][0] = 1;
    }
    
    // 动态规划填表
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            // 如果当前点被马控制，跳过（dp[i][j]保持为0）
            if (blocked[i][j]) {
                continue;
            }
            
            // 状态转移：dp[i][j] = dp[i-1][j] + dp[i][j-1]
            // 从左边来的路径数
            if (i > 0) {
                dp[i][j] += dp[i-1][j];
            }
            
            // 从上边来的路径数
            if (j > 0) {
                dp[i][j] += dp[i][j-1];
            }
        }
    }
    
    // 输出结果：从起点(0,0)到终点(n,m)的路径数
    cout << dp[n][m] << endl;
    
    return 0;
}

/*
算法解释：
1. 这是一个经典的动态规划问题
2. 状态定义：dp[i][j] = 从起点(0,0)到点(i,j)的路径数
3. 状态转移：dp[i][j] = dp[i-1][j] + dp[i][j-1]
   （当前点的路径数 = 从左边来的路径数 + 从上边来的路径数）
4. 边界条件：起点dp[0][0] = 1（如果起点未被马控制）
5. 约束条件：被马控制的点dp[i][j] = 0

时间复杂度：O(n*m)
空间复杂度：O(n*m)
*/ 