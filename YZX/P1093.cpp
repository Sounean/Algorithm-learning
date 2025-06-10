#include <iostream>
using namespace std;
struct student {
		int chinese;
		int math;
		int english;
		int zf;
}student[n];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
    	cin>>student[i].chinese;
    	cin>>student[i].math;
    	cin>>student[i].english;
    	student[i].zf;
	}
	sort(student.zf,student.zf+n);
	
	return 0;
}