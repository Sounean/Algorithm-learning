//
// Created by Sounean on 2024/12/8.
//
#include <iostream>
using namespace std;


int abs(int x){
    if(x > 0) return x;
    else return -x;
}
int main(){
    int x;
    cin>>x;
    cout << abs(x) ;
    return 0;
}