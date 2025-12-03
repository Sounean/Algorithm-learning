#include "iostream"
#include <vector>
#include "cmath"
#include "algorithm"
using namespace std;

// 这题重点是每个元素
// case1：假设身高相同的情况下，可以根据第二个元素第二个值来确定他们的前后顺序(谁更大，谁放后面 (但是无法具体到他们中间是否有隔几个))  先按身高也是从低到高的排一次，这样同值之间的前后确认下来了
// [4,4],[5,0],[5,2],[6,1],[7,0],[7,1]
// case2：身高不相同的值，从case1下来的数组从后往前判断,看值是多少且移动 [5,0],[7,0],[5,2],[6,1],[4,4],[7,1]  从后往前手动是可以的；
//        从前往后手动去找:[5,0],[6,1],[5,2],[7,0],[4,4],[7,1]   从前往后不好找，因为从前往后的话会因为部分元素需要变到右侧去，后面值再移位子不能简单通过+diff去找，而是需要先判断值；
//                                     而从后往前的找的话，往后挪之后，再前面的数要移动位子只需要+diff即可(因为他后面的数肯定>=他)
bool cmp(vector<int> people1,vector<int> people2){
    if(people1[0] != people2[0]){   // 先比较值大小
        return people1[0]<people2[0];
    }else{  // 当值大小一样时，再比较下标1的值
        return people1[1] < people2[1];
    }
}

vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(),people.end(), cmp);

    for (int i = people.size()-2; i >=0 ; i--) {
        if (people[i][0]!=people[i+1][0]){  // 一般出现要移动的，只会出现在数值开始变不一样的时候
            if (people[i][1]!=0){
                // 往前找看有几个值相同的
                int index = i;
                int sameNum = 0;
                while (people[index][0]==people[index-1][0]){
                    sameNum++;
                    index--;
                }
                // 当相同的值不够用时，就需要将该值往后挪了
                if (sameNum!=people[i][1]){
                    people.insert(people.begin()+i+people[i][1]-sameNum , people[i]);
                    people.erase(people.begin()+i);
                }
            }
        }
    }

    return people;
}

int main(){

    vector<vector<int>> queue = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
    vector<vector<int>> queue1 = reconstructQueue(queue);
    for (int i = 0; i < queue1.size(); ++i) {
        cout<<queue1[i][0]<<"-"<<queue1[i][1] << "  ";
    }

    return 0;
}