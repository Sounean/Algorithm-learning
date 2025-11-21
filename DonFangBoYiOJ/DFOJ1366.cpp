#include "iostream"
using namespace std;

// 1个封闭分成2个；  2个封闭分成4个；  3个封闭分成8个；  4个封闭分成14
// 认输，发现不了规律；其实也限制了“任意两条曲线只能交两点”,每次多一条曲线后，多出来的区域数量实际上就是新曲线可以被划分的数量。

int a[10020];
int main(){
    int n;
    cin >> n;
    a[1] = 2;
    a[2] = a[1]+2*(2-1);

    for (int i = 2; i <= n; ++i) {
        a[i] = a[i-1]+2*(i-1);
    }

    cout << a[n];
    return 0;
}