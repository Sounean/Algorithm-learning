#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;

// 这题感觉很简单
// 直接全部人分配1先，然后从头往后看，如果a[i+1]-a[i]>1,则a[i+1]就再多一个糖果
// 但是 1  3  2   1,好像按上面的不行，因为会出现推出第一个人1，第二个人2，第三个人1，第四个人就为0了

// 感觉实际上是找“坡”数量，找要不是平坡，就有差值的情况产生。找到数组中的最小值，全部人都减去该值；然后再找到峰点，查找两次坡的数量，按照更大值来设峰值（又有一个问题，怎么找峰旁边的谷呢？）

// 直接按照分数给了！然后找到最小值，全部减去最小值-1，让最小值变成1；然后将值分别存到


int candy(vector<int>& ratings) {

}

int main(){

    // 环路
//    vector<int> gas  = {1,2,3,4,5}; // 第 i 个加油站有汽油 gas[i] 升
//    vector<int> cost  = {3,4,5,1,2};    // 从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
    vector<int> gas  = {2,3,4}; // 第 i 个加油站有汽油 gas[i] 升
    vector<int> cost  = {3,4,3};    // 从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
    cout << candy(gas);

    return 0;
}
