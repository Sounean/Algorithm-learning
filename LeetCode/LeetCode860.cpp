#include "iostream"
#include <vector>
using namespace std;

// 该题重点是，相对面额10的来说，面额5的更万能，所有当出现有客户付20时，优先给10的。

// a5,a10
// 就对每个元素进行判定，然后加；
//                          如果等于5，直接a5++
//                          如果等于10，a10++,a5--
//                          如果出现20，先a10--，不够了再找a5，如果都不够则return false
bool lemonadeChange(vector<int>& bills) {
    int a5 = 0;
    int a10 = 0;
    for (int i = 0; i < bills.size(); ++i) {
        if (bills[i]==5){
            a5++;
        }else if(bills[i]==10){
            a5--;
            a10++;
        } else {
            if(a10>0){  // 当面额10还有的时候，优先出10的
                a10--;
                a5--;
            } else{
                a5 = a5-3;
            }
        }
        if(a5<0){
            return false;
        }
    }
    return true;

}


int main(){
    vector<int> nums = {5,5,10,10,20};
//    vector<int> nums = {5,5,5,10,20};
    cout << lemonadeChange(nums);

    return 0;
}