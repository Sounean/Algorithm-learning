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
// -------上述想法不对--------- 问题出在：策略是一次射最多重叠次数的区域是知道的，但是按照数值去对一个次数数组维护的话，数值太大了，这个有点不合理，想想会超时复吧？
//------->解决方案为，上述的思想是因为需要多次对次数数组遍历！在算出第一次次数数组之后，遍历完一次找到最大值的下标，然后再遍历原数组找到左右区间会包含最大值下标的进行删除，然后再排序再找！
//把该思路改成将所有数组按照左侧值从小打到排序，然后从左往右遍历一次即可！因为需要所有气球都射爆，所以只需要找到如图(LeetCode452_01.png)的气球的有边界往左最多能射爆几个
// 具体思考后，实践作图时，可将射的情况分成（LeetCode452_02）3种，其实不难看出，按上述大小排序和射发后，不会出现排序为A,B,C,射了AC而没把B射爆的情况（找不出反例）
// 所以思路为：1.先按"气球左侧值，从小到大排序"sort，2.遍历气球数组，每次记录前方气球的右侧最小值，当出现气球的左侧值比之前最小气球右侧值更大了，说明开始
// 产生无法重合的地方了，但是之前的又必须得射爆，所以前方必须要花费1次射得次数，且是局部最优解了(一次射最多),cnt++
//但上述思想 vector<vector<int>> queue = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};又没法满足

// 将数组根据第一个元素进行从小到大排序
static bool cmp(vector<int> p1,vector<int> p2){
    return p1[0] < p2[0];
}

int findMinArrowShots(vector<vector<int>>& points) {

    sort(points.begin(),points.end(), cmp);
    int cnt = 0;
    int minBallRight = points[0][1];
    for(int ballonIndex=0;ballonIndex<points.size();ballonIndex++){
        minBallRight = min(minBallRight,points[ballonIndex][1]);
        if (points[ballonIndex][0]>minBallRight){
            cnt++;
            minBallRight = points[ballonIndex][1]; // 更新对标气球右侧值
        }
    }

    cnt++;
    return cnt;
}

int main(){

    vector<vector<int>> queue = {{3,9},{7,12},{3,8},{6,8},{9,10},{2,9},{0,9},{3,9},{0,6},{2,8}};

//    vector<vector<int>> queue = {{1,2},{1,5},{4,5}};
//    vector<vector<int>> queue = {{1,2},{3,4},{2,3},{4,5}};
//    vector<vector<int>> queue = {{1,2},{3,4},{5,6},{7,8}};
//    vector<vector<int>> queue = {{10,16},{2,8},{1,6},{7,12}};
    int queue1 = findMinArrowShots(queue);

    cout << queue1;

    return 0;
}