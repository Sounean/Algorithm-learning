#include <iostream>
#include <cstring>

using namespace std;

// 马可能会出现的位子 (最多总共9个)
int horsePoints[9][2] = {
    {0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}
};

int BPoint[2] = {0,0};
long long dp[25][25]; // 使用long long避免溢出
bool isHorse[25][25]; // 标记马的位置

void initHorseOtherPoints() {
    for(int i = 1; i < 9; i++) {
        horsePoints[i][0] = horsePoints[i][0] + horsePoints[0][0];
        horsePoints[i][1] = horsePoints[i][1] + horsePoints[0][1];
    }
}

void markHorsePositions() {
    memset(isHorse, false, sizeof(isHorse));
    for(int i = 0; i < 9; i++) {
        int x = horsePoints[i][0];
        int y = horsePoints[i][1];
        if(x >= 0 && x <= 20 && y >= 0 && y <= 20) {
            isHorse[x][y] = true;
        }
    }
}

long long solve() {
    // 初始化dp数组
    memset(dp, 0, sizeof(dp));
    
    // 如果起点被马控制，直接返回0
    if(isHorse[0][0]) return 0;
    
    dp[0][0] = 1; // 起点到起点的路径数为1
    
    // 填充第一行
    for(int j = 1; j <= BPoint[1]; j++) {
        if(!isHorse[0][j]) {
            dp[0][j] = dp[0][j-1];
        }
    }
    
    // 填充第一列
    for(int i = 1; i <= BPoint[0]; i++) {
        if(!isHorse[i][0]) {
            dp[i][0] = dp[i-1][0];
        }
    }
    
    // 填充其余位置
    for(int i = 1; i <= BPoint[0]; i++) {
        for(int j = 1; j <= BPoint[1]; j++) {
            if(!isHorse[i][j]) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    
    return dp[BPoint[0]][BPoint[1]];
}

int main() {
    cin >> BPoint[0] >> BPoint[1] >> horsePoints[0][0] >> horsePoints[0][1];
    
    // 补充完整其他马的落地坐标
    initHorseOtherPoints();
    
    // 标记马的位置
    markHorsePositions();
    
    // 获取总共可能的路径数
    long long nums = solve();
    
    cout << nums;
    return 0;
} 