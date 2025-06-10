#include <iostream>
using namespace std;

int main() {
    int year;
    cin >> year;
    
    // 闰年判断规则：
    // 1. 能被4整除但不能被100整除的年份是闰年
    // 2. 能被400整除的年份是闰年
    // 简化：(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
    
    // 根据题目要求：输出距离当前年份最近的上一闰年
    // 如果当前年份是闰年，则直接输出该年份
    
    // 判断是否为闰年的函数
    auto isLeapYear = [](int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    };
    
    // 如果当前年份是闰年，直接输出
    if (isLeapYear(year)) {
        cout << year << endl;
    }
    else {
        // 否则向前查找最近的闰年
        for (int i = year - 1; i >= 1; i--) {
            if (isLeapYear(i)) {
                cout << i << endl;
                break;
            }
        }
    }
    
    return 0;
} 