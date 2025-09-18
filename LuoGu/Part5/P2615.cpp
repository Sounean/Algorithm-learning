#include "iostream"

using namespace std;

int N;
int huanFang[50][50];
int main(){
    cin >> N;
    int currentHanIndex = 0;
    int currentLieIndex = N/2;
    int currentValue = 1;
    huanFang[currentHanIndex][currentLieIndex] = currentValue;

    while (N*N!=currentValue){
        currentValue++;
        if(currentHanIndex == 0 and currentLieIndex!=N-1){
            currentHanIndex = N-1;
            currentLieIndex = currentLieIndex+1;
        }else if(currentLieIndex == N-1 and currentHanIndex != 0){
            currentHanIndex = currentHanIndex-1;
            currentLieIndex = 0;
        }else if(currentHanIndex == 0 and currentLieIndex==N-1){
            currentHanIndex = currentHanIndex+1;
        } else{
            if (huanFang[currentHanIndex-1][currentLieIndex+1]==0){
                // 右上方未填数
                currentHanIndex = currentHanIndex-1;
                currentLieIndex = currentLieIndex+1;
            }else{
                currentHanIndex = currentHanIndex+1;
            }
        }
        huanFang[currentHanIndex][currentLieIndex] = currentValue;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << huanFang[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}