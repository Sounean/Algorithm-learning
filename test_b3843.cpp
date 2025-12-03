#include <iostream>
#include <string>
using namespace std;

string get[120];   // 获取到的字符串根据逗号拆解成字符数组

// 判断字符串是否合规
bool judgetStr(string str){
    // 1.判断问题条件2长度是否符合
    if (str.length()<6 || str.length()>12){
        return false;
    }

    // 遍历字符串，查看字符串是否满足问题条件1和2
    int right[] = {0,0,0,0};    // 分别代表 属不属于大写A~Z、小写a~z、数字0~9、字符!@#$。 不符合则为0，符合则为1.默认初始化都是不符合
    for (int i = 0; i < str.length(); ++i) {
        char ch = str[i];

        if (ch>='A' && ch <='Z'){
            right[0] = 1;
        } else if(ch>='a' && ch<='z'){
            right[1] = 1;
        } else if(ch>='0' && ch<='9'){
            right[2] = 1;
        } else if (ch=='!'
                    || ch=='@'
                    || ch=='#'
                    || ch=='$'){
            right[3] = 1;
        } else{
            // 2.判断 不满足问题条件1时
            return false;
        }
    }

    // 3.判断不满足问题条件3时
    if (right[0]+right[1]+right[2] <2 || right[3]==0){
        return false;
    }

    return true;
}

int main(){
    string str1 = "";
    cin >> str1;

    // 第一大步：拆分字符串
    int currentGetStrIndex = 0; // 当前是第几个拆解出来的字符串
    while (str1.length() > 0){
        // 1.找出第一个逗号前面的字符串
        int index = str1.find(","); // 寻找逗号所在索引
        if(index>0){
            // 1.1有找到逗号的话，则将逗号前的字符串截取出来存到get字符数组；最后删除掉原字符串中第一个逗号和逗号前的字符串
            string strNew = str1.substr(0,index);   // (开始位子，子串长度)
            get[currentGetStrIndex] = strNew;
            currentGetStrIndex ++ ;
            // 去掉第一个逗号和他前面的字符串
            str1 = str1.erase(0,index+1); // (开始下标，删除长度)
        } else{
            // 1.2 如果没有找到逗号，且字符串长度又还有，则说明该字符串就是最后的字符串了
            get[currentGetStrIndex] = str1;
            currentGetStrIndex++;
            str1 = "";  // 也得清空掉，不然while循环就出不去了
        }

    }

    // 第二大步，筛选字符串到goodStr中去
    for (int i=0;i<currentGetStrIndex;i++) {
        bool flag  = judgetStr(get[i]);
        if (flag){
            cout << get[i] << endl;
        }
    }

    return 0;
}












