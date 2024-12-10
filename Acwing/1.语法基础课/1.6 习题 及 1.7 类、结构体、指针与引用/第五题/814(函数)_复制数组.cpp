//
// Created by Administrator on 2024/12/9.
//
#include <iostream>

using namespace std;

const int N = 110;

void copy(int a[],int b[],int size){
    for (int i=0;i<size;i++){
        b[i] = a[i];
    }
}

int main(){
    int n,m,size;
    int a[N],b[N];
    cin >> n >> m >> size;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        cin >> b[i];
    }

    copy(a,b,size);
//    cout << b;    // 只会输出0x71e63ff590 地址值
    for(int i=0;i<m;i++){
        cout << b[i] << " ";
    }
    return 0;
}