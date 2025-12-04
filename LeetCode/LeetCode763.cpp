#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;

// 从左往右遍历字母，获取str[i]后用rfind去找最后一个的他的下标值，更新curMinStrLength，截取当前的字符串出来
// 然后从头往后遍历到curMinStrLength,如果出现字母是map中没有的，则更新进map，并且在原字符串数组上rfind，且更新curMinStrLength，内循环结束代表一个子字符串处理好了,将长度加进vector中


vector<int> partitionLabels(string s) {
    vector<int> strLen={};
    int preIndex = 0;
    int curMinStrLength = 0;
    vector<char> charVector = {};
    for (int i = 0; i < s.size(); ++i) {
        char c1 = s[i];
        int new= s.rfind(c1);
        for (int j = preIndex; j < curMinStrLength; ++j) {

        }
    }


    return strLen;
}

int main(){

    string s = "ababcbacadefegdehijhklij";
    vector<int> queue1 = partitionLabels(s);

    for (int i = 0; i < queue1.size(); ++i) {
        cout << queue1[i] << " ";
    }

    return 0;
}