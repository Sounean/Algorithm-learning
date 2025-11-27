#include "iostream"
#include <vector>
using namespace std;


//这题就是从头往后遍历，有更小值就存入，有比他大的就立马卖出  且更新值

// 当前还没买入时，观察票价，只要票价有比当前小的就更新掉，一旦出现比当前保存的要多的，就假装自己在最小值那天已经买了，随即卖出；
// （但因为只能只能卖一次，所以要把票价存为最新的）例如 1,3,5 时，你只能选择1买，3卖；然后3买，5买；不能1买，3卖一次又5卖一次；
// 即降时买，涨时卖


//int maxProfit(vector<int>& prices) {
//    int maxSum =0;
//    int curPrice = prices[0];
//
//    for (int i = 0; i < prices.size(); ++i) {
//        if (prices[i]<curPrice){
//            curPrice = prices[i];
//        } else if(prices[i]>curPrice){
//            maxSum += prices[i]-curPrice;
//            curPrice = prices[i];
//        }
//    }
//    return maxSum;
//}
//int main(){
//    vector<int> nums = {7,6,4,3,1};
//    int max = maxProfit(nums);
//    cout << max;
//
//    return 0;
//}


// 但这题还可以更简单，直接遍历一次，贪心一点，只要是prices[i]-prices[i-1]>0的，就当自己买了
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