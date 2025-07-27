#include "iostream"
#include "algorithm"

using namespace std;

struct MuBan{
    int T1; // 维修时间
    int T2; // 损坏时间
}mubans[55000];

bool cmp(MuBan muBan1,MuBan muBan2){
    if(muBan1.T2!=muBan2.T2){
        return muBan1.T2 < muBan2.T2;
    }
    if(muBan1.T1 != muBan2.T1){
        return muBan1.T1 < muBan2.T2;
    }
    return 0;
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> mubans[i].T1 >> mubans[i].T2;
    }
    sort(mubans , mubans+N, cmp);

    int S = 0;
    int timeSum = 0;    // 当前消耗的总时间
    for (int i = 0; i < N; ++i) {
        if(timeSum+mubans[i].T1 > mubans[i].T2){
            break;
        }
        timeSum+=mubans[i].T1;
        S++;
    }
    cout << S;

    return 0;
}