#include "iostream"
#include <vector>
using namespace std;

// 分四个方向，左右下上的顺序
// 写到边界或者有值得地方就拐弯，最终结束得标准就是i遍历到i方
int maxProfit(vector<int>& prices) {
    int maxSum = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {
        if (prices[i+1]- prices[i]>0){
            maxSum+=prices[i+1]- prices[i];
        }
    }

    return maxSum;
}
int main(){
    vector<int> nums = {7,1,5,3,6,4};
    int max = maxProfit(nums);
    cout << max;

    return 0;
}