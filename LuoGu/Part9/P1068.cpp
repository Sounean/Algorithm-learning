#include <iostream>
#include <algorithm>

using namespace std;

struct Bean{
    int k;
    int s;
}beans[18000];

int N,m;

bool cmp(Bean b1, Bean b2){
    if(b1.s!=b2.s) return b1.s>b2.s;

    return b1.k<b2.k;
}

int main(){
    cin >> N >> m;
    for(int i=0; i < N; i++){
        cin >> beans[i].k >> beans[i].s;
    }

    sort(beans, beans + N, cmp);

    m = static_cast<int>(m*1.5);

    while ((m-1)+1 < N && beans[(m - 1) + 1].s == beans[(m - 1)].s)m++;


    cout << beans[m-1].s << " " << m << endl;

    for (int i = 0; i < m; ++i) {
        cout << beans[i].k << " " <<beans[i].s << endl;
    }

    return 0;
}
