# include <iostream>
# include <string>
using namespace std;
int main() {
	int arr2[7] = {0,0,0,0,0,0,0};
	int n;
	cin >> n;
	int arr[7];
    int arrWrite[7];    // 用来获取每一次完整的彩票输入
	for (int i=0;i<7;i++) {
		cin >> arr[i];
	}
	for (int i=0;i<n;i++) {
		int x = 0;
		int y = 0;
        for(int q=0;q<7;q++){
            cin >> arrWrite[q];
        }
        for(int q=0;q<7;q++){
            // 用q来遍历arrWrite数组
            for (int j=0;j<7;j++) {
                // 用j来遍历arr数组
                if (arrWrite[q]==arr[j]) {
                    x+=1;
                }
            }
        }

		arr2[7-x] = arr2[7-x]+1;
	}
	cout << arr2[0] << " " << arr2[1] << " " << arr2[2] << " " << arr2[3] << " " << arr2[4] << " " << arr2[5] << " " << arr2[6];
	return 0;
} 
