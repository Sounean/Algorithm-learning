#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 * 最优解法：使用STL全排列
 * 时间复杂度：O(9!) = O(362880)，比暴力枚举更高效
 * 空间复杂度：O(1)
 */

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    
    // 初始化1-9的数字序列
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> results; // 存储所有符合条件的结果
    
    // 使用STL的全排列函数遍历所有可能的排列
    do {
        // 构造三个三位数
        int num1 = digits[0] * 100 + digits[1] * 10 + digits[2];
        int num2 = digits[3] * 100 + digits[4] * 10 + digits[5];
        int num3 = digits[6] * 100 + digits[7] * 10 + digits[8];
        
        // 检查比例关系：num1:num2:num3 = A:B:C
        // 即 num1*B = num2*A 且 num1*C = num3*A
        if (num1 * B == num2 * A && num1 * C == num3 * A) {
            results.push_back({num1, num2, num3});
        }
    } while (next_permutation(digits.begin(), digits.end()));
    
    // 按第一个数字升序排序（题目要求）
    sort(results.begin(), results.end());
    
    // 输出结果
    if (results.empty()) {
        cout << "No!!!" << endl;
    } else {
        for (const auto& result : results) {
            cout << result[0] << " " << result[1] << " " << result[2] << endl;
        }
    }
    
    return 0;
}

/*
优化点分析：
1. 使用STL全排列，代码更简洁，逻辑更清晰
2. 避免了复杂的数字拆分和重复检查逻辑
3. 使用vector存储结果，便于排序
4. 比例检查使用乘法而非除法，避免浮点数精度问题
5. 时间复杂度固定为O(9!)，不依赖于输入的A,B,C值

算法思路：
1. 生成1-9的所有排列
2. 将每个排列分成三组，构成三个三位数
3. 检查这三个数是否满足A:B:C的比例关系
4. 收集所有符合条件的结果并排序输出

相比原算法的优势：
- 不需要复杂的边界检查
- 不会出现除零错误
- 自然保证了1-9每个数字只使用一次
- 代码更易理解和维护
*/ 