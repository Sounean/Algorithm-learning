#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;


//根据线段左侧值从小到大排序(i)，然后从前往后找，出现pj[0]<pj[1]的情况（如图LeetCode435的圈1和2）则表示需要删除一个掉，删除那个右侧值更大的 记录下来新的右侧值，然后往后找
// 如果出现pj[0]>=pi[1],也更掉新的右侧值 （如图圈3）

// 将数组根据第一个元素进行从小到大排序
static bool cmp(vector<int> p1,vector<int> p2){
    return p1[0] < p2[0];
}

int eraseOverlapIntervals(vector<vector<int>>& points) {

    sort(points.begin(),points.end(), cmp);

    int cnt = 0;
    int right = points[0][1];
    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0]<right){
            cnt++;
            right = min(points[i][1] , right);
        }else {
            right = points[i][1];
        }
    }


    return cnt;
}

int main(){



//    vector<vector<int>> queue = {{1,2},{1,2},{1,2}};
    vector<vector<int>> queue = {{1,2},{3,4},{2,3},{1,3}};
//    vector<vector<int>> queue = {{1,2},{2,3}};
    int queue1 = eraseOverlapIntervals(queue);

    cout << queue1;

    return 0;
}