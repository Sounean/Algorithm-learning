#include "iostream"
#include "string"
using namespace std;

string strList[120];
int countList[120];
int currentNum = 0; // 当前有存几个字符串进去，显式初始化为0

// 把单词全部转换成小写
string toLowerStr(string str){
    for (int j = 0; j < str.length(); ++j) {
        // 修正：准确判断是否为大写字母
        if (str[j] >= 'A' && str[j] <= 'Z'){
            // 说明是大写，要转换成小写
            str[j] = str[j] + ('a' - 'A');
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
        for (int j=0;j<currentNum;j++) {  // 修正：避免变量名冲突，使用j而不是i
            if(strList[j] == str){
                flag = true;
                countList[j]++;
                break;  // 优化：找到后立即退出循环
            }
        }

        if(!flag){
            strList[currentNum] = str;
            countList[currentNum] = 1;
            currentNum++;
        }
    }

    int maxCountIndex = 0;
    for (int i = 1; i < currentNum; ++i) {  // 优化：从1开始遍历
        // 修正：当出现次数相同时，选择字典序较小的字符串
        if (countList[i] > countList[maxCountIndex] || 
            (countList[i] == countList[maxCountIndex] && strList[i] < strList[maxCountIndex])){
            maxCountIndex = i;
        }
    }

    cout << strList[maxCountIndex];
    return 0;
}

