#include <iostream>
#include <algorithm>

using namespace std;

struct Student{
    int chinese;
    int math;
    int english;
    int allScore;
    int sno;    // 学号
}stu[310];

bool cmp(Student s1,Student s2){
    if(s1.allScore!=s2.allScore)return s1.allScore>s2.allScore;

    if(s1.chinese!=s2.chinese)return s1.chinese>s2.chinese;

    return s1.sno<s2.sno;
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        cin >> stu[i].chinese;
        cin >> stu[i].math;
        cin >> stu[i].english;
        stu[i].allScore = stu[i].chinese + stu[i].math + stu[i].english;
        stu[i].sno = i;
    }
    sort(stu+1 , stu+1+n , cmp);

    for (int i = 1; i <=5 ; ++i) {
        cout << stu[i].sno << " " << stu[i].allScore << endl;
    }

    return 0;
}
