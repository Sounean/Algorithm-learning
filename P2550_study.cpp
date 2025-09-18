# include <iostream>

using namespace std;
int arr[10] = {0};
int arr2[10] = {0};
int arr3[10] = {0};
int main() {

    int n = 0;
    cin >> n;
    for (int i = 0; i < 7; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> arr2[j];
        }
        int cnt = 0;
        for (int k = 0; k < 7; k++) {
            for (int l = 0; l < 7; l++) {
                if (arr[k]==arr2[l]) {
                    cnt += 1;
                }
            }
//            arr3[cnt] = arr3[7-cnt]+1;
        }
        // 假设中了7个号码即特等奖，修改的是下标为0
        arr3[7-cnt] = arr3[7-cnt]+1;
    }
    for (int i = 0; i < 7; i++) {
        cout << arr3[i] << " ";
    }
    return 0;
}