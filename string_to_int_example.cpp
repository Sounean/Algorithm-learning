#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>  // for atoi
#include <cstdio>   // for sscanf
using namespace std;

int main() {
    string str = "986";
    
    // 方法1：使用 stoi()（推荐，C++11标准）
    int num1 = stoi(str);
    cout << "方法1 (stoi): " << num1 << endl;
    
    // 方法2：使用 atoi()（C风格，需要c_str()）
    int num2 = atoi(str.c_str());
    cout << "方法2 (atoi): " << num2 << endl;
    
    // 方法3：使用 stringstream
    stringstream ss(str);
    int num3;
    ss >> num3;
    cout << "方法3 (stringstream): " << num3 << endl;
    
    // 方法4：使用 sscanf()（C风格）
    int num4;
    sscanf(str.c_str(), "%d", &num4);
    cout << "方法4 (sscanf): " << num4 << endl;
    
    // 更多示例
    cout << "\n更多示例：" << endl;
    string test_cases[] = {"123", "0", "-456", "9999"};
    for (string s : test_cases) {
        cout << "\"" << s << "\" -> " << stoi(s) << endl;
    }
    
    // 注意：如果字符串不是纯数字，stoi会抛出异常
    // 可以使用 try-catch 处理
    try {
        string invalid = "abc123";
        int num = stoi(invalid);
        cout << invalid << " -> " << num << endl;
    } catch (const exception& e) {
        cout << "转换失败: " << e.what() << endl;
    }
    
    return 0;
}






