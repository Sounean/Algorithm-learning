#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;

// 有可以滑动窗口用的到的地方吗？找到有符合的第一个字符开始？

// 首先，既然要和p是异位词那就说明，长度一定要想等，所以可以做一个长度为p.size的窗口，然后往后挪动，每次新的和p进行比较即可。--》此处将问题转换成了如何去把和p进行的比较变得简单

// 可以将每个字母的频率存到vector数组中去  后面可以直接和p对应的数组作比较即可；  然后窗口移动一位其实就是l向左移动一位，r向右移动一位   -->将上一个问题：比较两个字符串转变成比较字符串中各个字母出现的频率


vector<int> findAnagrams(string s, string p) {
    vector<int> indexV;

    if(s.size()<p.size())return indexV;

    vector<int> pCount(26,0);
    vector<int> sCount(26,0);
    for (int i = 0; i < p.size(); ++i) {
        pCount[p[i]-'a']++; // 统计字符串p中各字母出现的频率
        sCount[s[i]-'a']++; // 开头长度为p的字符串，出现的统计的频率
    }

    if (pCount == sCount)indexV.push_back(0);

    for (int i = 0; i < s.size() - p.size(); ++i) {
        sCount[s[i]-'a']--;
        sCount[s[i+p.size()]-'a']++;

        if (pCount == sCount)indexV.push_back(i+1); // 记住这里是i+1而不是i  因为我们上面的步骤本质上是去掉第i个，所以子字符串开头的下标是i+1处开始的
    }

    return indexV;
}

int main(){
    string s1 = "cbaebabacd";
    string p1 = "abc";

    string s2 = "abab";
    string p2 = "ab";

    vector<int> v1 = findAnagrams(s1,p1);
    vector<int> v2 = findAnagrams(s2,p2);

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] << ",";
    }
    cout << endl;
    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] << ",";
    }

    return 0;
}


