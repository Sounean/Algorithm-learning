#include "iostream"
using namespace std;

int num[1500];
int effectiveNum;   // 代表当前已经放了几个有效的数进去
int main(){
    // 1.获取数字
    int n = 0;
    cin >> n;
    bool flag = false;  // true表示输入的数大于0，false表示小于0
    if (n>0){
        flag = true;
    }

    bool panduan0 = true;  // 表示最右侧是否是连续的0 true表示是，false表示不是了

    // 2.把数字从右往左获取到effectiveNum数组中去(在这一步中，会去掉最右侧的连续0)
    while (n!=0){
        int geWei = n%10;   // 求出最右侧的数字
        if (!panduan0){
            // 当开始不是0了，就开始记录进数组中去
            if (geWei<0){
                geWei = geWei*-1;
            }
            num[effectiveNum] = geWei;
            effectiveNum++;
        } else{
            if (geWei!=0){
                panduan0 = false;
                if (geWei<0){
                    geWei = geWei*-1;
                }
                num[effectiveNum] = geWei;
                effectiveNum++;
            }
        }
        n = n/10;   // 去掉最右侧的数字
    }

    // 3.输出结果
    if (!flag){
        cout << "-";
    }
    for (int i=0;i<effectiveNum;i++) {
        cout << num[i];
    }

    return 0;
}