#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include <vector>
using namespace std;


// 不能只考虑横着，还得考虑竖着  横着分析不行，因为竖着也会影响  实际上就是两数索引之差*max(两个数)

// （j-i）*(max(a[j],a[i])),现在问题来了，肯定不是把所有可能性都列一遍


// 该题思路是从全部的视角放到局部的视角，对于部分的S来说，实际上，他的有效面积为：他min(max(左侧所有的高)，max(右侧所有的高))*1  这是点睛之笔，然后如何求左/又测最高？做两个数组
int trap(vector<int>& v1) {

    vector<int> vL(v1.size(), 0);
    vector<int> vR(v1.size(), 0);
    int sum = 0;

    int maxL = v1[0];   // 对于左侧而言，最长的
    int maxR = v1[v1.size()-1]; // 对于右侧而言，最长的
    for (int i = 0; i < v1.size(); ++i) {
        maxL = max(maxL,v1[i]);
        vL[i] = maxL;

        maxR = max(maxR,v1[v1.size()-1-i]);   // 假设共三个元素: 1  2  3 ,若当前i = 0,则理应[]中的为2
        vR[v1.size()-1-i] = maxR;
    }

    // 求面积和
    for (int i = 0; i < v1.size(); ++i) {
        int water = min(vL[i], vR[i]) - v1[i];  // 这里下方计算面积是错误的！因为他是柱形图！而不是折线图，然后每个柱形的面积我们要去掉。
        if (water > 0) {
//            cout << water << ";";
            sum += water;
        }
    }

//    for (int i = 0; i < v1.size() - 1; ++i) {
//        sum+=min(vL[i],vR[i]);
//    }

    return sum;
}

int main(){
//    vector<int> v1 = {0,1,0,2,1,0,1,3,2,1,2,1};   // 6
    vector<int> v1 = {4,2,0,3,2,5};
    int s = trap(v1);
    cout << s;

    return 0;
}


