#include <iostream>
#include <algorithm>

using namespace std;

int N,B;

bool cmp(int cow1,int cow2){
    return cow1>cow2;
}

int main(){
    cin >> N >> B;
    int cows[N+2];
    // 先排序降序，然后从头加到尾，看要多少才可以满足
    for (int i = 0; i < N; ++i) {
        cin >> cows[i];
    }
    sort(cows,cows+N,cmp);
    int cnt = 0;
    while (1){
        B-=cows[cnt];
        cnt++;
        if (B<=0)break;
    }
    cout << cnt;
    return 0;
}