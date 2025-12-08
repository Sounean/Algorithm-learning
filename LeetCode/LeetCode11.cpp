#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
using namespace std;


// 不能只考虑横着，还得考虑竖着  横着分析不行，因为竖着也会影响  实际上就是两数索引之差*max(两个数)

// （j-i）*(max(a[j],a[i])),现在问题来了，肯定不是把所有可能性都列一遍
int countOdds(vector<int> v1) {

    return cnt;
}

int main(){
    vector<int> v1 = {1,8,6,2,5,4,8,3,7};   // 49
    cout << countOdds(v1);

    return 0;
}


