#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 测试用例：n=100, k=16
    int n = 100, k = 16;
    
    // 使用float计算
    float sumA_float = 0, countA_float = 0;
    float sumB_float = 0, countB_float = 0;
    
    // 使用double计算
    double sumA_double = 0, countA_double = 0;
    double sumB_double = 0, countB_double = 0;
    
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            sumA_float += i;
            countA_float++;
            sumA_double += i;
            countA_double++;
        } else {
            sumB_float += i;
            countB_float++;
            sumB_double += i;
            countB_double++;
        }
    }
    
    float avgA_float = sumA_float / countA_float;
    float avgB_float = sumB_float / countB_float;
    
    double avgA_double = sumA_double / countA_double;
    double avgB_double = sumB_double / countB_double;
    
    cout << "使用float的结果：" << endl;
    cout << fixed << setprecision(10) << "A类平均数: " << avgA_float << endl;
    cout << "B类平均数: " << avgB_float << endl;
    
    cout << "\n使用double的结果：" << endl;
    cout << "A类平均数: " << avgA_double << endl;
    cout << "B类平均数: " << avgB_double << endl;
    
    cout << "\n期望结果：" << endl;
    cout << "A类平均数: 56.0" << endl;
    cout << "B类平均数: 50.1" << endl;
    
    return 0;
} 