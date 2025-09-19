#include "iostream"
#include "algorithm"    // 算法库
using namespace std;
// 函数中小括号中两个变量代表是数组任意两个相邻的元素

// 从大到小排序
bool cmp(int a,int b){
    return a>b;
}

// 按照个位数大小从大到小排序
bool cmp1(int a,int b){
    return a%10 > b%10;
}

// 结构体 (打包)
struct Student{
    int chinese;
    int math;
    int english;
    int allScore;   // 总分
    int sno;    // 学号
};


bool cmp2(Student s1,Student s2){
    if(s1.allScore!=s2.allScore){
        return s1.allScore > s2.allScore;
    } else{
        if (s1.chinese!=s2.chinese){
            return s1.chinese > s2.chinese;
        } else{
            return s1.sno < s2.sno;
        }
    }
}
int main() {
    Student stuList[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        stuList[i].sno = i+1;
        cin >> stuList[i].chinese >> stuList[i].math >> stuList[i].english;
        stuList[i].allScore = stuList[i].chinese+stuList[i].math+stuList[i].english;
    }

    sort(stuList,stuList+n,cmp2);

    for (int i = 0; i < 5; ++i) {
        cout<< stuList[i].sno << " " << stuList[i].allScore <<endl;
    }
//    int arr3[10] = {1,2313,345,567,10,0,12,32,65,8};
//
//    sort(arr3,arr3+10,cmp1);
//    for (int i = 0; i < 10; ++i) {
//        cout << arr3[i] << " ";
//    }

    return 0;
}