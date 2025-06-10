#include "iostream"
#include "algorithm"
using namespace std;

int main(){
    int n;
    cin >> n;
    int cnt = 0;    // 总桃数
    int j = 1;  // 具体那天所摘的桃的数量

    for (int i = 1; i <=n ; ) {
        int k = j;

        // 接下来k天都是摘固定数量的桃
        while (k>0){
            cnt+=j;
            k--;
            ++i;
            if(i > n){
                break;
            }
        }

        j++;
    }

    cout << cnt;
    

    return 0;
}
