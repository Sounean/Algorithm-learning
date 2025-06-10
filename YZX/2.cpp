#include <iostream>
using namespace std;
int main()
{
    int x,d,s;
    cin>>x>>d;
    for(int i=0;i<d;i++){
	    if(30-x-d-i<d && 30-x-d-i>x){
	    	if(i<d && i>x){
		    	if(i<=30-x-d-i){
		    		cout<<i<<" "<<30-x-d-i<<endl;
					s++;
				}else{
					break;
				}	
			}
			
		}
	}
	if(s==0){
		cout<<"0"<<" "<<"0";
	}
	return 0;
}