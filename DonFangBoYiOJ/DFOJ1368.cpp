//#include "iostream"
//#include "cmath"
//using namespace std;
//
//// 使用高精度或者long long，但N最大100，斐波那契第100项会超过long long范围
//// 需要使用高精度或者unsigned long long，但更好的方法是使用数组存储大数
//// 这里先用long long测试，如果不够用需要高精度
//
//unsigned long long a[120];
//
//int main(){
//    int M, N;
//    cin >> M >> N;
//
//    // 蜜蜂路线问题：从M到N的路径数 = 斐波那契数列的第(N-M+1)项
//    // 初始化：从M到M只有1种方式（不动），从M到M+1只有1种方式
//    a[M] = 1;
//    if (M + 1 <= N) {
//        a[M + 1] = 1;
//    }
//
//    // 斐波那契递推：a[i] = a[i-1] + a[i-2]
//    // 表示到达位置i的路径数 = 从i-1来的路径数 + 从i-2来的路径数
//    for (int i = M + 2; i <= N; ++i) {
//        a[i] = a[i-1] + a[i-2];
//    }
//
//    cout << a[N];
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;

int a[1005][1005], k = 1;

// 此处因为数字过大，所以采用高进度和去计算
void add(int x){
    for(int i = 0; i < k; i++){
        a[x][i] = a[x-1][i] + a[x-2][i];
    }
    for(int i = 0; i < k; i++){
        if(a[x][i] > 9){
            a[x][i+1] += a[x][i] / 10;
            a[x][i] %= 10;;
        }
    }
    if(a[x][k])k++; // 到目前为止有几位了（两数相加肯定最多增加1位）
}

int main() {
    int m, n;
    cin >> m >> n;
    a[m][0] = 1;
    for(int i = m+1; i <= n; i++){
        add(i);
    }
    for(int i = k-1; i >= 0; i--){
        cout << a[n][i];
    }
    return 0;
}