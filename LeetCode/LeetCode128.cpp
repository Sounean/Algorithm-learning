#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "set"
#include "unordered_set"
using namespace std;

// 因为如果用数组的话即使给排序了，其实还得考虑出现012222345  最长长度为012345，中间2地跳过的问题，那么set刚好符合1.不重复，2.排序，就用set就行

// 排序的时间长度是O(nlog)
int arr[150000];
//int longestConsecutive(vector<int>& nums) {
//    set<int> s1;
//    for (int i = 0; i < nums.size(); ++i) {
//        s1.insert(nums[i]);
//    }
//
//    if(s1.size()==0)return 0;
//    if(s1.size()==1)return 1;
//
//    int maxLen = 0; // 假设最长的长度为0
//    int index = 0;
//    for(const auto& s:s1){
//        arr[index++] = s;
//    }
//    int preIndex = 0;
//    int lastInex = 0;
//    int tempLen = 0;
//    while (1){
//        if (lastInex==s1.size()){
//            maxLen = max(maxLen,tempLen);
//            break;
//        }
//        if ((arr[lastInex] - arr[preIndex]) == (lastInex-preIndex)){    // 如果两指针规格内的符合的话就一直加加
//            tempLen++;
//            lastInex++;
//        }else{
//            maxLen = max(maxLen,tempLen);
//            tempLen = 0;
//            preIndex = lastInex;
//        }
//    }
//
//
//    return maxLen;
//}

// 尝试寻找可以作为序列起点的(不是序列起点的直接跳过！)
//  如果符合是序列起点，那么往后去找最长的连续集合
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end()); // 把 nums 转成哈希集合
    int ans = 0;
    for (int x : st) { // 遍历哈希集合
        if (st.count(x - 1)>0) { // 如果 x 不是序列的起点，直接跳过  (这步太牛了，我们繁琐的计算其实是需要给每个值都查看是否有连续的，他这一步本质上是判断一个长数组，该值是否为开头的，如果不是开头的，直接跳过下面全部步骤了)
            continue;
        }
        // x 是序列的起点
        int y = x + 1;
        while (st.count(y)>0) { // 不断查找下一个数是否在哈希集合中
            y++;
        }
        // 循环结束后，y-1 是最后一个在哈希集合中的数
        ans = max(ans, y - x); // 从 x 到 y-1 一共 y-x 个数
    }
    return ans;
}


int main(){
//    vector<int> n1 = {9,1,4,7,3,-1,0,5,8,-1,6}; // 3 4 5 6 7 8 9
//    vector<int> n1 = {};
//    vector<int> n1 = {100,4,200,1,3,2}; // 4
    vector<int> n1 = {0,3,7,2,5,8,4,6,0,1}; // 9
//    vector<int> n1 = {1,0,1,2};
    cout << longestConsecutive(n1);
    return 0;
}


