#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
#include <cstdlib>
using namespace std;


// 数值大时超时了
//bool right(int value){
//    int geWei;
//    while (value!=0 || value>10){
//        geWei = value%10;
//        value = value/10;
//        int newGeWei = value%10;
//        if (newGeWei>geWei){
//            return false;
//        }
//    }
//    return true;
//}
//
//int monotoneIncreasingDigits(int n) {
//    for (int i = n; ; i--) {
//        if (right(i)){
//            return i;
//        }
//    }
//}


// 从最左侧开始动手从左往右遍历，

// 特殊情况是 产生a[i]--，和a[i+1]=9之后，导致a[i-1]>a[i],又变的不符合条件了，这个情况往前遍历，找到第一个前者和后者不相等的，将后者值-1，随后后面全部用9补齐；如果一直找到第一位都是相等的，那么就第一位-1，后面全部用9补齐
int monotoneIncreasingDigits(int n) {
    string str = to_string(n);
    int strLen = str.size();
    string lastOutStr = "";
    
    for (int i = 0; i < strLen; ++i) {
        // 检查是否到达最后一个字符，或者当前字符小于等于下一个字符
        if (i == strLen - 1 || str[i] <= str[i+1]){
            // 如果符合上坡，拼接上去就完了
            lastOutStr += str[i];
        } else {
            // 产生str[i]>str[i+1]了
            // 检查lastOutStr是否为空，或者str[i]-1仍然符合单调递增
            if(lastOutStr.empty() || str[i]-1 >= lastOutStr[lastOutStr.size()-1]){  
                // 依旧符合
                lastOutStr += (str[i]-1);
                // 后面全部用9补齐
                for (int j = 0; j < strLen - lastOutStr.size(); ++j) {
                    lastOutStr += '9';
                }
                int num = stoi(lastOutStr);
                return num;
            } else {
                // 产生不符合的了，需要往前找
                int findIndex = lastOutStr.size()-1;
                while (findIndex > 0){
                    if (lastOutStr[findIndex] != lastOutStr[findIndex-1]){
                        // 此处可以改成平坡
                        char c1 = lastOutStr[findIndex];
                        lastOutStr = lastOutStr.substr(0, findIndex);  // 修正：截取前面的部分
                        lastOutStr += (c1-1);
                        for (int j = 0; j < strLen - lastOutStr.size(); ++j) {
                            lastOutStr += '9';
                        }
                        int num = stoi(lastOutStr);
                        return num;
                    }
                    findIndex--;  // 修正：递减索引
                }
                // 如果到头都没有上坡的，那就直接头部就-1，后面都补9
                if (!lastOutStr.empty()) {
                    char c1 = lastOutStr[0]-1;
                    lastOutStr = string(1, c1);  // 修正：重新构造字符串
                } else {
                    // 如果lastOutStr为空，说明第一个字符就不符合
                    lastOutStr = string(1, str[i]-1);
                }
                for (int j = 0; j < strLen - lastOutStr.size(); ++j) {
                    lastOutStr += '9';
                }
                int num = stoi(lastOutStr);
                return num;
            }
        }
    }
    
    // 如果所有字符都符合条件，直接返回原数
    return n;
}
int main(){
    int n = 10;
//    int n = 1234;
//    int n = 332;

    cout << monotoneIncreasingDigits(n);
    return 0;
}