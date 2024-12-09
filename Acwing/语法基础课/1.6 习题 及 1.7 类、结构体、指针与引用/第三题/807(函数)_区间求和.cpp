//
// Created by Sounean on 2024/12/9.
//
// 因为要用到精确到几位小数，这样的话就用cstdio库比较方便
#include <cstdio>

int sum(int l,int r){
    int sum = 0;
    for (int i=l;i<=r;i++){
        sum+=i;
        printf("此时的sum%d ,i:%d",sum,i);
    }
    return sum;
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    printf("%d %d",x,y);
    printf("%d", sum(x,y));
    return 0;
}