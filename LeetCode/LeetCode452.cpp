#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;


// 优先射有交接的，或者说，最优解中肯定是有往交接处射出的
// 现在问题来了，如何找出交接处？可以对重复数组进行++ 然后找出其中的最大值，找到后，cnt次数+1，然后将遍历原先的queue，其中会被射中的，直接减去该元素，且在次数数组中--该元素的范围；
// 直到最大值为0

// 如果[a1,b1],[a2,b2]存在交点的话：假设他们大小值根据a从小到大排序了，要有交点需要：a2<=b1即可

// 先排序所有的，按照a从小到大排序，然后当a2<=b1则表示一起干掉，在其中给他去掉； 结束判断是否还有，还有的就接着来    这个思路不对，因为[1,5][1,2][4,5]也会被一次性就去掉，实际上不是

// 将数组根据第一个元素进行从小到大排序
static bool cmp(vector<int> p1,vector<int> p2){
    if (p1[0]<=p2[0])return true;
    return false;
}

int findMinArrowShots(vector<vector<int>>& points) {
    int cnt = 0;
    while (points.size()!=0){
        sort(points.begin(),points.end(),cmp);
        vector<int> tempPoint = points[0];
        points.erase(remove_if(points.begin(),points.end(),
                               [cnt,tempPoint](vector<int> p){
            if (p[0]<=tempPoint[1] ) {  // 第一个的右侧要大于其他用来的比较的左侧
                return true;
            }else{
                return false;
            }
        }),points.end());
        cout<<"-------"<<endl;
        cnt++;
    }
    return cnt;
}

int main(){

    vector<vector<int>> queue = {{1,2},{1,5},{4,5}};
//    vector<vector<int>> queue = {{1,2},{3,4},{2,3},{4,5}};
//    vector<vector<int>> queue = {{1,2},{3,4},{5,6},{7,8}};
//    vector<vector<int>> queue = {{10,16},{2,8},{1,6},{7,12}};
    int queue1 = findMinArrowShots(queue);

    cout << queue1;

    return 0;
}