#include<iostream>
using namespace std;
int con[2000000];

int main(){
    int n;
    cin>>n;
    double a;  // 记住，有小数部分，可以用double就不用float
    int t;
    int i,j;
    for(i=1;i<=n;i++){
        cin>>a>>t;
        for(j=1;j<=t;j++){
            //按一下开关，状态（0或1）就改变一次
            if(con[int(a*j)]==1)	con[int(a*j)]=0;
            else con[int(a*j)]=1;
        }

    }
    for(i=1;;i++){
        if(con[i]==1) {
            cout<<i;
            break;
        }
    }
}