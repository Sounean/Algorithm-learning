#include <iostream>
#include <string>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	double A1 = 0, A2 = 0, B1 = 0, B2 = 0;  // 修复：1.初始化所有变量为0,不然的话，可能会出现随机数！！！！！！2.应该改成double类型，因为float有效数字只有6-7位，很明显可能会超了
	for (int i = 1 ; i < n+1 ; i++) {
		if (i%k==0) {
			A1 = A1 + i;
			A2 = A2 + 1;
		}
		else {
			B1 = B1 + i;
			B2 = B2 + 1;
		}
	}
    if(A2!=0){
        A1 = A1/A2;
    }
	if(B2!=0){
        B1 = B1/B2;
    }

	printf("%.1f",A1);
	printf(" ");
	printf("%.1f",B1);
	return 0;
}