#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;

//加油站

// 自己的方式暴力枚举，时间超了
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {


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
