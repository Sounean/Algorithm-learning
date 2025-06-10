#include <iostream>
#include <cstring>  // 要清空b数组，得用memset函数，需要先导入cstring库

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
    // 把每个数字都放到b数组中，判断有没重复的
    memset(b,0, sizeof(b));

    intoArray(x);
    intoArray(y);
    intoArray(z);

    for (int i = 1; i <=9 ; ++i) {
        if (b[i]==0){  // 如果有某个位上是0，说明有数字重复了
            return false;
        }
    }
    return true;
}

int main(){

    cin >> A >> B >> C;

    if(A*B*C==0){
        cout << "No!!!";
        return 0;
    }

    int cnt = 0;
    // 1.遍历可能构成的三位数，通过公式推出另外两个
    for(int x=123;x<=987;x++){
        if(x*B%A || x*C%A)continue; // 没法组成比例，跳过

        y = x*B/A;
        z = x*C/A;
        // 2.检查这三个是否组成每位数字上均不相等  （该怎么实现，每位拆出来对比? 放到数组里，然后下次放的时候先判断，为1则重复了，则停止）
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
 * 测试集再加个 “0 1 2”   可能导致RE！！
 * */