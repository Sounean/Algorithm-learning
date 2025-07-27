#include<iostream>
#include<algorithm>
using namespace std;
int b[28]={0};
int maxn,minn;
int main(){
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		b[a[i]-'A']+=1;
	}
	sort(b,b+26);
	maxn=b[25];
	for(int i=0;i<=25;i++){
		if(b[i]>0){
			minn=b[i];
			break;
		}
		
	}
	cout<<maxn-minn;
}
