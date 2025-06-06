#include <iostream>

using namespace std;

int n;
int main(){
    cin >> n;
    //  十层for循环?
    int cnt = 0;
    if(n<10 || n>30){
        cout << 0;
        return 0;
    }

    string outStr[5010];
    for(int a=1;a<=3;a++){
        for(int b=1;b<=3;b++){
            for (int c = 1; c <=3 ; c++) {
                for (int d=1;d<=3;d++) {
                    for (int e = 1; e <=3; e++) {
                        for(int f=1;f<=3;f++){
                            for (int g = 1; g <=3 ; g++) {
                                for (int h = 1; h <=3 ; h++) {
                                    for (int i = 1; i <=3 ; i++) {
                                        for (int j = 1; j <=3 ; j++) {
                                            if(a+b+c+d+e+f+g+h+i+j == n){
                                                outStr[cnt] =
                                                        to_string(a) + " " + to_string(b)+" " + to_string(c) + " " +
                                                                to_string(d) + " " + to_string(e) + " "+ to_string(f) + " "+
                                                                                                                        to_string(g)+ " " +
                                                                to_string(h) + " " + to_string(i) + " "+ to_string(j);
                                                cnt++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (cnt==0){
        cout << 0;
    } else{
        cout << cnt<<endl;
        for (int i = 0; i < cnt; ++i) {
            cout << outStr[i]<<endl;
        }
    }

    return 0;
}
