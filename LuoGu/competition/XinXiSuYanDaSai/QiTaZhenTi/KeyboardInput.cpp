#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
    return a>b;
}

int main() {
    string input;
    cin >> input;
    
    // 统计每个字符的出现次数
    int count[26] = {0}; // 只考虑小写字母a-z
    
    for (char c : input) {
//        if (c >= 'a' && c <= 'z') {
            count[c - 'A']++;
//        }
    }
    
    // 找出最大和最小出现次数（只统计出现过的字符）
    int maxCount = 0;
    int minCount = 1000; // 初始化为一个大值
    
//    for (int i = 0; i < 26; i++) {
//        if (count[i] > 0) {
//            maxCount = max(maxCount, count[i]);
//            minCount = min(minCount, count[i]);
//        }
//    }

    sort(count,count+input.length() , cmp);

//    max(count,count+input.length());

    // 根据题目要求判断输出
    // 如果 maxCount - minCount == 0，说明所有字符出现次数相同
    if (maxCount - minCount == 0) {
        cout << "LuminousHarmony" << endl;
    } else {
        cout << "SilentKeys" << endl;
    }
    
    cout << maxCount - minCount << endl;
    
    return 0;
} 