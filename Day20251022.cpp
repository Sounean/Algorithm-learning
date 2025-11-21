#include "iostream"
using namespace std;

int twoNumSum(int,int); // 函数的声明

int main(){
    int a=2;
    int b=3;
    cout << twoNumSum(a,b); // 调用函数
    return 0;
}

// 函数的定义
int twoNumSum(int a1,int b1){
    return a1+b1;
}