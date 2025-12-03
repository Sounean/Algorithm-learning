#include "iostream"
#include <vector>
#include "algorithm"
#include "cmath"
using namespace std;

// 排序nums数组，如果有负数的，优先从左往右将负数转成整数；
// 若还有多，只针对绝对值最小的进行连续的变换

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());

    int fuNum =0;   // 负数的个数
    for(int i=0;i<nums.size();i++){
        if (nums[i]<0){
            fuNum++;
        } else{
            break;
        }
    }

    int maxSum =0;
    // 当k<fuNum时：
    if(k<fuNum){
        for (int i = 0; i < nums.size(); ++i) {
            if(i<=fuNum){
                maxSum+= (-1*nums[i]);
            } else{
                maxSum+=nums[i];
            }
        }
    } else{
    // 当k>fuNum时，就出现1.先将负数部分都变成正，然后将剩下的*-1的次数叠加到，绝对值最小的那个值上面
        // 当原数组内的负数数量，小于k时 那么就去找，最终负数消失的那个值和前一个负数，谁绝对值更小
        int moreControl = 0;
        if (abs(nums[fuNum]) < abs(nums[fuNum-1])){
            moreControl = fuNum;
        }else{
            moreControl = fuNum-1;
        }
        for (int i=0;i<nums.size();++i) {
            if (i<=fuNum){
                if(i!=moreControl){
                    maxSum+= (-1*nums[i]);
                }else{
                    maxSum += pow(-1,k-fuNum)*nums[moreControl];    // 这里的疑惑是pow的第二个参数是k-fuNum还是k-fuNum+1?
                }
            }else{
                maxSum+=nums[i];
            }
        }
    }

    return maxSum;



    // 当k>=fuNum时：
    // 从刚开始不符合负数条件的和前一个  两者查看谁绝对值更小，就对其进行操作。

    

}
int main(){
    vector<int> nums = {2,-3,-1,5,-4};  // -4 -3 -1 2 5  --》 4 3 -1 2 5
    int k = 2;
    int max = largestSumAfterKNegations(nums,k);
    cout << max;

    return 0;
}
