#include "iostream"
#include <vector>
using namespace std;


// 用每次能覆盖的最大值cover来判断，然后依次往后遍历逼近cover的值大小，每次都去更新能覆盖的cover值，如果某次cover能给终端覆盖了，那就直接return true
// 遍历完了也没走到上面的retur true，那就直接走return false


bool canJump(vector<int>& nums)  {
    if (nums.size()==1) return true;

    int cover=0;
    for (int i = 0; i <=cover ; ++i) {  // 这里用=cover，因为以1/0 3/1 2/2 1/3 1/4 为例，第二个站3/1上，最终能到的时1/4,用<得话表达式只能到3就不符合实际情况了
        cover = max(cover,nums[i]+i);
        if (cover>=nums.size()-1)return true;
    }

    return false;
}
int main(){
//    vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {3,2,1,0,4};
//    vector<int> nums = {0};
    cout << canJump(nums);

    return 0;
}