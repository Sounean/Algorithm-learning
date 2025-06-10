#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 多层汉诺塔的数学解法
    // 对于4柱汉诺塔，存在一个近似最优的数学公式
    
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 3 << endl;
        return 0;
    }
    
    // Frame-Stewart算法的数学近似
    // 最优分割点 k ≈ n - sqrt(2n)
    // 但为了精确，我们用递归公式
    
    // 使用递归计算（记忆化）
    static long long memo[65];
    static bool calculated[65];
    
    function<long long(int)> solve = [&](int x) -> long long {
        if (x == 0) return 0;
        if (x == 1) return 1;
        if (x == 2) return 3;
        
        if (calculated[x]) return memo[x];
        
        long long result = (1LL << x) - 1; // 3柱汉诺塔的解
        
        // 尝试所有分割点
        for (int k = 1; k < x; k++) {
            long long temp = 2 * solve(k) + (1LL << (x - k)) - 1;
            result = min(result, temp);
        }
        
        calculated[x] = true;
        memo[x] = result;
        return result;
    };
    
    cout << solve(n) << endl;
    
    return 0;
} 