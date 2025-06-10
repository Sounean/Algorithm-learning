#include <iostream>
#include <cmath>    // 导入这个才能用sqrt

using namespace std;

int n, k;
int a[25];  // 修改：使用固定大小数组
int cnt = 0;

// 返回false表示非素数 true表示是素数
bool judgetSuShu(int num){
    if(num < 2) return false;  // 修改：处理小于2的情况
    bool isSuShe = true;
    int breakNum = sqrt(num);
    for(int i = 2; i <= breakNum; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

// 新增：DFS函数来选择k个数
// start: 从第几个数开始选择
// selected: 已经选择了几个数
// sum: 当前选择的数的和
void dfs(int start, int selected, int sum) {
    // 如果已经选择了k个数，检查和是否为素数
    if(selected == k) {
        if(judgetSuShu(sum)) {
            cnt++;
        }
        return;
    }
    
    // 从start开始选择数字
    for(int i = start; i < n; i++) {
        dfs(i + 1, selected + 1, sum + a[i]);   // 但是好像取得值，都是相邻的吧
    }
}

int main(){
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 修改：使用DFS而不是三重循环
    dfs(0, 0, 0);

    cout << cnt;

    return 0;
}


/*
 *
 * 3. 说明我的代码哪里的思路不够好
3.1 最大的问题：理解题意错误
你的代码固定选择3个数（三重循环），但题目要求选择k个数
这是致命错误，导致除了k=3的情况外，其他测试用例都无法通过
3.2 算法思路局限
使用三重循环只能处理k=3的情况，缺乏通用性
没有考虑到组合数学的本质：从n个数中选k个数的所有可能组合
3.3 边界条件处理不完善
素数判断函数没有处理小于2的情况
循环边界条件写死了，不够灵活
3.4 缺乏优化意识
没有剪枝优化
素数判断可以更高效（只检查奇数）
4. 我的代码风格有写的不好的地方
4.1 变量命名不规范
judgetSuShu 应该是 isPrime 或 judgePrime
isSuShe 应该是 isPrime
breakNum 应该是 limit 或 sqrtNum
4.2 代码结构问题
使用了变长数组 int a[n+2]，这在C++中不是标准做法
应该使用 vector<int> 或固定大小数组
4.3 注释和文档不足
缺乏函数功能说明
关键算法逻辑没有注释
4.4 代码风格不一致
有些地方用了空格，有些没用
括号风格不统一
4.5 没有输入输出优化
对于竞赛题目，应该加上 ios::sync_with_stdio(false) 等优化
4.6 魔法数字
循环中的硬编码数字（如 n-2, n-1）应该用有意义的变量名
总结： 你的主要问题是理解题意错误，把"选k个数"理解成了"选3个数"。建议以后做题时先仔细分析题目要求，理解清楚后再开始编码。同时要注意代码的通用性和可扩展性。
 * */