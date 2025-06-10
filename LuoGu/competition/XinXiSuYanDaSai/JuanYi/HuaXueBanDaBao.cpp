#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MAXH=100;

// 思路其实就是给先按从小到大排，这样不至于出现，很长的木板占用很小的
int main(){
    int n,weight;//滑板的数量n，滑板的重量weight
    cin>>n>>weight;
    int w[MAXH],l[MAXH];
    for(int i=1;i<=n;i++){
        cin>>w[i]>>l[i];
    }
    //使用冒泡排序法按长度对滑雪板排序
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            if(l[j]<l[j+1]){//交换长度
                int templ=l[j];
                l[j]=l[j+1];
                l[j+1]=templ;
                //按照长度交换对应重量
                int tempw=w[j];
                w[j]=w[j+1];
                w[j+1]=tempw;
            }
        }
    }
    int totall=0;//总木板数量
    int currew=0;//重量总值
    int maxl=0;
    for(int i=1;i<=n;i++){
        if(currew+w[i]>weight){
            totall+=2*maxl;
            currew=w[i];
            maxl=l[i];
        }else{
            currew+=w[i];
            maxl=max(maxl,l[i]);
        }
    }
    totall+=2*maxl;
    cout<<totall<<endl;
    return 0;
}


