#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int n,r;
int b[30];

// 每次传一个vector进去，不能传地址吧因为传了
void dfs(int startIndex,int select){
    if(select == r){
        for (int i = 0; i < r; ++i) {
            cout << setw(3) << b[i];
        }
        cout<<endl;
        return; // 如果满足了凑齐3个了就结束掉
    }

    for (int i = startIndex; i <= n; ++i) {
        b[select] = i;
        dfs(i + 1, select+1);
    }

}

int main(){
    cin >> n >> r;

    if(r==0){
        return 0;
    }

    // 从第1个数开始，已选了0个数
    dfs(1,0);

    return 0;
}

/*
 * 测试集输入5 0 不进行输出
 * */