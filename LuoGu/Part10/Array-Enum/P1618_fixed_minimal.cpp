#include <iostream>
#include <cstring>

using namespace std;

int b[10];
int A,B,C,x,y,z;

void intoArray(int num){
    int baiWei = num/100;
    int shiWei = num/10%10;
    int geWei = num%10;
    b[baiWei] = 1;
    b[shiWei] = 1;
    b[geWei] = 1;
}

bool check(int x,int y,int z){
    // 检查是否都是三位数
    if(x < 100 || x > 999 || y < 100 || y > 999 || z < 100 || z > 999) {
        return false;
    }
    
    // 把每个数字都放到b数组中，判断有没重复的
    memset(b,0, sizeof(b));

    intoArray(x);
    intoArray(y);
    intoArray(z);

    // 检查是否使用了0（题目要求1-9）
    if(b[0] == 1) return false;
    
    for (int i = 1; i <=9 ; ++i) {
        if (b[i]==0){  // 如果有某个位上是0，说明有数字重复了
            return false;
        }
    }
    return true;
}

int main(){

    cin >> A >> B >> C;

    int cnt = 0;
    // 1.遍历可能构成的三位数，通过公式推出另外两个
    for(int x=123;x<=987;x++){
        // 修复：添加更严格的整除性检查
        if(A == 0 || x*B % A != 0 || x*C % A != 0) continue; // 防止除零，确保能整除

        y = x*B/A;
        z = x*C/A;
        
        // 2.检查这三个是否组成每位数字上均不相等
        if(check(x,y,z)){
            cout << x << " " << y << " " << z << endl;
            cnt++;
        }
    }

    if(cnt==0){
        cout << "No!!!";
    }

    return 0;
}

/*
主要修改点：
1. 在check函数中添加了三位数范围检查
2. 添加了对数字0的检查（题目要求使用1-9）
3. 修复了整除性检查的写法（x*B%A改为x*B % A != 0）
4. 添加了防止除零的检查
*/ 