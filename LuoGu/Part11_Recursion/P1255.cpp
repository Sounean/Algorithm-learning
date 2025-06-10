#include <iostream>

using namespace std;


int N;
int zouLouTi(int currentLouTi){
    if(currentLouTi>2){
        return zouLouTi(currentLouTi-1)+ zouLouTi(currentLouTi-2);
    }
    if(currentLouTi == 2){
        return 2;
    } else if(currentLouTi == 1){
        return 1;
    }

}

int main(){
    cin >> N;

    int num = zouLouTi(N);

    cout << num;

    return 0;
}
