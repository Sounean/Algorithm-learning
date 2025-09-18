#include "iostream"

using namespace std;


// 马可能会出现的位子 (最多总共9个，如果超出了范围的不需要给记录下来
//马（2，4） （4，5） （3，6） （1，6） （0，5） （0，3） （1，2） （3，2） （4，3）
int horsePoints[9][2] = {
        {0,0},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}
};

int BPoint[2] = {0,0};

void initHorseOtherPoints() {
    for(int i=1;i<9;i++){
        horsePoints[i][0] = horsePoints[i][0]+horsePoints[0][0];
        horsePoints[i][1] = horsePoints[i][1]+horsePoints[0][1];
//        cout << "("<<horsePoints[i][0] << "," << horsePoints[i][1]<<")" << " ";
    }
}

int getNum(int point[]){
    // 在马点上时
    for(int i=0;i<9;i++){
        if (point[0] == horsePoints[i][0] && point[1] == horsePoints[i][1])return 0;
    }
    // 在原点上时
    if (point[0] == point[1] && point[1] == 0) return 0;
    // 在x轴或者y轴上时
    if(point[0] == 0 || point[1] == 0) return 1;
    // 其他可以落脚的情况
    int lastPoint1[2] = {point[0]-1,point[1]};
    int lastPoint2[2] = {point[0],point[1]-1};
    return getNum(lastPoint1) + getNum(lastPoint2);
}

int main(){
    cin >> BPoint[0] >> BPoint[1] >> horsePoints[0][0] >> horsePoints[0][1];
    // 补充完整其他马的落地坐标
    initHorseOtherPoints();

    // 获取总共可能的路径数
    int nums = getNum(BPoint);

    cout << nums;
    return 0;
}




