//
// Created by Administrator on 2024/12/10.
//
#include <iostream>
using namespace std;

void sort(int a[],int l,int r){
    // 此处用的是选择排序
    for(int i=l;i<=r;i++){
        for(int j=l+1;j<=r;j++){
            if(a[i]>a[j])swap(a[i],a[j]);
        }
    }
}

int main(){
    int n,l,r;
    int a[1000];

    cin >> n >> l >> r;
    for(int i =0;i<n;i++){
        cin >> a[i];
    }

    sort(a,l,r);

    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }

    return 0;
}