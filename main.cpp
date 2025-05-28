#include <bits/stdc++.h>
using namespace std;

int fun(int n){
    if(n == 1){
        return 1;
    } else {
        return fun(n-1)+3;
    }
}

int main() {
    for(int i = 1;i <= 10;i++){
        cout << fun(i) << endl;
    }
    return 0;
}
