#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int nums[20] = {1,2,3,4,5,6,7,8,9};
	int N = 0;
	cin >> N;
	int cnt = 0;
	do{
		for(int ai = 1;ai<=7;++ai){
			int a = 0;
			for(int i=0;i<ai;++i){
				a = a*10+nums[i];
			}
			for(int bi = ai+1;bi<=8;++bi) {
				int b=0;
				for(int i=ai;i<bi;++i){
					b = b*10+nums[i];
				}
				int c = 0;
				for(int i=bi;i<9;++i){
					c = c*10+nums[i];
				} 
    
				// 检查 c != 0 并且 a*c + b == N*c
				if(b%c==0 && a+b/c==N){
					cnt++;
				}	
			}	
		}
	} while(next_permutation(nums,nums+9));
	
	cout << cnt;
	return 0;
}
