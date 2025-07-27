#include <iostream>
using namespace std;

int main() {
    int s;
    cin >> s;
    
    // 时间转换：秒转换为小时
    // 1小时 = 3600秒
    int hours = s / 3600;
    
    cout << hours << endl;
    
    return 0;
} 