#include "iostream"

using namespace std;
int main(){
    int a = 1;
    cin >> a;
    for(int i=0;i<9;i++){
        a+=i;
    }

    cout << a;


    return 0;
}
