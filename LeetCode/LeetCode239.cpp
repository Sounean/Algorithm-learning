#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
#include "stack"
using namespace std;

// 得想到每个数字有效的生命周周期，再找到共性  新添加进来的元素可以直接供抛弃掉之前栈中所有小于他的，因为之前栈中所有小于他的1.生命周期比他短。2.选更大值时肯定新进来的大元素优先
// --> 总结就是输出的肯定是新的更大的值   --》 又有新问题，如果有个老元素一直被留在后面该咋办？
// --> 进来偏小的值也直接添加进来栈中，因为不能保证老大值被踢出去后，偏小值可能成为剩下得最大值


// 基本步骤1.滑动窗口向右边移动时，检查最左测被丢弃的是否值是双端队列的最左侧的值，是的话则从队列中也去掉(因为表示已经超过他的生命周期了)
// 基本步骤2.滑动窗口向右边移动时，检查最右侧新添加进来的大小，如果队列尾有比他小的，则出栈掉，把他添加到后方；  (为什么可以删除，因为新添加的不仅生命周起比他们长，值还比他们大)
//                                                  添加到后方；
// 基本步骤3.输出队列顶元素，即当前的最大值.

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    stack<int> stack1;
    vector<int> outV;   // 最终要输出的数组
//    for (int i = 0; i < ; ++i) {

//    }
//  3  2  1  0

}

int main(){

    vector<int> n1 = {3,2,1,0};
//    vector<int> n1 = {1,3,-1,-3,5,3,6,7};
    n1 = maxSlidingWindow(n1,3);
    for (int i = 0; i < n1.size(); ++i) {
        cout << n1[i] << ",";
    }

    return 0;
}


