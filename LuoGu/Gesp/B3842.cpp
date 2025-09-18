#include "iostream"

using namespace std;

int sno[1500];  // 存储同学报了编号的次数。比如编号0的同学只报了1次，则sno[0]的值为1
int main(){
    int N,M=0;
    cin >> N >> M;
    for (int i=0;i<M;i++) {
        int call = 0;
        cin >> call;
        sno[call]++;
    }

    bool flag = true;   // true表示所有同学都达到，false表示有同学没到达
    for (int i = 0; i < N; ++i) {
        if (sno[i] == 0){
            cout << i << " ";
            flag = false;
        }
    }

    if(flag){
        cout << N;
    }

    return 0;
}
