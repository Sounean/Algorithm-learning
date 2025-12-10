#include <iostream>
#include <ctime>
using namespace std;

// 你的原始代码（会TLE）
int yourSolution(int N, int i) {
    int sum = 1;
    int iterations = 0;
    while (true) {
        iterations++;
        int tempSum = sum;
        int j = N;
        for (; j >= 1; j--) {
            if (tempSum % N != i) {
                break;
            }
            if ((tempSum - i) % N != 0) {
                break;
            }
            tempSum = ((tempSum - i) / N) * (N - 1);
            if (tempSum <= 0) break;
        }
        if (j == 0) {
            cout << "迭代次数: " << iterations << endl;
            return sum;
        }
        sum++;
    }
}

// 优化版本：从最后一只小猫逆推
int optimizedSolution(int N, int i) {
    // 从最后一只小猫拿走的最少数量开始尝试
    for (int lastTake = 1; ; lastTake++) {
        int fish = N * lastTake + i;  // 最后一只小猫分鱼前的鱼数
        bool valid = true;
        int currentTake = lastTake;
        
        // 从倒数第二只开始逆推
        for (int cat = N - 1; cat >= 1; cat--) {
            // 当前小猫拿走 currentTake 条后，剩下的鱼数
            int remaining = fish - currentTake - i;
            
            // 上一只小猫拿走一份后，剩下 remaining 条
            // 设上一只小猫拿走 m 条，则：(N-1)*m = remaining
            if (remaining % (N - 1) != 0) {
                valid = false;
                break;
            }
            
            currentTake = remaining / (N - 1);
            fish = N * currentTake + i;
        }
        
        if (valid) {
            return fish;
        }
    }
}

int main() {
    cout << "=== TLE 问题分析 ===" << endl << endl;
    
    // 测试用例1：N=3, i=1
    int N1 = 3, i1 = 1;
    cout << "测试用例1: N=" << N1 << ", i=" << i1 << endl;
    
    clock_t start = clock();
    int result1_opt = optimizedSolution(N1, i1);
    clock_t end = clock();
    cout << "优化版本答案: " << result1_opt << ", 耗时: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    start = clock();
    int result1_your = yourSolution(N1, i1);
    end = clock();
    cout << "你的版本答案: " << result1_your << ", 耗时: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    cout << endl;
    
    // 测试用例2：N=4, i=1（可能答案更大）
    int N2 = 4, i2 = 1;
    cout << "测试用例2: N=" << N2 << ", i=" << i2 << endl;
    
    start = clock();
    int result2_opt = optimizedSolution(N2, i2);
    end = clock();
    cout << "优化版本答案: " << result2_opt << ", 耗时: " << (double)(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    
    cout << "\n=== 问题分析 ===" << endl;
    cout << "你的代码问题：" << endl;
    cout << "1. 从 sum=1 开始逐个枚举，如果答案是 10000，就要尝试 10000 次" << endl;
    cout << "2. 每次尝试都要检查 N 只小猫，时间复杂度 O(sum * N)" << endl;
    cout << "3. 当答案很大时（比如几万、几十万），会严重超时" << endl;
    cout << endl;
    cout << "优化思路：" << endl;
    cout << "1. 从最后一只小猫拿走的最少数量开始尝试（从1开始）" << endl;
    cout << "2. 逆推到第一只小猫，时间复杂度 O(lastTake * N)" << endl;
    cout << "3. 通常 lastTake 不会太大（几十到几百），比 sum 小得多" << endl;
    cout << endl;
    cout << "例如 N=3, i=1：" << endl;
    cout << "  你的方法：需要尝试到 sum=25，尝试 25 次" << endl;
    cout << "  优化方法：最后一只拿走 3 条，只需要尝试 3 次" << endl;
    
    return 0;
}




