#include "iostream"
using namespace std;

int n;
long long a[110];
int main(){
    // 单独的每层数量：索引0：第一层：1 索引1：第二层：1+2=3  第三层1+2+3=6  第四层：1+2+3+4=10

    // 归纳--> A(n) = A(n-1)+n+1
    cin >> n;
    a[0] = 1;
    for (int i = 1; i < n; ++i) {
        // 总数量 =  当前层数量+上面的所有数量   --》当前层数量=上一层单层数量+当前层数
        a[i] = a[i-1] + (i+1);
    }
//    cout << a[n-1];

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }

    cout << sum;
    return 0;

}
