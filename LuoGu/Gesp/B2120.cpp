#include "iostream"
#include "string"
using namespace std;

int main(){
    string str = "";
    getline(cin ,str);

    int lianxuLength = 0;
    bool  flag = true;  // 是否是第一个长度输出，是的话前面不加逗号
    for (int i = 0; i < str.length(); ++i) {
        if (str[i]!= ' '){
            lianxuLength++;
        } else{
            if (flag){
                cout << lianxuLength;
                flag = false;
            } else if(lianxuLength!=0){
                cout << "," << lianxuLength;
            }
            lianxuLength = 0;
        }
    }

    // 处理最后个字符串的长度还没被打印的问题
    if (lianxuLength!=0){
        if(flag){
            cout << lianxuLength;
        } else{
            cout << "," << lianxuLength;
        }
    }

    return 0;
}