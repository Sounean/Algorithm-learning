//
// Created by Administrator on 2025/7/25.
//
#include "iostream"

using namespace std;

int preWeek(int x,int n){
    if(x>5){
        return 0;
    } else{
        if(x+n < 6){
            return n;
        } else{
            return x+n - ((x+n)%5) - (x-1);
        }
    }
}

int lastWeek(int x,int n){
    int lastDays = (x+n)%7;
    if(lastDays<6){
        return lastDays;
    } else{
        return 5;
    }
}

int main(){
    int x,n;
    cin >> x >> n;

    if(x+n<8){
        cout << preWeek(x,n)*250;
    } else{
        int preCount = preWeek(x,8-x)*250;
        int middleCount = ((x+n)/7 - 1) * 5 *250;
        int lastCount = lastWeek(x,n) * 250;
        cout << preCount+middleCount+lastCount;
    }

    return 0;
}