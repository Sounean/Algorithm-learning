//
// Created by Administrator on 2024/12/9.
//
#include <iostream>

using namespace std;

void reverse(int a[],int size){
    for(int i=0,j=size-1;i<j;i++,j--){
        swap(a[i],a[j]);
    }

}

int main(){
    int a[100];
    int n,size;

    cin >> n >> size;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    reverse(a,size);

    for(int i=0;i<n;i++) {
        cout << i << " ";
    }

    return 0;
}