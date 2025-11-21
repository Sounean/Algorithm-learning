#include <iostream>
using namespace std;

// 原代码逻辑
int original(int n) {
    if(n==1||n==2){
        return 1;
    }
    int y = 1;
    int z = 1;
    for (int i = 2; i < n; ++i) {
        int x = y;
        y = z;
        z = x+y;
    }
    return z;
}

// 正确的斐波那契数列（从F(1)=1, F(2)=1开始）
int correct(int n) {
    if(n <= 0) return 0;  // 处理边界情况
    if(n==1||n==2){
        return 1;
    }
    int y = 1;
    int z = 1;
    for (int i = 2; i < n; ++i) {
        int x = y;
        y = z;
        z = x+y;
    }
    return z;
}

int main() {
    cout << "测试用例对比：" << endl;
    for(int n = 0; n <= 10; n++) {
        int orig = original(n);
        int corr = correct(n);
        cout << "n=" << n << ": 原代码=" << orig << ", 正确值=" << corr;
        if(orig != corr) {
            cout << " ❌ 错误！";
        } else {
            cout << " ✓";
        }
        cout << endl;
    }
    return 0;
}

