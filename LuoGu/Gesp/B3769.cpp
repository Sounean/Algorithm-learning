#include "iostream"
#include "string"
using namespace std;

int main(){
    string s = "";
    getline(cin , s);
    string t = "";
    getline(cin , t);
    int q = 0;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        int l1,r1,l2,r2 = 0;
        cin >> l1 >> r1 >> l2 >> r2;
        string newS = s.substr(l1-1,r1-l1);
        string newT = t.substr(l2-1,r2-l2);
        if (newS <newT){
            cout << "yifusuyi"<<endl;
        } else if(newS == newT){
            cout << "ovo"<<endl;
        } else{
            cout << "erfusuer"<<endl;
        }
    }


    return 0;
}
