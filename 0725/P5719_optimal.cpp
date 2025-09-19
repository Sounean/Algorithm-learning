#include <iostream>
#include <iomanip>  // 用于格式化输出
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    // 使用long long避免整数溢出，使用double提高精度
    long long sumA = 0, countA = 0;  // A类数的和与个数
    long long sumB = 0, countB = 0;  // B类数的和与个数
    
    // 遍历1到n的所有数
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            // 能被k整除的数属于A类
            sumA += i;
            countA++;
        } else {
            // 不能被k整除的数属于B类
            sumB += i;
            countB++;
        }
    }
    
    // 计算平均值，使用double确保精度
    double avgA = (countA > 0) ? (double)sumA / countA : 0.0;
    double avgB = (countB > 0) ? (double)sumB / countB : 0.0;
    
    // 使用cout和setprecision输出，更符合C++风格
    cout << fixed << setprecision(1) << avgA << " " << avgB << endl;
    
    return 0;
} 