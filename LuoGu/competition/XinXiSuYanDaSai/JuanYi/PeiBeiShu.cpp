#include <iostream>
#include <vector>
using namespace std;

const int MOD = 202307;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> books(m);
    for (int i = 0; i < m; i++) {
        cin >> books[i];
    }

    // dp[i][j] 表示前i种书中选出j本书的方案数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // 初始状态：选0本书有1种方案
    dp[0][0] = 1;

    // 动态规划计算
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            // 不选第i种书的方案数
            dp[i][j] = dp[i - 1][j];

            // 选k本第i种书的方案数
            for (int k = 1; k <= min(j, books[i - 1]); k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD;
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}
