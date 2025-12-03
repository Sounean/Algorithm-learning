#include "iostream"
using namespace std;

//int nums[] = {1,17,5,10,13,15,10,5,16,8};
//int nums[] = {1,7,4,9,2,5};
int nums[] = {1,2,3,4,5,6,7,8,9};
int a[1500];
int main() {

    int index = 0;  // 坡度的索引
    for (int i = 0; i < 8; i++) {
        // 平坡就跳过，只去判断上坡和下坡的情况
        if(nums[i+1]-nums[i] != 0){
            // 如果是第一个坡，就不需要和前一项比较，直接存就好了(也没有前一项)
            if(index == 0){
                a[index] = nums[i+1]-nums[i];
                index++;
            } else{
                // 不是第一坡的时候，还需要跟前一个坡进行比较，是要相反的
                if(a[index-1]*(nums[i+1]-nums[i]) <0){
                    a[index] = nums[i+1]-nums[i];
                    index++;
                }
            }
        }
    }

    cout << index+1 << endl;

    return 0;
}