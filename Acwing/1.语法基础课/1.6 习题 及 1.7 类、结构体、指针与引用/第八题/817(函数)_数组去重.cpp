//
// Created by Administrator on 2024/12/9.
//
#include <iostream>

using namespace std;

int unique(int a[],int size){
    int cnt = 0;
    for(int i =0;i<size;i++ ){
        bool haveRepeat = false;
        for(int j=0;j<i;j++){   // 表示数据从头找到他自己看下有么有重复的
            if(a[i] == a[j]){
                haveRepeat = true;
                break;
            }
        }
        if(!haveRepeat)cnt++;
    }
    return cnt;
}

int main(){
    int n,size;
    int a[100];

    cin >> n >> size;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int repeatNum = unique(a,size);
    cout << n-size+repeatNum;

    return 0;
}