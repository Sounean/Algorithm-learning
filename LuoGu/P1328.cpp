#include <iostream>

using namespace std;
// 下方带a的是甲，b的是乙
int N,Na,Nb=1;    // N：游戏进行的轮次,Na：A的周期,Nb:B的周期
int ScoreA,ScoreB;  // A和B的成绩
int main(){
    // 游戏结构二维表
    int a[5][5] = {{0,-1,1,1,-1},
                   {0,0,-1,1,-1},
                   {0,0,0,-1,1},
                   {0,0,0,0,1},
                   {0,0,0,0,0}};

    cin >> N >> Na >> Nb;
    int NaList[Na+2];
    int NbList[Nb+2];

    // 获取输入的出拳周期
    for(int i=0;i<Na;i++){
        cin >> NaList[i];
    }
    for(int i=0;i<Nb;i++){
        cin >> NbList[i];
    }

    int asdf = 111;
    for (int i = 0; i < N; ++i) {
        int currentNa = NaList[i%Na];// 出的拳
        int currentNb = NbList[i%Nb];
        if(currentNa>currentNb){
            if(a[currentNb][currentNa]==-1){
                ScoreA++;
//                cout << "time:" << i << "ScoreA:" << ScoreA << ",now A:" << currentNa << ",now B:" << currentNb<< endl;
            } else if(a[currentNb][currentNa]==1){
                ScoreB++;
//                cout << "time:" << i << "ScoreB:" << ScoreB  << ",now A:" << currentNa << ",now B:" << currentNb<<  endl;
            } else{
//                cout << "time:" << i  << ",now A:" << currentNa << ",now B:" << currentNb<<  endl;
            }
        } else{
            if(a[currentNa][currentNb]==1){
                ScoreA++;
//                cout << "time:" << i << "ScoreA:" << ScoreA  << ",now A:" << currentNa << ",now B:" << currentNb<<  endl;
            } else if(a[currentNa][currentNb]==-1){
                ScoreB++;
//                cout << "time:" << i << "ScoreB:" << ScoreB  << ",now A:" << currentNa << ",now B:" << currentNb<<  endl;
            }else{
//                cout << "time:" << i  << ",now A:" << currentNa << ",now B:" << currentNb<<  endl;
            }
        }
    }

    cout << ScoreA << " " << ScoreB;

    return 0;
}

