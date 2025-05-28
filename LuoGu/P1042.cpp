//
// Created by Administrator on 2025/5/28.
//
//#include <iostream>
//#include <cmath>
//using namespace std;
//int f[2] = {11,21};
//int a[25*2500 + 10] ,n=0;
//int main(){
//    char tmp;
//    while(1){
//        cin >> tmp;
//        if(tmp == 'E')break;
//        else if(tmp == 'W') a[n++] = 1;
//        else if(tmp == 'L') a[n++] = 0;
//    }
//    for(int k=0;k<2;k++){
//        int w=0,l=0;
//        for(int i=0;i<n;i++){
//            w += a[i];l += 1-a[i];
//            if((max(w,l) >= f[k]) && abs(w-1) >= 2){
//                cout << w << ":" << l << endl;
//                w = l = 0;
//            }
//        }
////        if(w!=0 || l!=0)cout << w<< ":" << l<< endl;
//
//        cout << endl;
//    }
//
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;

const int N = 2505;

string all;
int scores[2] = {11, 21};

int main()
{
    // 读取所有输入字符直到遇到'E'
    char c;
    while (cin >> c) {
        if (c == 'E') {
            all += c;
            break;  // 遇到'E'立即停止读取
        }
        if (c == 'W' || c == 'L') {
            all += c;
        }
        // 忽略其他字符，如换行符
    }

    // 针对11分、21分制分别处理
    for(int i = 0; i < 2; i++)
    {
        int score = scores[i];
        int w = 0, l = 0; // 比分初始值
        for(int j = 0; j < all.size(); j++)
        {
            if(all[j] == 'W') w++; // 华华得分
            else if(all[j] == 'L') l++; // 对手得分
            else if(all[j] == 'E') break; // 比赛结束

            // 如果得分超过11或者21，且比分间隔>=2，表示一局结束，输出比分
            if(max(w, l) >= score && abs(w - l) >= 2)
            {
                cout << w << ":" << l << endl;
                w = l = 0;
            }
        }
        // 如果一局比赛未结束，也要输出本局比分
        if(w!=0 || l!= 0)cout << w << ":" << l << endl;

        // 11分制和21分制之间有换行
        if(i == 0) cout << endl;
    }

    return 0;
}

