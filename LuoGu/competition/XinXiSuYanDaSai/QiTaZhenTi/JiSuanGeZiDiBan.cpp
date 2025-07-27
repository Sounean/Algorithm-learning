#include "iostream"
#include "algorithm"

using namespace std;

int main(){
    int n,m;
    cin >> n>> m;
    int cnt = 0;
    for(int bianChang=1;bianChang<=min(n,m);bianChang++){
        cnt += (n-bianChang+1)*(m-bianChang+1);
    }
    cout << cnt;

    return 0;
}