#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a1,int a2){
    return a1<a2;
}

int main(){
    int n;
    cin >> n;

    // 使用固定大小数组避免变长数组问题
    int getNums[n+2];
    int chaNums[n+2];

    // 边界情况：n=1时直接输出Jolly    (重点是这个)
    if(n == 1){
        cout << "Jolly" << endl;
        return 0;
    }
    
    // 读取所有输入数据
    for (int i = 0; i < n; ++i) {
        cin >> getNums[i];
        // 计算相邻元素差值
        if(i!=0){
            chaNums[i] = abs(getNums[i] - getNums[i-1]);
        }
    }

    sort(chaNums+1 , (chaNums+1)+(n-1) , cmp);

    bool flag = false;
    for (int i = 1; i <= n-1; ++i) {
        if (chaNums[i]!=i){
            cout << "Not jolly" << endl;
            flag = true;
            break;
        }
    }

    if(!flag) cout << "Jolly" << endl;

    return 0;
}

/*
 * 测试集：
 * 输入： 1 42  输出:Jolly
 * 输入： 4 1 4 2 3  输出:Jolly  
 * 输入： 3 1 3 2  输出:Not jolly
 * */