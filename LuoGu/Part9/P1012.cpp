#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string s1,string s2){
    int s1Length = s1.length();
    int s2Length = s2.length();
    int cmpIndex = 0;
    while (cmpIndex<=s1Length && cmpIndex <= s2Length){
        if(s1[cmpIndex]!=s2[cmpIndex]){
            return s1[cmpIndex]>s2[cmpIndex];
        } else{
            cmpIndex++;
        }
    }
    return s1Length<s2Length;   // 这里有问题，3 392 13 和3 302 13 这两个测试集可以搞死
}

int n;
int main(){
    cin >> n;
    string getStr[n+2];
    for(int i=0;i<n;i++){
        cin >> getStr[i];
    }

    sort(getStr , getStr+n , cmp);

    for (int i=0;i<n;i++) {
        cout << getStr[i];
    }

    return 0;
}


/*
 * 测试集:3 392 13 输出392313
 * 3 302 13  输出313302
 * */