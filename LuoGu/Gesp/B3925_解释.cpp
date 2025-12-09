#include <iostream>
using namespace std;

/*
 * B3925 小猫分鱼问题 - 详细解释
 * 
 * 问题：为什么最后一只小猫不能拿走1条或2条，而必须是3条？
 * 
 * 关键约束条件：
 * 1. 每只小猫分鱼时，必须能把鱼平均分成 N 份（每份数量相同）
 * 2. 每只小猫拿走一份后，剩下的鱼数必须能让下一只小猫继续分
 * 3. 所有数量都必须是整数
 */

// 验证函数：给定最后一只小猫拿走的鱼数，验证是否可行
bool verify(int N, int i, int lastTake) {
    // 最后一只小猫分鱼前的鱼数
    int fish = N * lastTake + i;
    
    // 从倒数第二只开始，逆推每一只小猫分鱼前的鱼数
    for (int cat = N - 1; cat >= 1; cat--) {
        // 当前这只小猫拿走一份后，剩下的鱼数
        int remaining = fish;
        
        // 当前这只小猫分鱼前的鱼数
        // 设分鱼前有 x 条，分成 N 份，每份 y 条，多 i 条扔掉，拿走一份 y 条
        // 则：x = N*y + i，且 x - y - i = remaining
        // 所以：x = remaining + y + i，且 x = N*y + i
        // 因此：remaining + y + i = N*y + i
        //      remaining = (N-1)*y
        //      y = remaining / (N-1)
        //      x = N*y + i = N*remaining/(N-1) + i
        
        // 检查 remaining 是否能被 (N-1) 整除
        if (remaining % (N - 1) != 0) {
            return false;  // 无法整除，不可行
        }
        
        int take = remaining / (N - 1);  // 当前小猫拿走的鱼数
        fish = N * take + i;  // 当前小猫分鱼前的鱼数
        
        // 检查是否为正整数
        if (fish <= 0 || take <= 0) {
            return false;
        }
    }
    
    return true;  // 所有约束都满足
}

int main() {
    int N = 3, i = 1;
    
    cout << "=== 小猫分鱼问题分析 ===" << endl;
    cout << "N = " << N << " (3只小猫)" << endl;
    cout << "i = " << i << " (每次扔掉1条)" << endl;
    cout << endl;
    
    // 测试最后一只小猫拿走不同数量的鱼
    for (int lastTake = 1; lastTake <= 5; lastTake++) {
        cout << "--- 测试：最后一只小猫拿走 " << lastTake << " 条鱼 ---" << endl;
        
        // 最后一只小猫分鱼前的鱼数
        int fish = N * lastTake + i;
        cout << "最后一只小猫分鱼前有: " << fish << " 条鱼" << endl;
        
        // 检查是否能被 N 整除（最后一只小猫需要分成 N 份）
        if (fish % N != 0) {
            cout << "❌ 失败：无法平均分成 " << N << " 份（" << fish << " % " << N << " != 0）" << endl;
            cout << endl;
            continue;
        }
        
        int each = fish / N;  // 每份的鱼数
        cout << "分成 " << N << " 份，每份 " << each << " 条，多 " << i << " 条扔掉" << endl;
        cout << "拿走1份（" << each << " 条），剩下 " << (fish - each - i) << " 条" << endl;
        
        // 验证整个流程
        if (verify(N, i, lastTake)) {
            cout << "✓ 可行！" << endl;
            
            // 详细展示整个过程
            cout << "\n详细过程（从后往前）：" << endl;
            fish = N * lastTake + i;
            for (int cat = N; cat >= 1; cat--) {
                int take = (cat == N) ? lastTake : (fish - i) / N;
                cout << "第" << cat << "只小猫：分鱼前有 " << fish << " 条，";
                cout << "分成" << N << "份每份" << take << "条，扔掉" << i << "条，";
                cout << "拿走" << take << "条，剩下 " << (fish - take - i) << " 条" << endl;
                fish = N * take + i;  // 上一只小猫分鱼前的鱼数
            }
        } else {
            cout << "❌ 不可行：逆推过程中出现无法整除的情况" << endl;
        }
        cout << endl;
    }
    
    cout << "\n=== 结论 ===" << endl;
    cout << "最后一只小猫必须拿走 3 条鱼，因为：" << endl;
    cout << "1. 拿走 1 条：分鱼前有 4 条，无法平均分成 3 份（4 % 3 != 0）" << endl;
    cout << "2. 拿走 2 条：分鱼前有 7 条，无法平均分成 3 份（7 % 3 != 0）" << endl;
    cout << "3. 拿走 3 条：分鱼前有 10 条，可以分成 3 份，且逆推过程全部满足整数约束" << endl;
    
    return 0;
}



