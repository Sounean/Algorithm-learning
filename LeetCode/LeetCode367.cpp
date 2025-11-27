#include "iostream"
#include <vector>
using namespace std;


int wiggleMaxLength(vector<int>& nums) {
    int cnt = 0;    // 相反坡度的数量

    vector<bool> compare;
    for(int i=0;i<nums.size()-1;){
        // 当是平线时，直接略过
        if(nums[i+1]-nums[i]==0){

        } else {
            // 当产生坡度时，观察坡度是否和上一次的相反；相反才记录下来
            if (cnt==0){
                cnt++;
                compare.push_back((nums[i+1]-nums[i])>0);
            } else{
                // 只有后面跟着的趋势是和之前一个是相反的才需要保存进来，且加1
                if(((nums[i+1]-nums[i])>0)!=compare[cnt-1]){
                    cnt++;
                    compare.push_back((nums[i+1]-nums[i])>0);
                }
            }
        }
        i++;
    }

    cnt++;

    return cnt;
}
int main(){
    vector<int> nums = {1,1,1,2,2,2,1,1,1,3,3,3,2,2,2};
    int length = wiggleMaxLength(nums);
    cout << length;

    return 0;
}
