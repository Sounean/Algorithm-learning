#include "iostream"
#include "map"
#include "algorithm"
#include "cmath"
#include "string"
#include "vector"
using namespace std;


// 创建一个副本出来，然后有遍历到的地方就把值设为1，本质上是沿着四种方向延续着移动，然后碰到非0或者到头的即改变方向  消耗时复O(n)肯定逃不掉，空间O(2*n*m)

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> collectPos;

    int row = matrix.size();    // 行
    int colunm = matrix[0].size();  // 列
    vector<vector<int>> vRow(row+2,vector<int>(colunm+2,0));   // 0代表值有没有被修改过
    // 给边界四条铺成0
    for (int i = 0; i < colunm+2; ++i) {
        vRow[0][i] = 1;
        vRow[row+1][i] = 1;
    }
    for (int i = 0; i < row+2; ++i) {
        vRow[i][0] = 1;
        vRow[i][colunm+1] = 1;
    }

    vector<vector<int>> direV = {{0,1} , {1,0} , {0,-1} , {-1,0}};  // 右下左上
    int direIndex = 0;  // 当前是什么方向
    vector<int> curPos = {1,1}; // 当前是什么坐标
    int num = 0;    // 当前已经走了几步

    // 开始走
    while (num!=row*colunm){
        collectPos.push_back(matrix[curPos[0]-1][curPos[1]-1]); // vRow是比matrix偏移了的
        vRow[curPos[0]][curPos[1]] = 1;
        if(vRow[curPos[0]+direV[direIndex][0]][curPos[1]+direV[direIndex][1]]==0){   // 如果没有到头/碰到为1的话-->用vector还得考虑碰都边界和自身的情况，不如用数组
            curPos[0] += direV[direIndex][0];
            curPos[1] += direV[direIndex][1];
            num++;
        }else{  // 如果需要转弯的话
            direIndex = (direIndex+1)%4;
            curPos[0] += direV[direIndex][0];
            curPos[1] += direV[direIndex][1];
            num++;
        }
    }
    return collectPos;
}

int main(){
    vector<vector<int>> v1 = {{1,2,3} , {4,5,6} , {7,8,9}};

    vector<vector<int>> v2 = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12}};

    vector<int> v1Out = spiralOrder(v1);
    vector<int> v2Out = spiralOrder(v2);

    for (int i = 0; i < v1Out.size(); ++i) {
        cout << v1Out[i] << ",";
    }
    cout << endl;
    for (int i = 0; i < v2Out.size(); ++i) {
        cout << v2Out[i] << ",";
    }

    return 0;
}


