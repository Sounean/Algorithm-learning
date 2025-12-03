#include "iostream"

using namespace std;

int array1[1500];
int array2[1500];
int main(){
    int N,M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> array1[i];
    }

    int a = array1[0];
    for (int i = 1; i <M ; ++i) {
        if (a==array1[i]){
            continue;
        }else {
            if ((a-array1[i]) == 1) {
                a  = array1[i];
                continue;
            }
            if ((a-array1[i]) >= 2) {
                a  = array1[i];
                array2[i] = array1[i]-1;
            }
        }
    }



    return 0;
}