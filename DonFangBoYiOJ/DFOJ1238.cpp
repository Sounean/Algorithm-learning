#include "iostream"
using namespace std;
int n;
long long x,y,z;
int main(){
   cin >> n;
   if(n<=0){
       cout << 0;
       return 0;
   }

   if(n==1||n==2){
       cout << 1;
       return 0;
   }

   y = 1;
   z = 1;
    for (int i = 2; i <n; ++i) {
        x = y;
        y = z;
        z = x+y;
    }
    cout << z;

    return 0;
}
