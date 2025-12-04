#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    map<string, int> myMap;
    myMap["apple"] = 10;
    myMap["banana"] = 20;
    
    // ========== 获取不存在的key的几种情况 ==========
    
    // 方法1：使用 [] 操作符（不推荐用于检查）
    // 注意：如果key不存在，会自动创建该key，值为0（默认值）
    cout << "方法1 - []操作符:" << endl;
    cout << myMap["orange"] << endl;  // 输出: 0，但会创建 "orange"=0 这个键值对
    cout << "map大小: " << myMap.size() << endl;  // 现在有3个元素了！
    
    // 方法2：使用 at() 函数（推荐，安全）
    // 如果key不存在，会抛出异常
    cout << "\n方法2 - at()函数:" << endl;
    try {
        cout << myMap.at("grape") << endl;  // 会抛出异常
    } catch (const exception& e) {
        cout << "key不存在，抛出异常" << endl;
    }
    
    // 方法3：使用 find() 函数（最推荐，最安全）
    cout << "\n方法3 - find()函数:" << endl;
    auto it = myMap.find("pear");
    if (it != myMap.end()) {
        cout << "找到: " << it->second << endl;
    } else {
        cout << "key不存在" << endl;
    }
    
    // 方法4：使用 count() 函数检查是否存在
    cout << "\n方法4 - count()函数:" << endl;
    if (myMap.count("apple") > 0) {
        cout << "apple存在: " << myMap["apple"] << endl;
    } else {
        cout << "apple不存在" << endl;
    }
    
    if (myMap.count("watermelon") > 0) {
        cout << "watermelon存在" << endl;
    } else {
        cout << "watermelon不存在" << endl;
    }
    
    return 0;
}
