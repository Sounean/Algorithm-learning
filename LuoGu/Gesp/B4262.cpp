#include "iostream"
#include "string"
using namespace std;

string strList[120];
int countList[120];
int currentNum; // 当前有存几个字符串进去

// 把单词全部转换成小写
string toLowerStr(string str){
    for (int j = 0; j < str.length(); ++j) {
        if (str[j]<='Z'){
            // 说明是大写，要转换成小写
            str[j] = str[j]+('a'-'A');
        }
    }
    return str;
}

int main(){
    int n;
    cin >> n;
    for (int i=0;i<n;i++) {
        string str="";
        cin >> str;
        str = toLowerStr(str);

        bool flag = false;  // false表示字符串在原来收集的字符串数组中没有
        for (int i=0;i<currentNum;i++) {
            if(strList[i] == str){
                flag = true;
                countList[i]++;
            }
        }

        if(!flag){
            strList[currentNum] = str;
            countList[currentNum] = 1;
            currentNum++;
        }
    }

    int maxCountIndex = 0;
    for (int i = 0; i < currentNum; ++i) {
        if (countList[i]>countList[maxCountIndex]){
            maxCountIndex = i;
        }
    }

    cout << strList[maxCountIndex];
    return 0;
}
