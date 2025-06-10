//#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
    int z;
};

bool cmp(Point p1,Point p2){
    return p1.z>p2.z;
}

double getJuLi(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) + (p1.z-p2.z)*(p1.z-p2.z));
}

int N;
double juLi;
int main(){
    // 就是单纯给这个排序后，每个距离加起来
    cin >> N;
    Point points[N+2];
    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y >> points[i].z;
    }

    sort(points , points + N , cmp);

    for (int i = 0; i < N - 1; ++i) {
        juLi += getJuLi(points[i],points[i+1]);
    }

    printf("%.3f" , juLi);

    return 0;
}
