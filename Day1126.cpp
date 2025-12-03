#include <iostream>
#include "algorithm"
using namespace std;

int main(){
    // 局部最优：每个饼干都尽可能不被浪费 全局最优：尽量多的小朋友胃口得到满足
    int g[] = {1,2};
    int s[] = {1,2,3};

    sort(g,g+2);
    sort(s,s+3);

//    for (int i = 0; i < 3; ++i) {
//        cout << g[i] << " ";
//    }

    // 1.有满足的时候：当s[j]>=g[i],j++,i++,cnt++
    // 2.产生g[i]>s[j],饼干需要找一个更大的，但是当j>s.size(),分配结束


    int i = 0;
    int cnt = 0;
    for (int j = 0; j < 3; ) {
        if (s[j]>=g[i]){
            j++;
            j++;
            cnt++;
        }else{
            j++;
        };
    }

    cout << cnt;

    return 0;
}
