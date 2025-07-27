#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    // 统计n个传感器数据中的有效信号数字之和
    // 有效信号：某一位是3的倍数的数字（0, 3, 6, 9）
    
    int totalSum = 0;
    
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        
        // 检查数据的每一位数字
        int temp = data;
        while (temp > 0) {
            int digit = temp % 10;  // 取出最后一位数字
            
            // 如果这一位是3的倍数（0, 3, 6, 9），则加入总和
            if (digit % 3 == 0) {
                totalSum += digit;
            }
            
            temp /= 10;  // 去掉最后一位
        }
    }
    
    cout << totalSum << endl;
    
    return 0;
} 