#include <iostream>
using namespace std;
int main()
{
    int n,k,c=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
    	for(;i>0;i/10){
    		if(i%10==k){
    			c++;
			}
		}
	}
	cout<<c;
	return 0;
}