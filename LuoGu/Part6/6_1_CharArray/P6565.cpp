#include <string>
#include <iostream>

using namespace std;
string names[120];
string signals[120];
string maxMoreSosnames = "";
int maxMoreSosNum = -1;

// 计算字符串中有多少个sos
int countSos(string str){
    if (str.length() < 3) return 0; // 可能产生RE点：每当有下方往后面连续多取的，都得加一行这个防止越界！！！
    int counts = 0;
    for(int i = 0;i<str.length()-2;i++){
        if(str[i]=='s' and str[i+1]=='o' and str[i+2]=='s'){
            counts++;
        }
    }
    return counts;
}
int main(){
    int n = 0;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        getline(cin,names[i]);
        getline(cin,signals[i]);
        int nums = countSos(signals[i]);
        if (nums>maxMoreSosNum){
            maxMoreSosnames=names[i];
            maxMoreSosNum = nums;
        }else if(nums == maxMoreSosNum){
            maxMoreSosnames =  maxMoreSosnames+" "+names[i];
        }
    }

    cout << maxMoreSosnames<<endl;
    cout << maxMoreSosNum;

    return 0;
}
