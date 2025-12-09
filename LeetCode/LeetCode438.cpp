#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;

// 有可以滑动窗口用的到的地方吗？找到有符合的第一个字符开始？

// 找到有符合的，如果字符能在p中find的到立即开始？
// 写一个map m1分别去存他们拆开的字符出现的次数。后面都要和这个对标
//  赋值m1为m2，一个对比map<char,int>（字符，出现的次数）
//   map<char,vector<int> mIndex(字符，出现的索引)
//    如果往后面挪发现不在p里面直接跳过，l变到r后面重新找
//    如果往后面挪发现在p中，刷新map，将里面对应值-1，如果发现出现-1的说明可能出现多出来的,那么直接更新l一直到mIndex所记录的第一个的后一个索引，中间出现的全部都在m1中次数加回去，mIndex中减掉

// 如果r-l+1 == p.size()那么说明有成功找到一个，此时l+r同时往后挪


vector<int> findAnagrams(string s, string p) {
    vector<int> v1; // 最终答案里的

    string currentStr = "";
    map<char,int> mTimes;   // 次数map
    for (int i = 0; i < p.size(); ++i) {
        if (mTimes.count(p[i])){// 如果原来map中有
            mTimes[p[i]] = 0;
        } else {    // 如果原来map没有
            mTimes[p[i]]++;
        }
    }

    int right =0;
    int left = 0;
    while (mTimes.count(s[left])<0)left++;

    if (left>=s.size()-p.size())return v1;

    for (; left < s.size()-p.size(); ++left) {
        while (mTimes.count(s[left])==0){
            left++;
        }
        if (left==s.size())break;
        map<char,int> curTime = mTimes;
        right = left++;


        // 不会有下面这步，因为上面while循环已经保证了可你的那个有
//        if (mTimes.count(s[i]) == 0){   // 如果在次数map中都么有说明是直接不符合的
//
//        }
        while (mTimes.count(s[right])>0 && mTimes[s[right]]>0){ // 当右指针指向的属于合法范围内的时候

        }

    }

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


