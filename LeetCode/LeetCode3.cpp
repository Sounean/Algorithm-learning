#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;


//  双指针，一个指向当前序列的头，一个
// 如果按照双指针的话，还得考虑出现  abcsdba 这种中途出现的非但要往前面找，还得将左指针移动且从数组中删除某些元素,(用数组存不好，因为还得考虑删除，那么就不能用int[],但用来查找的话vector又不方便，故直接用字符串,到时候直接截取)

int lengthOfLongestSubstring(string s) {
    if (s.length()==0||s.length()==1)return s.size();

    int maxLength = 0;
//    int lIndex = 0;
    int rIndex = 1;
    string maxStr = "";
    maxStr+=s[0];
    while (rIndex<s.size()){
        int index=maxStr.find(s[rIndex]);
        if (index==string::npos){    // 如果再之前所截取的字串中没有的话,直接添加
            maxStr+=s[rIndex];
        }else{// 进行删除
            maxStr = maxStr.substr(index+1);
            maxStr+=s[rIndex];
        }
        rIndex++;
        maxLength = max(maxLength , (int)maxStr.size());
    }

    return maxLength;
}

int main(){
//    string str = "a";
//    int index=str.find('a');
//    str = str.substr(index+1);
//    cout << str;

    string str1 = "abcabcbb";
    cout << lengthOfLongestSubstring(str1)<<endl;
    string str2 = "bbbbb";
    cout << lengthOfLongestSubstring(str2)<<endl;
    string str3 = "pwwkew";
    cout << lengthOfLongestSubstring(str3)<<endl;
//string str = "avc";
//    cout << str.find('v');
    return 0;
}


