#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;

// 记录0的下标 vector<int>  然后跳过本次的乘积
// 如果0的数量大于1的话，全部是0；
// 如果等于1的话，只有当i为0的下标的时候直接返回乘积，其他均为0
// 如果等于0的话，每次计算的时候直接除以当前的数字
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> zeroNums = {};
    int allChengJi
    for (int i = 0; i < nums.size(); ++i) {

    }


}

int main(){

    vector<int> v1 = {1,2,3,4};
    vector<int> v2 = {-1,1,0,-3,3};

    v1 = productExceptSelf(v1);
    v2 = productExceptSelf(v2);

    for (int i = 0; i < v1.size(); ++i) {
        cout << v1[i] <<",";
    }
    cout << endl;

    for (int i = 0; i < v2.size(); ++i) {
        cout << v2[i] <<",";
    }
    cout << endl;

    return 0;
}


