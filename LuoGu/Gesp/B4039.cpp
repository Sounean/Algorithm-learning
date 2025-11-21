#include "iostream"

using namespace std;

// 比较这个字符串是否是回文数
bool judgetHuiWen(string str){
    string strNew = "";
    for (int i=str.length()-1;i>=0;i--) {
        strNew+=str[i];
    }

    if (strNew == str){
        return true;
    } else{
        return false;
    }
}

int main(){
    int n = 0;
    cin >> n;

    for (int i=0;i<n;i++) {
        string str = "";
        cin >> str;

        if (str.length() < 4){
            cout << "No"<< endl;
            continue;
        }
        

        string leftStr = "";    // 左侧的子字符串
        string rightStr = "";      // 右侧的子字符串
        bool flag = false;   // false代表遍历完了还没出现两侧均是回文数的情况
        for (int leftLength=2;leftLength<str.length()-1;leftLength++) {
            leftStr = str.substr(0 , leftLength);
            rightStr = str.substr(leftLength,str.length()-leftLength);
            if (judgetHuiWen(leftStr) && judgetHuiWen(rightStr)){
                flag = true;    // 出现了回文数
                cout << "Yes" << endl;
                break;
            }
        }

        if(!flag){
            cout << "No" << endl;
        }


    }

    return 0;
}