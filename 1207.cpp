#include "iostream"

using namespace std;

int n;
double a[450];  // 白细胞数量样本
int main(){
    cin >> n;   // 获取白细胞数量

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    double max1 = a[0];
    double min1 = a[0];
    for (int i = 0; i < n; ++i) {
        if(max1 < a[i]){
            max1 = a[i];
        }
        if(min1 > a[i]){
            min1 = a[i];
        }
    }

    double sum1 = 0;
    for (int i = 0; i < n; ++i) {
        if( a[i]!=max1 && a[i]!=min1){
            sum1+=a[i];
        }
    }
    double avg = sum1/(n-2);

    double absMax = 0;
    for (int i = 0; i < n; ++i) {
        if( a[i]!=max1 && a[i]!=min1){
            double d1 = avg-a[i];
            if(d1<0){
                d1 = d1*-1;
            }
            if(d1>absMax){
                absMax = d1;
            }
        }
    }
    cout << avg << ":" << absMax;

//    cout << "max:" <<max1 << "min:" << min1;

//1 0  1

    return 0;
}
