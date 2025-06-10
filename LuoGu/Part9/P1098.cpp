//
// Created by Administrator on 2025/5/31.
//
#include <iostream>
using namespace std;

int p1,p2,p3;
string getStr;
string alphaXiaoxieMap = "abcdefghijklmnopqrstuvwxyz";
string alphaDaxieMap = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string numMap = "0123456789";

// 判断字符是数字字符还是字母字符   true:字母，false：数字
bool isAlpha(char c){
    if(c>='0' && c<='9'){
        return false;
    }else{
        return true;
    }
}

void printZhonJiande(char lastChar,char nextChar){
    cout << lastChar;
}

int main(){
    // 1.获得类型
    cin >> p1 >> p2 >> p3;
    getline(cin,getStr);
    // 遍历字符串
    char lastChar;  // 上一个字符
    for(int i=0;i<getStr.length();i++){
        if(getStr[i]!='-'){
            // 2.1如果不是'-‘直接输出
            cout << getStr[i];
            lastChar = getStr[i];
        } else {
            // 2.2如果是'-'，开始考虑格式了
            char nextChar = getStr[i+1];
            if(isAlpha(lastChar)!= isAlpha(nextChar)){
                // 3.1 如果-前后不是一个类型，也直接输出
                cout << '-' << nextChar;
                lastChar = nextChar;
                i++;
                continue;
            } else{
                // 3.2如果是同一个类型的
                // 4.1 判断是不是相同的，相同的或者'-'号左侧的比右侧大，都直接输出
                // 4.2 若'-'号左侧比右侧小，则判断是进行获取和输出 (这部分可以重用，可以做成函数)
                printZhonJiande(lastChar,nextChar);
                i++;    // 因为都处理到’-‘后面的了
                continue;
            }
        }


    }

    return 0;
}