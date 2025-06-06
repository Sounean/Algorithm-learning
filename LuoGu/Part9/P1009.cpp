#include "iostream"

using namespace std;
int S,n;
// 这题等留到后面
// 数字小可以这么做，数字大就不行了
int main(){
    cin >> n;
    int tmp = 1;
    // 将本次的！结果存下来
    for(int i=1;i<=n;i++){
        tmp = tmp*i;
        S += tmp;
    }
    cout << S;
    return 0;
}
