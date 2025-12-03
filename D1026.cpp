#include "iostream"
using namespace std;


void testA(int x){
    x+1;
}

int main() {
    int a = 99;
    testA(a);
    cout << a;
    return 0;
}