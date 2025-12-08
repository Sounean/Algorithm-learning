#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;


// 不能只考虑横着，还得考虑竖着  横着分析不行，因为竖着也会影响  实际上就是两数索引之差*max(两个数)

// （j-i）*(max(a[j],a[i])),现在问题来了，肯定不是把所有可能性都列一遍

// 双指针i,j 要移动时，移动min(i,j)的，因为双方各移动一位，距离还是一样，那怎么移动？
// 官方解是每次min(i,j)向内移动，但是较小值向内移动就肯定对呢？会不会较大值向内移动反而产生更大值？  有解，可看图LeetCode11
class Solution {
public:
    int maxArea(vector<int>& height) {
        int sumMax = 0;
        int l = 0;
        int r = height.size()-1;
        while (l!=r){
            sumMax = max(sumMax,min(height[l],height[r])*abs(l-r));
            if (height[l]>=height[r]){
                r--;
            }else{
                l++;
            }
        }

        return sumMax;
    }
};

int main(){
    Solution sol;
    vector<int> v1 = {1,1};
//    vector<int> v1 = {1,8,6,2,5,4,8,3,7};   // 49
    cout << sol.maxArea(v1);

    return 0;
}


