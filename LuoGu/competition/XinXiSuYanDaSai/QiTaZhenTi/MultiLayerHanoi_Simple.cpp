#include <iostream>
#include <cmath>
using namespace std;

// 递归函数计算多层汉诺塔
long long hanoi4(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 3;
    
    // 使用Frame-Stewart算法的最优分割点
    // 理论最优分割点约为 k = n - sqrt(2*n) + 1
    int k = max(1, (int)(n - sqrt(2.0 * n) + 1));
    
    // 但为了确保最优，我们检查几个分割点
    long long result = (1LL << n) - 1; // 3柱汉诺塔作为上界
    
    // 检查理论最优点附近的几个值
    for (int i = max(1, k - 2); i <= min(n - 1, k + 2); i++) {
        long long temp = 2 * hanoi4(i) + (1LL << (n - i)) - 1;
        result = min(result, temp);
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    cout << hanoi4(n) << endl;
    
    return 0;
} 