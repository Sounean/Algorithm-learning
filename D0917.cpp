#include <algorithm>
#include <cstring>
#include "iostream"
#include "string"
using namespace std;

int value[150];   // 用来存小鱼保存的数字，因为数字不超过100，所以写150
int main() {
    int n = 0;
    bool flag = false;  // true时代表输出的数为0，false代表不为0
    int num = 0;    // 当前已经写了几个数了(刚好num-1也可以作为最后获取的非0数的索引)
    while (!flag){
        cin >> n;
        if (n != 0){
            xxxx;
            num++;
        } else{
            flag = true;
        }
    }
    for (int i = num-1; xxxx ; --i) {
        cout << value[i] << " ";
    }

    return 0;
}