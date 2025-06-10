#include <iostream>
using namespace std;

// 计算阶乘
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    // 按照题目描述：第一行是m和n，第二行是各种书的数量
    int m, n;
    cin >> m >> n;

    int books[20];
    int total = 0;

    // 读取m种书的数量
    for (int i = 0; i < m; i++) {
        cin >> books[i];
        total += books[i];
    }

    // 计算多重排列：total! / (books[0]! * books[1]! * ... * books[m-1]!)
    long long result = factorial(total);

    for (int i = 0; i < m; i++) {
        result /= factorial(books[i]);
    }

    cout << result << endl;

    return 0;
}