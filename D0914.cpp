#include <cstring>
#include "iostream"
#include "string"
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 65; i < 92; i++) {
        char a = i + n;
        if (i+n>91) {
            a -= 27;
        }
        if (a=='[') {
            cout << "" ;
        }
        else {
            cout  << a << "" ;
        }
    }

    

    return 0;
}