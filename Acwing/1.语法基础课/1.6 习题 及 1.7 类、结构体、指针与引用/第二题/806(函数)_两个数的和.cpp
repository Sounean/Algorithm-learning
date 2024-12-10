//
// Created by Sounean on 2024/12/8.
//
// 因为要用到精确到几位小数，这样的话就用cstdio库比较方便
#include <cstdio>

double add(double x,double y){
    return x + y;
}

int main(){
    double x,y;
    scanf("%lf%lf",&x,&y);
    printf("%.2lf", add(x,y));
    return 0;
}
