// 这题还一个小坑在，系数最高项隐藏条件其实就是不为0
// 对每个项拆分，然后对每个项从左边即符号开始，到系数，到x到幂进行分类讨论:
//1.当i不等于n并且输入的数是正数,输出"+"
//2.当i不等于0且输入的数是-1,输出"-"
//3.输入的数的绝对值大于1或者当前i=0，输出输入的数   （因为如果是+-1，这个1都是隐藏的）
//4.当i>1，输出x^和i
//5.当i=1，输出x
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int n;
    cin>>n;
    for(int i=n;i>=0;i--){//注意，循环要从大到小
        int x;
        cin>>x;
        if(x){
            // 符号部分
            if(i!=n&&x>0)
                cout<<'+';
            if(i!=0&&x==-1)
                cout<<'-';
            // 系数部分
            if(abs(x)>1||i==0)
                cout<<x;
            // x和幂部分
            if(i>1)
                cout<<"x^"<<i;
            if(i==1)
                cout<<'x';
        }
    }
    return 0;
}
