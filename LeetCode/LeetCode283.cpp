#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
using namespace std;

// 两个指针，一个指向当前赋值到新数组的第i位了；另一个指向获取的是旧数组的第j位；
// 如果
void moveZeroes(vector<int>& nums) {
    int oldIndex = 0;
    int newIndex = 0;
    for (; oldIndex < nums.size(); ++oldIndex) {
        if (nums[oldIndex]!=0){
            nums[newIndex++] = nums[oldIndex];
        }
    }

    for (; newIndex < nums.size(); newIndex++) {
        nums[newIndex] = 0;
    }

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ";";
    }
}

int main(){

    vector<int> v1 = {0,1,0,3,12};
    moveZeroes(v1);
    return 0;
}


