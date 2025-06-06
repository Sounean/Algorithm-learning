#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Student{
    string s;
    int y;
    int m;
    int d;
    int sno;    // 输入的序号
}students[110];

bool cmp(Student s1,Student s2){
    if(s1.y!=s2.y)return s1.y<s2.y;

    if(s1.m!=s2.m)return s1.m<s2.m;

    if(s1.d!=s2.d)return s1.d<s2.d;

    return s1.sno>s2.sno;
}

int n;
int main(){
    cin >> n;

    for (int i=0;i<n;i++) {
        cin >> students[i].s>> students[i].y >> students[i].m >> students[i].d;
        students[i].sno = i;
    }

    sort(students , students+n , cmp);

    for (int i = 0; i < n; ++i) {
        cout << students[i].s << endl;
    }

    return 0;
}
