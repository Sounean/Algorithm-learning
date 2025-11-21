#include "iostream"
using namespace std;

int a[12];
int main(){
    a[9] = 1;
    // a[9] = a[8]/2-1 --> a[8] = (a[9]+1)*2   --> a[i] = (a[i+1]+1)*2
    for (int i = 8; i >=0 ; i--) {
        a[i] = (a[i+1]+1)*2;
    }
    cout << a[0];

    return 0;
}