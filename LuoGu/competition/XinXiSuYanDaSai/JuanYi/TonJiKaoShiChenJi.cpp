#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int scores[50]; // 根据题目限制，学生数量不超过50
    int totalScore = 0;

    // 读取每个学生的成绩并计算总成绩
    for (int i = 0; i < n; i++) {
        cin >> scores[i];
        totalScore += scores[i];
    }

    // 计算平均分（向下取整）
    int averageScore = totalScore / n;

    // 统计高于等于平均分和低于平均分的学生人数
    int aboveAverage = 0;
    int belowAverage = 0;

    for (int i = 0; i < n; i++) {
        if (scores[i] >= averageScore) {
            aboveAverage++;
        } else {
            belowAverage++;
        }
    }

    // 输出结果
    cout << aboveAverage << " " << belowAverage << endl;

    return 0;
}
