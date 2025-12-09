#include <iostream>
using namespace std;

// 用户代码的逻辑（有bug的版本）
int userSolution(int N, int i) {
    int num = 1;
    while (true) {
        int TempNum = num;
        int j = N;
        for (; j >= 1; j--) {
            if ((TempNum * 3 + 1) % 2 == 0) {
                TempNum = (TempNum * 3 + 1) / 2;
            } else {
                break;
            }
        }
        if (j == 1) {
            return TempNum * 3 + 1;
        }
        num++;
    }
}

// 正确的解法
int correctSolution(int N, int i) {
    for (int lastTake = 1; ; lastTake++) {
        int fish = N * lastTake + i;
        bool valid = true;
        int currentTake = lastTake;
        
        for (int cat = N - 1; cat >= 1; cat--) {
            int remaining = fish - currentTake - i;
            if (remaining % (N - 1) != 0) {
                valid = false;
                break;
            }
            currentTake = remaining / (N - 1);
            fish = N * currentTake + i;
        }
        
        if (valid) {
            return fish;
        }
    }
}

int main() {
    cout << "=== 会WA的测试用例 ===" << endl << endl;
    
    // 测试用例1: N=3, i=1 (这个可能AC，因为代码就是为这个写的)
    int N1 = 3, i1 = 1;
    int correct1 = correctSolution(N1, i1);
    int user1 = userSolution(N1, i1);
    cout << "测试用例1: N=" << N1 << ", i=" << i1 << endl;
    cout << "  正确答案: " << correct1 << endl;
    cout << "  你的输出: " << user1 << endl;
    cout << "  结果: " << (correct1 == user1 ? "AC" : "WA") << endl << endl;
    
    // 测试用例2: N=3, i=2 (不同的i值)
    int N2 = 3, i2 = 2;
    int correct2 = correctSolution(N2, i2);
    int user2 = userSolution(N2, i2);
    cout << "测试用例2: N=" << N2 << ", i=" << i2 << endl;
    cout << "  正确答案: " << correct2 << endl;
    cout << "  你的输出: " << user2 << endl;
    cout << "  结果: " << (correct2 == user2 ? "AC" : "WA") << endl << endl;
    
    // 测试用例3: N=4, i=1 (不同的N值)
    int N3 = 4, i3 = 1;
    int correct3 = correctSolution(N3, i3);
    int user3 = userSolution(N3, i3);
    cout << "测试用例3: N=" << N3 << ", i=" << i3 << endl;
    cout << "  正确答案: " << correct3 << endl;
    cout << "  你的输出: " << user3 << endl;
    cout << "  结果: " << (correct3 == user3 ? "AC" : "WA") << endl << endl;
    
    // 测试用例4: N=2, i=1
    int N4 = 2, i4 = 1;
    int correct4 = correctSolution(N4, i4);
    int user4 = userSolution(N4, i4);
    cout << "测试用例4: N=" << N4 << ", i=" << i4 << endl;
    cout << "  正确答案: " << correct4 << endl;
    cout << "  你的输出: " << user4 << endl;
    cout << "  结果: " << (correct4 == user4 ? "AC" : "WA") << endl << endl;
    
    // 测试用例5: N=5, i=1
    int N5 = 5, i5 = 1;
    int correct5 = correctSolution(N5, i5);
    int user5 = userSolution(N5, i5);
    cout << "测试用例5: N=" << N5 << ", i=" << i5 << endl;
    cout << "  正确答案: " << correct5 << endl;
    cout << "  你的输出: " << user5 << endl;
    cout << "  结果: " << (correct5 == user5 ? "AC" : "WA") << endl << endl;
    
    cout << "=== 问题总结 ===" << endl;
    cout << "你的代码硬编码了 N=3 和 i=1，使用了：" << endl;
    cout << "  - TempNum * 3 + 1  (应该是 TempNum * N + i)" << endl;
    cout << "  - (TempNum * 3 + 1) % 2  (应该是 % (N-1))" << endl;
    cout << "  - (TempNum * 3 + 1) / 2  (应该是 / (N-1))" << endl;
    cout << "  - TempNum * 3 + 1 作为最终答案 (应该是 TempNum * N + i)" << endl;
    
    return 0;
}



