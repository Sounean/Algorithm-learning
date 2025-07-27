#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 多层汉诺塔问题
    // 对于n个盘子，最少移动次数为 2^n - 1
    // 但这里是多层汉诺塔，需要考虑分层策略
    
    // 动态规划解法
    // dp[i] 表示移动i个盘子需要的最少步数
    long long dp[65]; // 防止溢出，使用long long
    
    // 初始化
    dp[0] = 0;
    dp[1] = 1;
    
    // 状态转移方程：
    // dp[i] = min(2*dp[k] + 2^(i-k) - 1) for k = 1 to i-1
    // 其中k表示分层的位置
    
    for (int i = 2; i <= n; i++) {
        dp[i] = (1LL << i) - 1; // 初始化为传统汉诺塔的解：2^i - 1
        
        // 尝试所有可能的分层位置
        for (int k = 1; k < i; k++) {
            long long temp = 2 * dp[k] + (1LL << (i - k)) - 1;
            dp[i] = min(dp[i], temp);
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
} 