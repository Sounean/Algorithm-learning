#include "iostream"
#include <vector>
#include "map"
#include "string"
#include "algorithm"
using namespace std;

// 对所有字符串进行排序，如果属于题中的字母异位词的那么他们的排序后的大小是一样，如"acb"和“cab”排序后均为“abc”。
//具体思路就是如上，接下来要做的就是遍历，然后比较，不一样的则添加新的keymap，如果之前有一样的key存在则找出之前的value，添加一个元素进去。

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string,vector<string>> map;
    for (int i = 0; i < strs.size(); ++i) {
        vector<string> v1;
        string s1 = strs[i];
        string s2= s1;
        sort(s2.begin(),s2.end());
        if (map.count(s2)>0){
            // 如果原来有，就在原来的里面添加进去
            v1 = map[s2];
            v1.push_back(s1);
        }else{
            v1.push_back(s1);
        }
        map[s2] = v1;
    }

    vector<vector<string>> group;
    for (const auto& kv:map) {
        group.push_back(kv.second);
    }

    return group;
}



int main(){
    vector<string> nums = {"eat", "tea", "tan", "ate", "nat", "bat"};
//vector<string > nums = {""};
//vector<string > nums = {"",""};
//    vector<vector<string>>  max = groupAnagrams(nums);
//    for (int i = 0; i < max.size(); ++i) {
//        cout << "[";
//        for (int j = 0; j < max[i].size(); ++j) {
//            cout << max[i][j]<< ",";
//        }
//        cout << "];";
//    }

    string str2 = "acb";
    string str1 = str2;

    sort(str1.begin(),str1.end());
    cout << str1<< ";" << str2;
    return 0;
}