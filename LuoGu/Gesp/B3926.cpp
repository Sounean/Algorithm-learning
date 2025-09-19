#include "iostream"
#include "string"
using namespace std;

int main(){
    int N = 0;
    cin >> N;
    for (int i = 0;i<N;i++) {
        int value1 = 0;
        string danWei1 = "";
        string value2 = "0";
        string fuhao = "=";
        string danWei2 = "";
        cin >> value1 >> danWei1 >> fuhao >>value2 >> danWei2;

        if (danWei1 == "km" && danWei2=="m"){
            cout << value1 << " "<< danWei1 << " = " << value1*1000 << " " << danWei2;
        } else if (danWei1 == "km" && danWei2=="mm"){
            cout << value1 << " "<< danWei1 << " = " << value1*1000000 << " " << danWei2;
        }else if (danWei1 == "m" && danWei2=="mm"){
            cout << value1 << " "<< danWei1 << " = " << value1*1000 << " " << danWei2;
        }else if (danWei1 == "kg" && danWei2=="g"){
            cout << value1 << " "<< danWei1 << " = " << value1*1000 << " " << danWei2;
        } else if (danWei1 == "kg" && danWei2=="mg"){
            cout << value1 << " "<< danWei1 << " = " << value1*1000000 << " " << danWei2;
        }else if (danWei1 == "g" && danWei2=="mg"){
            cout << value1 << " "<< danWei1 << " = " << value1*1000 << " " << danWei2;
        }
        cout << endl;
    }
    return 0;
}
