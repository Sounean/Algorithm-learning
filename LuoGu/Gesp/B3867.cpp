#include "iostream"

using namespace std;

int a[1500];
int main(){
    int N,D = 0;
    cin >> N >> D;
    for (int i=0;i<D;i++) {
        // i+1 代表第几天,也代表那天放了多少元；value代表是放在哪个罐子中
        int value = 0;
        cin >> value;
        a[value] += (i+1);
    }

    for (int i=0;i<N;i++) {
        cout << a[i] << " ";
    }
    return 0;
}
