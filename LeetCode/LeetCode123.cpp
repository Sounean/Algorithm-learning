#include "iostream"
#include <vector>
using namespace std;

// 从头往后遍历 每次有更小的就更新进来   找到峰点,也不对 因为可能:[1,10,-1,2]  找到谷点是-1,后面算出来也只有3，最长边出现在非谷点处

// 做成折线图后进行查找
int maxProfit(vector<int>& prices) {
    int maxSum = 0;
    int highValue = 0;
    int lowValue = 0;
    for (int i = 0; i < prices.size() - 1; ++i) {

    }

    return maxSum;
}
int main(){
    vector<int> nums = {7,1,5,3,6,4};
    int max = maxProfit(nums);
    cout << max;

    return 0;
}
