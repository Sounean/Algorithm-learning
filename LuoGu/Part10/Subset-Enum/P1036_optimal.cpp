#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, k;
vector<int> nums;
int result = 0;

/**
 * 高效的素数判断函数
 * @param num 待判断的数
 * @return true表示是素数，false表示不是素数
 */
bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;  // 偶数直接排除
    
    // 只需要检查到sqrt(num)，且只检查奇数
    int limit = sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

/**
 * 深度优先搜索选择k个数
 * @param index 当前考虑的数字索引
 * @param selected 已选择的数字个数
 * @param sum 当前选择数字的和
 */
void dfs(int index, int selected, int sum) {
    // 剪枝：如果剩余数字不够选择，直接返回
    if (selected + (n - index) < k) {
        return;
    }
    
    // 递归终止条件：已选择k个数
    if (selected == k) {
        if (isPrime(sum)) {
            result++;
        }
        return;
    }
    
    // 递归终止条件：已遍历完所有数字
    if (index >= n) {
        return;
    }
    
    // 选择当前数字
    dfs(index + 1, selected + 1, sum + nums[index]);
    
    // 不选择当前数字
    dfs(index + 1, selected, sum);
}

int main() {
    // 优化输入输出
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    nums.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // 从第0个数开始，已选择0个数，当前和为0
    dfs(0, 0, 0);
    
    cout << result << endl;
    
    return 0;
} 