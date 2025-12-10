#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * LeetCode 406: 根据身高重建队列
 * 
 * 正确思路：
 * 1. 先按身高从高到低排序，身高相同则按 k 从小到大排序
 * 2. 然后按 k 值插入到结果数组的对应位置
 *    因为前面插入的都是身高 >= 当前身高的，所以直接按 k 插入即可保证正确性
 * 
 * 为什么这样是对的？
 * - 当我们按身高从高到低排序后，对于每个元素，前面已经插入的元素身高都 >= 当前元素
 * - 所以当前元素的 k 值就是它应该插入的位置索引
 * - 例如：[7,0] 应该在第0个位置，[5,2] 应该在第2个位置（前面有2个身高>=5的）
 */

bool cmp(vector<int> people1, vector<int> people2){
    if(people1[0] != people2[0]){   // 先按身高从高到低排序
        return people1[0] > people2[0];
    }else{  // 身高相同，按 k 从小到大排序
        return people1[1] < people2[1];
    }
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    // 先排序：身高从高到低，身高相同则 k 从小到大
    sort(people.begin(), people.end(), cmp);

    // 处理下来的数组天生满足前面比后面的大
    // 所以接下来只需要满足前面到底有几个比他大的即可  --》 这一步变换成先搞一个空列表，直接将其放在people[i][1]位(先不管其他元素具体的值，反正他的位子确实就应该在哪里)
    for (int i = 0; i < people.size(); ++i) {
        cout << people[i][0] << "-" << people[i][1]<< "  ";
    }
    
    // 按 k 值插入到结果数组
    vector<vector<int>> result;
    for(int i = 0; i < people.size(); i++){
        // 将 people[i] 插入到 result 的第 people[i][1] 个位置
        // 因为前面插入的都是身高 >= people[i][0] 的，所以直接按 k 插入即可    这样不会影响原来的值，不会导致出现不符合people[i][1]的情况，因为新插入的值都比之前的要小！
        result.insert(result.begin() + people[i][1], people[i]);
        cout<< "ever circle vector:";
        for (int j = 0; j < result.size(); ++j) {
            cout<<result[j][0]<<","<<result[j][1]<< "  ";
        }
        cout << endl;
    }
    
    return result;
}

int main(){
    vector<vector<int>> queue = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    
    cout << "输入: ";
    for (int i = 0; i < queue.size(); ++i) {
        cout << "[" << queue[i][0] << "," << queue[i][1] << "]";
        if (i < queue.size() - 1) cout << " ";
    }
    cout << endl;
    
    vector<vector<int>> result = reconstructQueue(queue);
    cout << "输出: ";
    for (int i = 0; i < result.size(); ++i) {
        cout << "[" << result[i][0] << "," << result[i][1] << "]";
        if (i < result.size() - 1) cout << " ";
    }
    cout << endl;
    
    // 验证结果
    cout << "\n验证: " << endl;
    for (int i = 0; i < result.size(); ++i) {
        int count = 0;
        for (int j = 0; j < i; ++j) {
            if (result[j][0] >= result[i][0]) {
                count++;
            }
        }
        cout << "位置 " << i << ": [" << result[i][0] << "," << result[i][1] 
             << "], 前面有 " << count << " 个身高 >= " << result[i][0] 
             << " 的人" << (count == result[i][1] ? " ✓" : " ✗") << endl;
    }

    return 0;
}






