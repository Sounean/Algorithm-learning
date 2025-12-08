#include <iostream>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

// 唯一一点思路是必须有一个正数、负数   ————》 可以先对数据进行排序负数、0、正数
// 负数0个时候，得全部为0
// 负数1个的时候，要么一个0，一个正；要么两个正，  --》 从0往后遍历，如果出现和已经大于负数和了，那么break  ---》需要知道下标为0的索引i0，从i0一直到nums.size()-1
// 负数2个的时候，必须要一个正，且这个正数遍历的条件是当大于负数和时直接break  --》 从0遍历到0的下标双指针

//当数组第一个元素为正或者最后一个元素为负的时候直接return
// 锁定第一个元素i，然后双指针，一个l指向i的后一位，一个指向该数组最后一个
// 当i+l+r<0时，此时i固定，且r已经为最大了，那么就需要将l变大，则l++(应该是一直+到和下标l值不同时)
// 当i+l+r==0时，添加进最终要返回的数组中去；l++,r--  （一直计算到和下标r值不同时）
//   当l>=r时break，i++，i移动到>0时return

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> vOut;

    sort(nums.begin(),nums.end());

    // Check if array is too small
    if(nums.size() < 3) return vOut;
    
    if(nums[0]>0 || nums[nums.size()-1]<0)return vOut;  // 直接不存在

    int i = 0;
    while(i < nums.size() - 2) {  // i needs at least 2 more elements (l and r)
        int l = i + 1;
        int r = nums.size() - 1;
        
        while(l < r) {
            int s = nums[i] + nums[l] + nums[r];
            if (s < 0){
                l++;
                // Skip duplicates for l
                while (l < r && nums[l] == nums[l-1]) {
                    l++;
                }
            } else if(s == 0){
                vector<int>v1 = {nums[i], nums[l], nums[r]};
                vOut.push_back(v1);
                l++;
                r--;
                // Skip duplicates for l
                while (l < r && nums[l] == nums[l-1]) {
                    l++;
                }
                // Skip duplicates for r
                while (l < r && nums[r] == nums[r+1]) {
                    r--;
                }
            } else {
                r--;
                // Skip duplicates for r
                while (l < r && nums[r] == nums[r+1]) {
                    r--;
                }
            }
        }
        
        // Move i to next unique value
        i++;
        while (i < nums.size() - 2 && nums[i] == nums[i-1]) {
            i++;
        }
        
        // If current i is positive, no need to continue
        if (i < nums.size() && nums[i] > 0) break;
    }
    
    return vOut;
}

int main(){
//    vector<int> nums = {-1,0,1,2,-1,-4};    // 2
//    vector<int> nums = {0,1,1};    // 0

    vector<int> nums = {0,0,0};    // 0

    vector<vector<int>> v2 = threeSum(nums);

    for (int i = 0; i < v2.size(); ++i) {
        cout << "[";
        for (int j = 0; j < v2[i].size(); ++j) {
            cout << v2[i][j]<<",";
        }
        cout << "],";
    }
    return 0;
}


