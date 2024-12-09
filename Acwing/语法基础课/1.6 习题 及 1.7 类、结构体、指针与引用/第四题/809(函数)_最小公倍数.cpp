//
// Created by Administrator on 2024/12/9.
//
#include <iostream>

using namespace std;

// 思路：大小范围肯定是1到a*b为止  （从1开始找一直找到a*b,找到能被a和b整除的即可）

int lcm(int a,int b){
    for ( int i=1;i<=a*b;i++){
        if(i % a == 0 && i % b == 0){
            return i;
        }
    }
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d", lcm(x,y));
    return 0;
}