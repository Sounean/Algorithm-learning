#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;

/*
 * 加油站问题 - 数学原理说明：
 * 
 * 关键结论：如果总油量 >= 总消耗，那么一定存在至少一个起点可以完成一圈
 * 
 * 数学证明：
 * 1. 定义 rest[i] = gas[i] - cost[i]，表示从站点i到站点i+1的净收益（或净消耗）
 * 2. 如果 sum(rest[i]) >= 0，说明总收益 >= 0，即总油量 >= 总消耗
 * 
 * 为什么 sum(rest[i]) >= 0 就能保证可以跑完一圈？
 * 
 * 反证法：
 * 假设 sum(rest[i]) >= 0，但无论从哪个起点开始都无法完成一圈。
 * 这意味着：对于任意起点k，在行驶过程中总会在某个位置j处，累积油量变成负数。
 * 
 * 但是，如果我们把所有站点的rest[i]加起来：
 * - 从起点k开始，累积到位置j时油量变成负数
 * - 这意味着 rest[k] + rest[k+1] + ... + rest[j] < 0
 * - 那么剩余的 rest[j+1] + ... + rest[k-1] 必须 > 0（因为总和 >= 0）
 * 
 * 关键洞察：如果从某个起点k无法完成，那么问题一定出在k到j这段路上。
 * 但是，如果总和 >= 0，那么必然存在另一段路（j+1到k-1）的累积收益是正的，
 * 足以抵消k到j这段的负收益。这意味着我们可以从j+1开始，而不是从k开始。
 * 
 * 更直观的理解：
 * - 如果总和 >= 0，说明"总资产"是够的
 * - 虽然某些路段会"亏钱"（rest[i] < 0），但总有其他路段"赚钱"（rest[i] > 0）
 * - 只要我们从合适的位置开始（比如从"赚钱"路段开始），就能用赚的钱来填补亏的钱
 * 
 * 注意：sum(rest[i]) >= 0 并不意味着每个 rest[i] 都 >= 0
 * 而是说：即使有些 rest[i] < 0，但总和仍然 >= 0，所以一定存在一个起点可以完成
 */

// 先从最简单的绕一圈比较gas和cost相同索引上的值的大小比较，如果cost>gas则表示不能从此处开始(因为会根本到不了下个站点)
//                                                 如果有cost=<gas的，则尝试从那个索引开始执行开车操作，然后判断是否能走回来
//                                                                                            中间出现油量<0则表示不够走回来了，则break本次的路线
//                                                                                            如果能加回来原来的坐标的表示可以回来，可以结束循环输出true
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    // 去假设站点是从某个站点开始的
    for (int i = 0; i < gas.size(); ++i) {
        if(cost[i]>gas[i])continue;

        int currentGas = 0; // 当前车内可用汽油

        // 如果当前可以满足作为第一个站点，则开始判断
        int currentIndex=i;
        int tempIndex = currentIndex+gas.size();    //表示应当到此处加油站之后就结束(将原先形成环状的加油站变成重复循环的)
//        for (;currentIndex<currentIndex+gas.size() ;currentIndex++) {
        for (;currentIndex<tempIndex ;currentIndex++) {
            currentGas = currentGas+gas[currentIndex%(int)gas.size()]-cost[(currentIndex)%(int)gas.size()];  // 这个状态代表车开到下一个站点上，但还未加油时的油量
            if (currentGas<0)break;
        }

        if (currentGas>=0){
            return i;
        }
    }

    return -1;
}

int main(){

    // 环路
//    vector<int> gas  = {1,2,3,4,5}; // 第 i 个加油站有汽油 gas[i] 升
//    vector<int> cost  = {3,4,5,1,2};    // 从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
    vector<int> gas  = {2,3,4}; // 第 i 个加油站有汽油 gas[i] 升
    vector<int> cost  = {3,4,3};    // 从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升
    cout << canCompleteCircuit(gas,cost);

    return 0;
}
