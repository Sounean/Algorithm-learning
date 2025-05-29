//
// Created by Administrator on 2025/5/29.
//
#include "iostream"
#include "string"
#include "algorithm"
#define maxn 4001
using namespace std;
int a[maxn],b[maxn],c[maxn];    // a存位数更长的那个
int main(){
    string A,B;
    cin >> A >> B;

    // 处理输入为0的特殊情况
    if (A == "0" || B == "0") {
        cout << 0;
        return 0;
    }

    int len = max(A.length(),B.length());
    int lessLength = -1;
    int moreLength = -1;
    // 反过来获取了
    // 用更长的放在上面
    if(A.length()>B.length()){
        lessLength = B.length();
        moreLength = A.length();
        for(int i = A.length()-1,j=1;i>=0;i--,j++){
            a[j] = A[i]-'0';
        }
        for(int i = B.length()-1,j=1;i>=0;i--,j++){
            b[j] = B[i]-'0';
        }
    }else{
        lessLength = A.length();
        moreLength = B.length();
        // b和a都从1位开始存,是和输入的是反过来的
        for(int i = A.length()-1,j=1;i>=0;i--,j++){
            b[j] = A[i]-'0';
        }
        for(int i = B.length()-1,j=1;i>=0;i--,j++){
            a[j] = B[i]-'0';
        }
    }
//    cout << a << ";" << b;

    for(int j=1;j<=lessLength;j++){
        for(int i=1;i<=moreLength;i++){
//            c[i] += b[j]*a[i];    // 这样的话乘积后的位数是有问题的
//            c[i+1] = c[i]/10;
//            c[i] = c[i]%10;
            c[i+j-1] += a[i] * b[j];  // 正确位置：i+j-1
            c[i+j] += c[i+j-1] / 10;  // 累加进位
            c[i+j-1] %= 10;
        }
    }
    // 笨一点的就是往后面找短的位，有出现不是0的，则给长度加上去
    int CLength = moreLength;
    for(int i=lessLength;i>0;i--){
        if(c[len+i]!=0){
            CLength+=i;
            break;
        }
    }

    for(int i=CLength;i>=1;i--){
        cout << c[i];
    }
    return 0;
}
