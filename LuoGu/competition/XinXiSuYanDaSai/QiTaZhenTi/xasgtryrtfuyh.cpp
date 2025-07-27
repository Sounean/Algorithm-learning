#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int x = 0;
	int find=0;
	int j = 0;
	for(int i=2;i<=10;i++){
        find = 0;
		j=n*i;
		for(;j>0;j=j/10){
			 find=find*10+j%10;
		}
		if(n==find){
			x=i;
			break;
		}
	}
	cout<<x;
}
