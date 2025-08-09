#include <iostream>
using namespace std;

int main() {
	int n,k;
	cin >> n >> k;
	float A1 = 0, A2 = 0, B1 = 0, B2 = 0;
	for (int i = 1 ; i <= n ; i++) {  // 修复：使用 <= 而不是 < n+1
		if (i%k==0) {
			A1 = A1 + i;
			A2 = A2 + 1;
		}
		else {
			B1 = B1 + i;
			B2 = B2 + 1;
		}
	}
	A1 = A1/A2;
	B1 = B1/B2;
	printf("%.1f %.1f\n", A1, B1);  // 修复：添加换行符，使用一个printf
	return 0;
} 