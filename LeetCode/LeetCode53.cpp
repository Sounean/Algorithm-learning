#include "iostream"
#include <vector>
using namespace std;


int maxSubArray(vector<int>& nums) {
    // 按最大值进行范围波动？不太合理，可能会出现最大值附近又比较大的最小值，一下子打下去了。

    // 现在矛盾的点是不知道这个最长子数组是从哪开始的，都没有一个开始的点。 都不知道咋遍历

    // 认输

    // 贪心应该贪在需要本次对后一次的贡献应该是大于0的，如果一旦出现加上之后会小于0，则直接放弃掉会小于0的那一段，从新开始找，
    // 即如果当前是负贡献，则不让加进后面的判断中，如[-1,1,3];直接放弃-1,而是从1开始去尝试构件最大子数组
    // 并且每次都记录下来当前的最大值result，一直去更新



    //从左开始遍历，逐渐和后一个数进行相加 每次相加都和记录的最大值进行比较
    // 如果出现负贡献，则直接从下一个元素开始重新计算

    int result = nums[0]; // 代表当前是最小值，等待后面开始更新进来

    int curSum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        curSum+=nums[i];    // 和当前的进行相加
        if (curSum>result)result = curSum;

        if (curSum<0){
            curSum = 0; // 出现负贡献，需要从后面一个开始重新相加
        }
    }

    return result;

}
int main(){
    vector<int> nums = {1};
    int max = maxSubArray(nums);
    cout << max;

    return 0;
}
