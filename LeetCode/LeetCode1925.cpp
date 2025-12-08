#include "iostream"
#include <cmath>
using namespace std;

// 咋去遍历这些情况呢
// 次数num
// 好像可以双指针去做这题，一个i针指向开头，另一个j指向他的下一位；
// 然后直接计算i平方+j平方 = s，再返回来sqrt求出来k，看k方是否等于s，是的话则num++；
//                                            如果k方小于s，则j往后挪一位
//                                            如果k方大于s，结束里面j循环，i往后挪一位，接着来，如果刚开始算出来的方就大于n方了，则直接结束全部循环

int countTriples(int n) {
    int num=0;
    int preIndex=1;    // 前指针
    int lastIndex=2;    // 后指针
    int s=0;    // 平方和
    int sq =0;  // 平方和的算数平方根
    for (; preIndex < n - 1; preIndex++) {
        bool judget = false;    // 判断是否第一次就满足了，第一次就满足直接跳出全部循环 （该值在第一次时就会被改成true
        for (lastIndex= preIndex + 1; lastIndex < n; lastIndex++) {
            s = pow(preIndex, 2) + pow(lastIndex, 2);
            sq = sqrt(s);
            if(sq > n){
                if(!judget) return num*2; // 如果第一次即大于n了，则表示后面肯定也不会有了
            }
            if(s<=pow(n,2) && pow(sq,2) == s){
//                cout << num<<":"<< preIndex << "_" << lastIndex << ":" << sq<<endl;
                num++;
            }
            judget = true;
        }

    }
    return num*2;
}
int main(){
//    int n = 5;
    int n=10;
//int n = 18;
    int max = countTriples(n);
    cout << max;

    return 0;
}