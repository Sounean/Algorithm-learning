#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;

// [i,j,k],其中大小顺序 i  j   k  且肯定a[i] = a[k] = 2a[j]

// 直接set?
// 那必须是i指向开头的   直接转换成set，然后直接去找他自身大小和1/2的，如果存在，则通过索引判断，不存在直接跳过（不对啊，set的话就去重了）

// 我能想到的就是遍历，然后减枝（判断set中是否有他的值两倍的和他自身的）
int specialTriplets(vector<int>& nums) {
    map<int,vector<int>> map;
    for (int i = 0; i < nums.size(); ++i) {
        vector<int> v1;
        if (map.count(nums[i])){
            // 如果map中有了，就添加进去
            v1 = map[nums[i]];
        }
        v1.push_back(i);
        map[nums[i]] = v1;
    }

    int sum = 0;
    for (const auto& [key, vec]:map) {
        if (key/2*2 != key)continue;    // 是奇数的直接跳

        if (map.count(key) && map[key].size()>=2 && map.count(key/2)){
            vector<int> vik = map[key];
            vector<int> vj = map[key/2];
            int k = vik[vik.size()-1];  // 因为存放的时候下标都是按顺序存放的，所以直接取最后一个肯定是最大的
            int i = vik[0];
            int flag = false;
            for (int j = 0; j < vj.size(); ++j) {
                if (j>k && j<i){
                    flag = true;
                    break;
                }
            }
            if (flag)sum++;
        }
    }

    // 上述方式省略了有3个0的情况
//    if (map[0].size()>=3)sum++;

    return sum;
}

int main(){

    vector<int> v1 = {6,3,6};   // 1
    vector<int> v2 = {0,1,0,0};
    vector<int> v3 ={8,4,2,8,4};
//    int l1 = specialTriplets(v1);
//    cout << l1;
    int l2 = specialTriplets(v2);
    cout << l2;
//    int l3 = specialTriplets(v3);
//    cout << l3;
    return 0;
}


