// 滑动窗口  结合 滑动窗口模板示意图.png 去理解
while(right<s.size())
{
    char c=s[right]
    right++;
    ...//更新数据
    while(valid==needs.size())      // 此处随着题目的条件改变而改变
    {
        ...   //一般用于更新答案
        char d=s[left];
        left++;                             // 满足条件后移动指针
        ... //更新数据
    }

}


// 题:给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);     // 如果截取的数组中有r所指的字符，则从头开始删，删到这个字符没有才结束
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;

    }
};
