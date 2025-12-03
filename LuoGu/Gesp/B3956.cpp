#include "iostream"
#include "string"
using namespace std;

int main(){
    int n=0;
    cin >> n;
    string str = "";
    cin >> str;

    int sum = 0;
    for (int i=0;i<str.length();i++) {
        char  ch = str[i];
        if (ch>='a' && ch<='z'){
            //说明是小写a~z
            sum += (ch-'a'+1);
        } else if(ch>='A' && ch<='Z'){
            sum += (-1*ch);
        }
    }

    cout << sum;

    return 0;
}
