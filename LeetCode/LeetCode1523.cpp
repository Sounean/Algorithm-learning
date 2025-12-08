#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
using namespace std;

// 左奇右偶：1,4--> （4-1）/2+1    1，2--》(2-1)/2+1
// 左偶右奇：2，3--》（3-2）/2+1    2，5 --》 （5-2）/2+1
// 左偶右偶：2，4--》（4-2）/2
// 左奇右奇
int countOdds(int low, int high) {
    int cnt = 0;
    for (int i = low; i <=high ; ++i) {
        if(i%2==1)cnt++;
    }
    return cnt;
}

int main(){

    cout << countOdds(8,10);

    return 0;
}


