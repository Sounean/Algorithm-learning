#include <iostream>
#include <vector>
using namespace std;

// 正确的逆推函数
int correctSolution(int N, int i) {
    // 从最后一只小猫拿走的最少数量开始尝试
    for (int lastTake = 1; ; lastTake++) {
        // 最后一只小猫分鱼前的鱼数
        int fish = N * lastTake + i;
        
        bool valid = true;
        int currentTake = lastTake;
        
        // 从倒数第二只开始逆推
        for (int cat = N - 1; cat >= 1; cat--) {
            // 当前小猫拿走 currentTake 条后，剩下的鱼数
            // 当前小猫分鱼前有 fish 条，分成 N 份，每份 currentTake 条，多 i 条扔掉
            // 拿走 1 份（currentTake 条），剩下：fish - currentTake - i 条
            int remaining = fish - currentTake - i;
            
            // 上一只小猫拿走一份后，剩下 remaining 条给当前小猫
            // 设上一只小猫拿走 m 条，则它分鱼前有 N*m + i 条
            // 拿走 1 份（m 条）后，剩下：N*m + i - m - i = (N-1)*m 条
            // 所以：(N-1)*m = remaining
            // 因此：m = remaining / (N-1)
            
            // 检查是否能整除
            if (remaining % (N - 1) != 0) {
                valid = false;
                break;
            }
            
            currentTake = remaining / (N - 1);
            
            // 更新 fish 为上一只小猫分鱼前的鱼数
            fish = N * currentTake + i;
        }
        
        if (valid) {
            return fish;
        }
    }
}

// 用户代码的逻辑（有bug的版本）
int userSolution(int N, int i) {
    int num = 1;
    while (true) {
        int TempNum = num;
        int j = N;
        for (; j >= 1; j--) {
            // 问题1: 硬编码了 *3+1，只适用于 N=3
            // 问题2: 硬编码了 /2，只适用于 N=3
            if ((TempNum * 3 + 1) % 2 == 0) {
                TempNum = (TempNum * 3 + 1) / 2;
            } else {
                break;
            }
        }
        if (j == 1) {
            return TempNum * 3 + 1;  // 问题3: 这里也硬编码了
        }
        num++;
    }
}

int main() {
    cout << "=== 测试用例对比 ===" << endl;
    cout << "格式: N i | 正确答案 | 用户代码输出 | 是否WA" << endl;
    cout << "----------------------------------------" << endl;
    
    // 测试多个用例
    vector<pair<int, int>> testCases = {
        {3, 1},   // 样例
        {3, 2},   // 不同的 i
        {4, 1},   // 不同的 N
        {4, 2},
        {5, 1},
        {2, 1},   // N=2
        {2, 2},
    };
    
    for (auto& test : testCases) {
        int N = test.first;
        int i = test.second;
        
        int correct = correctSolution(N, i);
        int user = userSolution(N, i);
        
        cout << N << " " << i << " | " << correct << " | " << user;
        if (correct != user) {
            cout << " | ❌ WA";
        } else {
            cout << " | ✓ AC";
        }
        cout << endl;
    }
    
    cout << "\n=== 问题分析 ===" << endl;
    cout << "1. 代码硬编码了 N=3：使用了 *3+1 和 /2，只适用于 N=3, i=1" << endl;
    cout << "2. 正确的逆推公式应该是：m = (N*k + i) / (N-1)" << endl;
    cout << "   其中 k 是当前小猫拿走的，m 是上一只小猫拿走的" << endl;
    cout << "3. 代码中应该使用变量 N 和 i，而不是硬编码的 3 和 1" << endl;
    
    return 0;
}

