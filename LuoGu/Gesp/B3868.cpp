#include "iostream"
#include "string"

using namespace std;

int main(){
    int N;
    cin >> N;
    for (int i=0;i<N;i++) {
        int a[6] = {1,1,1,1};   // 一开始都默认可以，如果出现不合规的，就设成0
        string str = "";
        cin >> str;
        for (int k=0;k<str.length();k++) {
            // 不符合二进制
            if (str[k]!='0' && str[k]!='1'){
                a[0] = 0;
            }

            // 不符合八进制
            if (str[k]<'0' || str[k]>'7'){
                a[1] = 0;
            }

            // 不符合十进制
            if (str[k]<'0' || str[k]>'9'){
                a[2] = 0;
            }

            // 不符合十六进制 0~9 A~F
            if (str[k]<'0' || (str[k]>'9' && str[k]<'A') || str[k]>'F'){
                a[3] = 0;
            }
        }
        for (int i=0;i<4;i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
