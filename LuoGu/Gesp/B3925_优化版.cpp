#include <iostream>
using namespace std;

/*
 * B3925 小猫分鱼 - 优化版本（避免TLE）
 * 
 * 优化思路：从最后一只小猫开始逆推，而不是枚举总鱼数
 * 
 * 原方法问题：
 * - 从 sum=1 开始逐个枚举总鱼数
 * - 如果答案是 10000，就要尝试 10000 次
 * - 时间复杂度 O(答案大小 × N)，当答案很大时会TLE
 * 
 * 新方法优势：
 * - 从最后一只小猫拿走的最少数量开始尝试（从1开始）
 * - 逆推到第一只小猫，时间复杂度 O(最后一只拿走数量 × N)
 * - 通常最后一只拿走的数量不会太大（几十到几百），比总鱼数小得多
 * 
 * 例如 N=3, i=1：
 * - 最后一只拿走 3 条就能满足
 * - 只需要尝试 3 次，每次检查 3 只小猫
 * - 即使答案是 25000，最后一只也只需要拿走几十条，尝试次数远少于 25000
 */

int main() {
    int N, i;
    cin >> N >> i;
    
    // 从最后一只小猫拿走的最少数量开始尝试
    for (int lastTake = 1; ; lastTake++) {
        // 最后一只小猫分鱼前的鱼数
        // 如果最后一只拿走 lastTake 条，那么它分鱼前必须有 N*lastTake + i 条
        int fish = N * lastTake + i;
        bool valid = true;
        int currentTake = lastTake;
        
        // 从倒数第二只开始逆推到第一只
        for (int cat = N - 1; cat >= 1; cat--) {
            // 当前小猫拿走 currentTake 条后，剩下的鱼数
            // 当前小猫分鱼前有 fish 条，分成 N 份，每份 currentTake 条，多 i 条扔掉
            // 拿走 1 份（currentTake 条），剩下：fish - currentTake - i 条
            int remaining = fish - currentTake - i;
            
            // 上一只小猫拿走一份后，剩下 remaining 条给当前小猫
            // 设上一只小猫拿走 m 条，则它分鱼前有 N*m + i 条
            // 拿走 1 份（m 条）后，剩下：N*m + i - m - i = (N-1)*m 条
            // 所以：(N-1)*m = remaining，即 m = remaining / (N-1)
            
            // 检查是否能整除
            if (remaining % (N - 1) != 0) {
                valid = false;
                break;
            }
            
            // 计算上一只小猫拿走的数量
            currentTake = remaining / (N - 1);
            
            // 更新 fish 为上一只小猫分鱼前的鱼数
            fish = N * currentTake + i;
        }
        
        // 如果所有小猫都满足条件，输出答案
        if (valid) {
            cout << fish;
            return 0;
        }
    }
    
    return 0;
}


