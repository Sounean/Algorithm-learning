// 这题就是对于边际条件的思考多了些：1.系数为1/-1时，不该把1显示出来，2.首位系数负号的隐藏情况，3.系数为0则不显示该项的情况,4.幂为1次时^1不显示
// 纯粹就是考读题和反复根据原先情况根据错误进行修改

// 测试集:n=5, [100, -1, 1, -3, 0, 10]  输出:100x^5-x^4+x^3-3x^2+10
// 测试集:n=3, [-50, 0, 0, 1]   输出:-50x^3+1
// 测试集:n=0, [5]   输出:5
// 测试集:n=1, [-1, 2]   输出:-x+2
// 测试集:n=2, [0, -1, 1]  输出:-x+1

#include <iostream>
using namespace std;
int n=0;
int array[100] = {0};
bool fuhao  = false; // false代表+ ，true代表-,默认代表+
bool coutOne = false; // 有没有输出第一项，因为只有第一项才需要判断是否系数>0，要不要前面加上+号

// 不带符号输出单项
void coutSingle(int xishu,int mi){
    if (xishu!=0){
        if(mi!=n && xishu>0){
            cout << "+";
        }
        if(mi==0){
            cout << xishu;
        }else if(mi==1){
            if(xishu==1 ){
                cout << "x";
            } else if(xishu==-1) {
                cout << "-x";
            }else{
                cout << xishu << "x";
            }
        }else{
            if(xishu==1 ){
                cout << "x^" << mi;
            } else if(xishu==-1) {
                cout << "-x^" << mi;
            }else{
                cout << xishu << "x^" << mi;
            }
        }

    }

    fuhao = !fuhao;
}

int main(){
    cin >> n;
    for(int i=0;i<=n;i++){
        cin >> array[i];
    }

    if(n%2==0)fuhao = true;
    for(int i=0;i<=n;i++){
        coutSingle(array[i] , n-i);
    }

    return 0;
}

