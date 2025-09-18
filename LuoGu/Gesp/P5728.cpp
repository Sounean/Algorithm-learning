#include "iostream"
#include "cmath"
using namespace std;

struct Student{
    int chinese;
    int math;
    int english;
    int allSocre;
} students[1500];
int main(){
    int num;
    cin >> num;

    int count = 0;
    for (int i=0;i<num;i++) {
        cin >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].allSocre = students[i].chinese + students[i].math + students[i].english;
    }

    for (int i = 0; i < num; ++i) {
        for (int k=i+1;k<num;k++) {
            if (abs(students[i].chinese-students[k].chinese)<=5
            && abs(students[i].math - students[k].math)<=5
            && abs(students[i].english - students[k].english)<=5
            && abs(students[i].allSocre -students[k].allSocre) <= 5){
                count++;
            }
        }
    }

    cout << count;
    return 0;
}
