#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 简单测试：计算1到100的和的平均值
    float sum_float = 0;
    double sum_double = 0;
    
    for (int i = 1; i <= 100; i++) {
        sum_float += i;
        sum_double += i;
    }
    
    float avg_float = sum_float / 100;
    double avg_double = sum_double / 100;
    
    cout << "1到100的平均值：" << endl;
    cout << "float: " << fixed << setprecision(10) << avg_float << endl;
    cout << "double: " << avg_double << endl;
    cout << "理论值: 50.5" << endl;
    
    return 0;
} 