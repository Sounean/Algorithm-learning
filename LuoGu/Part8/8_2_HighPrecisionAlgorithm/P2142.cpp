#include "iostream"
#include "string"
#include "algorithm"
#define maxn 10099   // 题目中要求10的10086次方了，这里也得改更大
using namespace std;
int max_arr[maxn],min_arr[maxn],c[maxn];
int maxLenth,finalLength;   // maxLenth:两者中更长的,finalLength:最后计算出来的差的长度

// 两个输入的比较大小，如果一样大返回false，程序结束
int judgeBig(string A,string B,int* max_arr,int* min_arr){
    int  same = 0;  // 0表示一样大，1代表A是更大的，2代表B是更大的
    int aLength = A.length();
    int bLength = B.length();
    if(aLength>bLength){
        same = 1;
        maxLenth = aLength;
        for(int i = A.length()-1,j=1;i>=0;i--,j++){
            max_arr[j] = A[i]-'0';
        }
        for(int i = B.length()-1,j=1;i>=0;i--,j++){
            min_arr[j] = B[i]-'0';
        }

    } else if (aLength<bLength){
        same = 2;
        maxLenth = bLength;
        for(int i = A.length()-1,j=1;i>=0;i--,j++){
            min_arr[j] = A[i]-'0';
        }
        for(int i = B.length()-1,j=1;i>=0;i--,j++){
            max_arr[j] = B[i]-'0';
        }

    } else{

        for(int i = A.length()-1,j=1;i>=0;i--,j++){
            if(same==0){
                if(A[i] == B[i]){
                    min_arr[j] = max_arr[j] = A[i]-'0';
                } else if(A[i]>B[i]){
                    same = 1;
                    maxLenth = aLength;
                    max_arr[j] = A[i]-'0';
                    min_arr[j] = B[i]-'0';
                } else{
                    same = 2;
                    maxLenth = bLength;
                    min_arr[j] = A[i]-'0';
                    max_arr[j] = B[i]-'0';
                }
            }else if(same==1){
                max_arr[j] = A[i]-'0';
                min_arr[j] = B[i]-'0';
            }else if(same==2){
                min_arr[j] = A[i]-'0';
                max_arr[j] = B[i]-'0';
            }
        }
    }
    return same;
}
int main(){
    string A,B;
    cin >> A >> B;
    int sameBig = judgeBig(A,B,max_arr,min_arr);
    if(sameBig == 0){
        cout << 0;
    }else{
        if(sameBig == 2){
            cout<< '-';
        }
        for(int i=1;i<=maxLenth;i++){
            if(max_arr[i]<min_arr[i]){
                c[i] = max_arr[i] + 10- min_arr[i];
                if(c[i]!=0)finalLength = i;
                max_arr[i+1]-=1;
            } else{
                c[i] = max_arr[i] - min_arr[i];
                if(c[i]!=0)finalLength = i;
            }
        }
    }
    for(int i=finalLength;i>=1;i--){
        cout << c[i];
    }
    return 0;
};
