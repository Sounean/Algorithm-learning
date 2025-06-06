#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int a[5] = {7,1,2,1,3};
    do{
        for (int i = 0; i < 5; ++i) {
            cout << a [i] << " ";
        }
        cout << endl;
    } while (next_permutation(a,a+5));

    return 0;
}
