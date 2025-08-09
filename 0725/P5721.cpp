//
// Created by Administrator on 2025/7/30.
//
#include "iostream"

using namespace std;

int main(){
    int n=0, flag=1;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i; j++){   // 里面这个代表每行应该有多少个数字，推理就是最下面那个1个数字的话，那么有几行，最上面那个就有多少个数字
            printf("%02d", flag);
            flag++;
        }
        printf("\n");
    }
    return 0;
}

