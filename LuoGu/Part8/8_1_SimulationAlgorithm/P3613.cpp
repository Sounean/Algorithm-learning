#include <iostream>
#include <vector>

using namespace std;

int n, q;

int deskNo,boxNo;   // deskNo：第几个柜子,boxNo：柜子的第几个格口
int main(){
    cin >> n >> q;
    vector<vector<int>> locker(n+1);
    while(q--){
        int type;   // 操作类型
        cin >> type;
        if(type==1){
            int nums;   // 存放夺少东西
            cin >> deskNo >> boxNo >> nums;
            if(locker[deskNo].size() < boxNo+1){
                locker[deskNo].resize(boxNo+1);
            }
            locker[deskNo][boxNo] = nums;
        }else{
            cin >> deskNo >> boxNo;
            cout << locker[deskNo][boxNo] << endl;
        }
    }

    return 0;
}
