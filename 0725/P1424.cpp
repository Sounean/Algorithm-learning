//
// Created by Administrator on 2025/7/25.
//
#include "iostream"

using namespace std;

int preWeek(int x,int n){
    // 计算前一周的工作日天数，x是当前周几，n是当前周的工作日天数
    // endDay代表前一周的最后一天
   if (x > 5) return 0;  // 从周末开始
   int endDay = x + n - 1;
   if (endDay <= 5) return n;  // 都在工作日
   return 6 - x;  // 到周五为止
}

int lastWeek(int x,int n){
    // startDay代表最后一周的周几
    int startDay = (x + n - 1) % 7; 
    if (startDay == 0) startDay = 7;    // 当最后一天是周日时
    if (startDay > 5) return 0;    // 当最后一天是周末时
    return startDay;    // 返回最后一周的工作日天数
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
//        cout << preWeek(x,8-x) << " " <<  ((x+n)/7 - 1) * 5 << " " << lastWeek(x,n);
        cout << preCount+middleCount+lastCount;
    }

    return 0;
}