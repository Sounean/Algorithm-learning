//
// Created by Administrator on 2025/5/29.
//
//#include "iostream"
//#include "string"
////#include "algorithm"
//using namespace std;
//// 若需定义常量，推荐const int maxn = 999; 这是预处理指令，在编译前进行文本替换代码中所有maxn会被直接替换为999
//// 且要注意后面不能带;
//#define maxn 999
//int add1[maxn],add2[maxn];
//int main(){
//    // 分别获取
//    string add1Str,add2Str;
//    cin >> add1Str >> add2Str;
//    int add1StrLen = add1Str.length();
//    int add2StrLen = add2Str.length();
//    // 给短的那位前面补0
//    int maxStrLen = max(add1StrLen , add2StrLen);
//    if(maxStrLen > add2StrLen){
//        add2Str = std::string(add1StrLen - add2StrLen, '0') + add2Str;
//    } else {
//        add1Str = std::string(add2StrLen - add1StrLen, '0') + add1Str;
//    }
//    // 从最后面开始，每位相加，满十进1
//    int finalArray[maxStrLen];
//    bool haveJinWei = false;
//    for (int i = maxStrLen-1; i >=0; --i) {
//        finalArray[maxStrLen-1 -i] = (add1Str[i]-'0') + (add2Str[i]-'0') + haveJinWei;
//        if(finalArray[maxStrLen-1 -i] >= 10){
//            haveJinWei = true;
//            finalArray[maxStrLen-1 -i] = finalArray[maxStrLen-1 -i]-10;
//        }else{
//            haveJinWei = false;
//        }
//    }
//
//    // 遍历反过来，如果最后一位没有满十就不输出最后一位
//    if(haveJinWei){
//        cout << 1;
//    }
//    for(int i = 0;i<maxStrLen;i++){
//        cout << finalArray[i];
//    }
//
//    return 0;
//}

// 碰到输入长串数字并逐位处理的，需要考虑到string获取并将它们拆分放到数组内去，好一位位处理。
#include "iostream"
#include "string"
#include "algorithm"
#define maxn 520
using namespace std;
int a[maxn],b[maxn],c[maxn];
int main(){
    string A,B;
    cin >> A >> B;
    int len = max(A.length(),B.length());
    // 反过来获取了
    for(int i = A.length()-1,j=1;i>=0;i--,j++){
        a[j] = A[i]-'0';
    }
    for(int i = B.length()-1,j=1;i>=0;i--,j++){
        b[j] = B[i]-'0';
    }
    for(int i=1;i<=len;i++){
        c[i] += a[i] + b[i];    // 此处用的是 "+=" 而是不 “=”，所以上一次的进位在这里也有
        c[i+1] = c[i]   / 10;
        c[i] %= 10;
    }
    if(c[len+1]){
        len++;
    }
    for(int i=len;i>=1;i--){
        cout << c[i];
    }
    return 0;
};