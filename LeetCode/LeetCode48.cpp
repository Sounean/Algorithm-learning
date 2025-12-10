#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;



void rotate(vector<vector<int>>& matrix) {
    int temp1 = 0;
    for (int i = 0; i < matrix.size()/2; ++i) {   // 有几行 代表旧x
        for (int j = i; j < matrix.size()-1-i; ++j) {    // 有几列  代表旧y
            temp1 = matrix[i][j];
            matrix[i][j] = matrix[matrix.size()-1-j][i];
            matrix[matrix.size()-1-j][i] = matrix[matrix.size()-1-i][matrix.size()-1-j];
            matrix[matrix.size()-1-i][matrix.size()-1-j] = matrix[j][matrix.size()-1-i];
            matrix[j][matrix.size()-1-i] = temp1;

        }
    }
}

int main(){
    vector<vector<int>> v1 = {{5,1,9,11} , {2,4,8,10} , {13,3,6,7} , {15,14,12,16}};

    vector<vector<int>> v2 = {{1,2,3} , {4,5,6} , {7,8,9}};

     rotate(v1);
     rotate(v2);

    for (int i = 0; i < v1.size(); ++i) {
        cout << "[";
        for (int j = 0; j < v1[0].size(); ++j) {
            cout << v1[i][j] << ",";
        }
        cout << "]";
    }

    for (int i = 0; i < v2.size(); ++i) {
        cout << "[";
        for (int j = 0; j < v2[0].size(); ++j) {
            cout << v2[i][j] << ",";
        }
        cout << "]";
    }

    return 0;
}


