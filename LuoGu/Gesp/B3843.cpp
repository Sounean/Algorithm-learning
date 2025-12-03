#include "iostream"
#include "cstdlib"
#include "ctime"
#include "math.h"

using namespace std;

int main(){
    srand(time(0));
    // 产生随机数，范围是:2~8    1.判断范围知晓范围大小n；2.rand()%(n+1) + 偏移
    int n = rand()%6 + 1;
    cout << sqrt(4)<<endl;
    return 0;
}