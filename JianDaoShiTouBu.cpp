#include "iostream"
#include "cstdlib"
#include "ctime"

using namespace std;


int i=0;
// 定义函数
void player(){
    cin >> i;
}

int computer(){
    return 1;
}

// 两数之和
void pd(int a,int b){   // 形参
    cout << a+b;
}

int main() {
    player();   // 调用函数


    int com = computer();

    pd(i,com);  // 实参

    return 0;
}