#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;

void rotate(vector<int>& nums, int k) {
    k = k%nums.size();

    vector<int> lsV;
    for (int i = nums.size()-k; i < nums.size(); ++i) {
        lsV.push_back(nums[i]);
    }

    // 前面的往后面挪
    for (int i = nums.size()-k-1;i>=0;i--) {
//        nums[nums.size()-1] = nums[i];
        nums[i+k] = nums[i];
    }

    for (int i = 0; i < lsV.size(); ++i) {
        nums[i] = lsV[i];
    }

}

int main(){
    vector<int> n1 = {1,2,3,4,5,6,7};
    vector<int> n2 = {-1,-100,3,99};

    rotate(n1,3);
    rotate(n2,2);

    for (int i = 0; i < n1.size(); ++i) {
        cout << n1[i] << ",";
    }
    cout << endl;
    for (int i = 0; i < n2.size(); ++i) {
        cout << n2[i]<< ",";
    }
    cout << endl;
    return 0;
}


