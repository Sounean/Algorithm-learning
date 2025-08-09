#include "iostream"
#include "algorithm"
using namespace std;

int haveGet[7] = {0};   // 记录的中奖个数
int main(){
    int global[7] = {0};    // 中奖的号码
    int n = 0;  // 买的彩票张数
    int buyTicket[7] = {0};
    cin >> n;
    for (int i = 0; i < 7; ++i) {
        cin >> global[i];
    }
    sort(global,global+7);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 7; ++j) {
            cin >> buyTicket[j];
        }
        sort(buyTicket,buyTicket+7);

        int cnt = 0;
        int buyTicketIndex = 0;
        int globalIndex = 0;
        while (buyTicketIndex<7 && globalIndex<7){
            if(buyTicket[buyTicketIndex] == global[globalIndex]){
                cnt++;
                globalIndex++;
                buyTicketIndex++;
            }
            if (buyTicket[buyTicketIndex] > global[globalIndex]){
                globalIndex++;
            }
            if (buyTicket[buyTicketIndex] < global[globalIndex]){
                buyTicketIndex++;
            }
            if(globalIndex>7)globalIndex=7;
            if(buyTicketIndex>7)buyTicketIndex=7;
        }

        haveGet[7-cnt]++;
    }

    for (int i = 0; i < 7; ++i) {
        cout << haveGet[i] << " ";
    }


    return 0;
}