#include "iostream"

using namespace std;

int main(){
    int use = 0;    // 实际用电量
    float count = 0;  // 花费费用

    cin >> use;

    if(use<150){
        count = use*0.4463;
//        printf("%.1f",count);
    } else if(use<400){
        count = 150*0.4463 + (use-150)*0.4663;
    } else{
        count = 150*0.4463 + (400-150)*0.4663 + (use-400)*0.5663;
    }
    printf("%.1f",count);

    return 0;
}

