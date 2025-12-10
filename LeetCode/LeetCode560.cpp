#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;

// 现在的问题 i是有可能有负数的,就是说下方逻辑不成立，下方成立的前提是，l向右得话，sum会单向减少，r向右是单向增大，以此来逼近k  但是现在l和r移动时curSum指不定增大减小，就是说规律无效了，必须全部可能都列一遍
// 一个和去统计当前的字串数字之和 curSUm,l表示字串开头在原nums中的下标，r同理
// 当curSum <k的时候，r++,curSum+=nums[r]
// 当curSum == k的时候，curSUm-nums[l-1],l++，r++,curSum+=nums[r],
// 当curSum>k的时候 curSum-nums[l],l++

//结束条件：当r指向最后一个元素，且curSum<=k，实际上后面
int subarraySum(vector<int>& nums, int k) {

}

int main(){

    vector<int> v1 = {1,1,1};
    vector<int> v2 = {1,2,3};

    cout << subarraySum(v1,2)<<endl;
    cout << subarraySum(v2,3);


    return 0;
}


