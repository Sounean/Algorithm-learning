#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
#include "map"
using namespace std;

// 从左往右遍历字母，获取str[i]后用rfind去找最后一个的他的下标值，更新curMinStrLength，截取当前的字符串出来
// 然后从头往后遍历到curMinStrLength,如果出现字母是map中没有的，则更新进map，并且在原字符串数组上rfind，且更新curMinStrLength，内循环结束代表一个子字符串处理好了,将长度加进vector中


vector<int> partitionLabels(string s) {
    vector<int> strLen={};
    int preIndex = 0;
    int curMinStrLength = 0;
    map<char,int> charMap;
//    int curMinStrLength = 0;
//    vector<char> charVector = {};
    for (int i = 0; i < s.size(); ) {   // 第三参不需要，以为是更根据上一个字符串的最后下标来的
        char c1 = s[i];
        curMinStrLength = s.rfind(c1);
        if (curMinStrLength==9){
//            cout<< 1;
        }
        for (int j = preIndex; j < curMinStrLength; ++j) {
//            char c2=  s.rfind(s[j]);
            if (charMap.count(s[j])==0){
                charMap[s[j]] = 1;
                int c2Index = s.rfind(s[j]);
                curMinStrLength = max(curMinStrLength , c2Index);
                if (curMinStrLength==9){
//                    cout<< 1;
                }
            }else{
                continue;   // 表示是属于之前已经有的字母了，则跳过
            }

        }
        strLen.push_back(curMinStrLength-preIndex+1);
        preIndex = curMinStrLength+1;   // 此处要+1，因为cur所指的下标此时还是上一个字符串中的字母
        i = curMinStrLength+1;
    }


    return strLen;
}

int main(){

//    string s = "eaaaabaaec";
//    string s = "eccbbbbdec";
    string s = "ababcbacadefegdehijhklij";
    vector<int> queue1 = partitionLabels(s);

    for (int i = 0; i < queue1.size(); ++i) {
        cout << queue1[i] << " ";
    }

    return 0;
}