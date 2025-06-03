//
// Created by Administrator on 2025/5/28.
//
#include "iostream"
using namespace std;
int n,m;
char chars[101][101];
int main(){
    cin >> n;   // n行
    cin >> m;   // 每行m个字符


    // 1.获取输入内容
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> chars[i][j];
        }
    }
    // 2.进行分析
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(chars[i][j]!='*'){
                int cnt = 0;
                // 左上角
                if(i-1 <0 || j-1<0){
                }else{
                    if(chars[i-1][j-1] == '*'){
                        cnt++;
                    }
                }
                // 上方
                if(i-1<0){
                }else{
                    if(chars[i-1][j] == '*'){
                        cnt++;
                    }
                }
                // 右上方
                if(i-1<0 || j+1==m){
                }else{
                    if(chars[i-1][j+1] == '*'){
                        cnt++;
                    }
                }
                // 左侧
                if(j-1<0){
                }else{
                    if(chars[i][j-1] == '*'){
                        cnt++;
                    }
                }
                // 右侧
                if(j+1==m){
                }else{
                    if(chars[i][j+1] == '*'){
                        cnt++;
                    }
                }
                //左下方
                if(i+1==n || j-1<0){
                }else{
                    if(chars[i+1][j-1] == '*'){
                        cnt++;
                    }
                }
                // 下方
                if(i+1==n){
                }else{
                    if(chars[i+1][j] == '*'){
                        cnt++;
                    }
                }
                // 右下方
                if(i+1==n || j+1==m){
                }else{
                    if(chars[i+1][j+1] == '*'){
                        cnt++;
                    }
                }
                chars[i][j] = cnt+'0';
            }
        }
    }

    // 3.输出内容
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << chars[i][j];
        }
        cout << endl;
    }

    return 0;
}

// 通过1.构造虚拟的边界和2.利用dx,dy遍历偏移来实现省略if嵌套