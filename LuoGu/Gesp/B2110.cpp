#include "iostream"
#include "string"
using namespace std;

int count[30] = {0};    // 用来存储26字母出现的次数
int main(){
    string str = "";
    getline(cin ,str);

    // 遍历输入的字母，获取字母出现的次数
    for(int i=0;i<str.length();i++){
        count[str[i] - 'a']++;
    }

    bool flag = false;
    // 遍历数组去查找第一个出现次数为1的
    for (int i=0;i<26;i++) {
        if (count[i] == 1){
            flag = true;
            char ch = 'a' + i;
            cout << ch;
            break;
        }
    }

    if (!flag){
        cout << "no";
    }

    return 0;
}
