#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;
// 本题是LeetCode55的plus版本

// 题意中说的是保证可以到达终点，存在>=n条路径，需要从中去找跳跃次数最少的
// 另做一个数组times去存放去该点的最少跳跃次数
// 从前往后遍历(局部变量i)cover，对第一个元素能到的地方，去times表里进行判断，如果表里不为0了，肯定是之前更小次数能达到过，就不更新，
//                                                           如果表里为0说明之前更小次数肯定到不了，那就给元素更新成i；
//                         当cover出现>=nums.size-1时说明已经到了终端，则直接返回


// 外层i遍历时，每次都查看cover值有没有变化，如果有变化，则将原cover值到cover这段的下标在times中赋值cnt，如果原先times中有值了，则continue；一次完就cnt++;
int jump(vector<int>& nums)  {
    if (nums.size()==1) return 0;

    vector<int> times(nums.size(),0);   // 创建一个长度为nums.size,且值全为0的数组

    int cover=0;
    int oldCover = 0;
    int cnt = 1;    // 当前第几步了
    for (int i = 0; i <=cover ; ++i) {
        cover = max(cover,nums[i]+i);
        if(cover!=oldCover){
//            int size = nums.size()-1;
//            int maxIndex = max(cover, size);  // vector.size()返回的不是int!是td::size_t（标准库定义的无符号整数类型）
            int maxIndex = min(cover, (int)nums.size()-1);
//            cout << cover <<";"<< (int)nums.size()<<endl;
            for (int j = oldCover; j <= maxIndex; ++j) {
                if(times[j]==0)times[j]=cnt;
            }
            cnt++;  //错在这里 (当通过值上非0的开始再次跳到的时候)，此处每次i往后移一次就加加了是不对的，实际上要一轮区间加完了才++，但是区间怎么去观测做不到
            oldCover = cover;
        }
        if (cover>=nums.size()-1)break; // cover能覆盖整个数组的话就代表可以结束了
    }

    return times[nums.size()-1];
}
int main(){
//    vector<int> nums = {2,1};

    //    vector<int> nums = {0};
//    vector<int> nums = {2,3,1,1,4};
//    vector<int> nums = {2,3,0,1,4};
    vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout << jump(nums);

    return 0;
}