#include <iostream>
using namespace std;

// 你的代码逻辑
int yourSolution(int N, int i) {
    int sum = 1;
    while (true) {
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
        }
        if (j == 1) {  // 注意：这里应该是 j == 0，不是 j == 1
            return sum;
        }
        sum++;
    }
}

// 正确的解法（从最后一只小猫逆推）
int correctSolution(int N, int i) {
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

// 正向验证函数：给定总鱼数，验证是否满足所有小猫的要求
bool verify(int N, int i, int totalFish) {
    int fish = totalFish;
    
    for (int cat = 1; cat <= N; cat++) {
        // 检查是否能分成 N 份，余 i 条
        if (fish % N != i) {
            return false;
        }
        
        // 每份的鱼数
        int each = (fish - i) / N;
        
        // 拿走一份后，剩下的鱼数
        fish = fish - each - i;
    }
    
    return true;
}

int main() {
    cout << "=== 代码问题分析 ===" << endl << endl;
    
    // 测试用例：N=3, i=1
    int N = 3, i = 1;
    
    cout << "测试用例：N=" << N << ", i=" << i << endl;
    int correct = correctSolution(N, i);
    int yours = yourSolution(N, i);
    
    cout << "正确答案: " << correct << endl;
    cout << "你的输出: " << yours << endl;
    cout << "验证你的答案: " << (verify(N, i, yours) ? "✓ 正确" : "✗ 错误") << endl;
    cout << endl;
    
    cout << "=== 问题1：循环条件错误 ===" << endl;
    cout << "你的代码：if (j == 1)" << endl;
    cout << "问题：当 j == 1 时，说明第 N 只小猫（最后一只）还没处理完就 break 了" << endl;
    cout << "正确应该是：if (j == 0)，表示所有 N 只小猫都处理完了" << endl;
    cout << endl;
    
    cout << "=== 问题2：剩余鱼数计算公式错误 ===" << endl;
    cout << "你的代码：tempSum = ((tempSum-i)/N) * (N-1)" << endl;
    cout << "问题分析：" << endl;
    cout << "  当前小猫分鱼前有 tempSum 条" << endl;
    cout << "  分成 N 份，每份 (tempSum-i)/N 条，多 i 条扔掉" << endl;
    cout << "  拿走 1 份，即拿走 (tempSum-i)/N 条" << endl;
    cout << "  剩下 = tempSum - (tempSum-i)/N - i" << endl;
    cout << "      = tempSum - (tempSum-i)/N - i" << endl;
    cout << "      = (tempSum-i) - (tempSum-i)/N" << endl;
    cout << "      = (tempSum-i) * (1 - 1/N)" << endl;
    cout << "      = (tempSum-i) * (N-1)/N" << endl;
    cout << "  但你的代码写的是：((tempSum-i)/N) * (N-1)" << endl;
    cout << "  这两个公式不一样！" << endl;
    cout << "  例如：tempSum=10, N=3, i=1" << endl;
    cout << "    正确：((10-1)/3) * (3-1)/3 = 3 * 2/3 = 2（但这是分数，不对）" << endl;
    cout << "    重新算：10 - 3 - 1 = 6（剩下6条）" << endl;
    cout << "    你的公式：((10-1)/3) * (3-1) = 3 * 2 = 6 ✓" << endl;
    cout << "  等等，让我再算一次..." << endl;
    cout << endl;
    
    // 手动验证
    cout << "手动验证（N=3, i=1, tempSum=25）：" << endl;
    int tempSum = 25;
    cout << "第1只小猫：分鱼前 " << tempSum << " 条" << endl;
    cout << "  25 % 3 = " << (tempSum % 3) << " (应该是1) " << (tempSum % 3 == 1 ? "✓" : "✗") << endl;
    int each1 = (tempSum - 1) / 3;
    cout << "  每份 " << each1 << " 条，拿走1份，扔掉1条" << endl;
    tempSum = tempSum - each1 - 1;
    cout << "  剩下 " << tempSum << " 条" << endl;
    cout << "  用你的公式：((25-1)/3) * (3-1) = " << ((25-1)/3) * (3-1) << " 条" << endl;
    cout << "  实际剩下：25 - 8 - 1 = " << (25 - 8 - 1) << " 条" << endl;
    cout << "  你的公式结果：" << (((25-1)/3) * (3-1)) << " ✓" << endl;
    cout << endl;
    
    cout << "第2只小猫：分鱼前 " << tempSum << " 条" << endl;
    cout << "  16 % 3 = " << (tempSum % 3) << " (应该是1) " << (tempSum % 3 == 1 ? "✓" : "✗") << endl;
    int each2 = (tempSum - 1) / 3;
    cout << "  每份 " << each2 << " 条，拿走1份，扔掉1条" << endl;
    tempSum = tempSum - each2 - 1;
    cout << "  剩下 " << tempSum << " 条" << endl;
    cout << "  用你的公式：((16-1)/3) * (3-1) = " << (((16-1)/3) * (3-1)) << " 条" << endl;
    cout << "  实际剩下：16 - 5 - 1 = " << (16 - 5 - 1) << " 条" << endl;
    cout << "  你的公式结果：" << (((16-1)/3) * (3-1)) << " ✓" << endl;
    cout << endl;
    
    cout << "第3只小猫：分鱼前 " << tempSum << " 条" << endl;
    cout << "  10 % 3 = " << (tempSum % 3) << " (应该是1) " << (tempSum % 3 == 1 ? "✓" : "✗") << endl;
    int each3 = (tempSum - 1) / 3;
    cout << "  每份 " << each3 << " 条，拿走1份，扔掉1条" << endl;
    tempSum = tempSum - each3 - 1;
    cout << "  剩下 " << tempSum << " 条" << endl;
    cout << endl;
    
    cout << "=== 结论 ===" << endl;
    cout << "公式 ((tempSum-i)/N) * (N-1) 实际上是正确的！" << endl;
    cout << "因为：tempSum - each - i = tempSum - (tempSum-i)/N - i" << endl;
    cout << "     = (tempSum-i) - (tempSum-i)/N" << endl;
    cout << "     = (tempSum-i) * (1 - 1/N)" << endl;
    cout << "     = (tempSum-i) * (N-1)/N" << endl;
    cout << "但注意：(tempSum-i)/N 必须是整数（前面已经检查过了）" << endl;
    cout << "所以：(tempSum-i) * (N-1)/N = ((tempSum-i)/N) * (N-1) ✓" << endl;
    cout << endl;
    cout << "主要问题：循环条件应该是 j == 0，不是 j == 1！" << endl;
    
    return 0;
}

