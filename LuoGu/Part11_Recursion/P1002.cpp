#include <iostream>

using namespace std;

// 马可能的偏移量
int horseOffset[10][2] = {
        {0,0},
        {-2,1},
        {-1,2},
        {1,2},
        {2,1},
        {2,-1},
        {1,-2},
        {-1,-2},
        {-2,-1}
};

int horsrPoint[30][30] ={0};    // 这里面不是直接存坐标，而是马的坐标处设为1

int mem[30][30];    // 保存直接走过的坐标所可能的路径条数
bool visited[30][30] = {false};

int B[3],FO[3]; // B右下角、FO是马的坐标

int forstSize;  // 有效的马的坐标数量

int getF(int x,int y){

    if(visited[x][y])return mem[x][y];

    if(horsrPoint[x][y]){
        // 如果是马的地方就不加进来
        return 0;
    }

    if (x==1 && y == 0){
        return 1;
    }

    if(x==0 && y==1){
        return 1;
    }

    if(x>=0 && y>=0){
        int tiaoshu = getF(x-1,y)+ getF(x,y-1);
        visited[x][y] = true;
        mem[x][y] = tiaoshu;
        return tiaoshu;
    }

}

void getHorsePoint(int fOldx,int fOldy){
    for (int i = 0; i < 9; ++i) {
        if (fOldx+horseOffset[i][0]<0 && fOldx+horseOffset[i][0]>B[0] && fOldy+horseOffset[i][1]<0
        && fOldy+horseOffset[i][1]>B[1])continue;    // 如果超过棋盘就不算在内
        horsrPoint[fOldx+horseOffset[i][0]][fOldy+horseOffset[i][1]] = 1;
        forstSize++;
    }
}

int main(){

    cin >> B[0] >> B[1];
    cin >> FO[0] >> FO[1];

    getHorsePoint(FO[0] , FO[1]);

    int cnt = getF(B[0],B[1]);

    cout << cnt;

    return 0;
}