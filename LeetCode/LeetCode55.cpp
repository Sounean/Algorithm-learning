#include "iostream"
#include <vector>
using namespace std;


// 如果默认是从前往后去找的话会出现这么一个情况，不知道什么时候跳到了0然后不能接下来了，除非每次到下个坐标后都进行对里面元素的值进行从1开始的遍历'
// 那每次挑最大的不一定可以成，因为会出现 3500 1,如果一开始选3而不是1就没了，所以说正着来直接找最大值是不行的；
// 那就从后往前去推，记录步数，到达有数值的地方，第一case：中间碰到为0得，肯定也是死元素，就直接跳过(到那个元素上直接动不了了)
//                                      第二case：去判断能不能一步到位，能得话就不修改值，让值始终为正数，continue掉本次；
//                                      第三case：如果上面的case没有continue，那么再接着判断他所能到达的其他元素能不能到终端，即其他元素得值是否是正数，如果有正数，则continue掉，如果全部没有正数，将其设为0；
//
// 遍历完，去获取第一个元素的值，是0则false，是正数则返回true

// 要判断两个，一个是该元素直接可以到的范围；另一个是他可以到达的另外一个元素；如果他直接无法到达终点且可以到达的其他元素也均无法到达，那就是死元素(本题中将死元素设为0)；


// 自己做的时候遗漏的情况：nums = {0}的时候
bool canJump(vector<int>& nums)  {
    if (nums.size()==1) return true;


    bool flag = false;
    for (int i = nums.size()-2; i >=0 ; i--) {  // 此处应该从下标nums.size-2开始，因为最后一个元素是终端，即使是0也代表已经到终端了
        // 第一case
        if(nums[i] == 0)continue;

        // 第二case
        if (nums.size()-1-i <= nums[i])continue;    // 假设是 1 2 0 1,那么此时到元素2时，i为1 则左式值为4-1-1=2 符合

        // 第三case
        bool flag = false;  // true:里面存在非死元素,false:里面全是死元素
        for (int j = nums[i]; j >0 ; j--) {
            if (nums[i+j]!=0){
                flag = true;
                break;
            }
        }
        if (!flag){
            nums[i] = 0;// 如果他能达到的也全是死元素，那他也是死元素
        }
    }

    return nums[0]>0;
}
int main(){
//    vector<int> nums = {2,3,1,1,4};
//    vector<int> nums = {3,2,1,0,4};
    vector<int> nums = {0};
    cout << canJump(nums);

    return 0;
}
