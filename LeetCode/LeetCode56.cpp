#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;

// 这题应该创建新数组v<v<int>> newV，然后添加元素比删除简单
//将所有的元素按照左侧值从小到大去排序一次,然后从左往右遍历，int left为第一个元素的左侧值，int r为右侧值，然后往后遍历，如果右侧的线段左侧值<=r，则r = max(新线段的右值,r)
//                                                                                                              左侧值>r,则{left,r}作为新元素插入newV，且将left更新为下一个元素的左值，r更新为下一个元素的右值

static bool  cmp(vector<int> i1,vector<int> i2){
    return i1[0]<i2[0];
}

vector<vector<int>> merge(vector<vector<int>>& intervals)  {

    if (intervals.size() == 1){
        return intervals;
    }

    sort(intervals.begin(),intervals.end(),cmp);

    vector<vector<int>> newV = {};
    int left = intervals[0][0];
    int right = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0]<=right){
            right = max(intervals[i][1] , right);
        }else{
            newV.push_back({left,right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    newV.push_back({left,right});


    return newV;

}
int main(){
    vector<vector<int> > nums = {{1,3},{2,6},{8,10},{15,18}};
//    vector<vector<int> > nums = {{1,4},{4,5}};
    vector<vector<int>> m1 = merge(nums);
    for (int i = 0; i < m1.size(); ++i) {
        cout << m1[i][0] << "-" << m1[i][1]<<"  ";
    }
    return 0;
}