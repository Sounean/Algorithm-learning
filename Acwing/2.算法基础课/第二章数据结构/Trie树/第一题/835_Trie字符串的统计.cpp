//
// Created by Administrator on 2024/12/10.
//
#include <iostream>
using namespace std;

const int N = 100010;
char str[N];
int son[N][26], cnt[N], idx;

void insert(char str[])
{
    int p = 0; //从根节点开始插入
    for(int i = 0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) {
            son[p][u] = ++idx;
            cout << "此时修改:P" << p <<";u:" << u << ";son[p][u]的值为:" << son[p][u] << ";idx的值:" << idx << endl;
        };
        p = son[p][u];
        cout << "我是真看不懂什么指针下移:" << son[p][u] << endl;
    }
    cnt[p]++;
    cout << "结束了本次插入操作:p:" << p << ";cnt[p]:" << cnt[p]  << endl;
}

int query(char str[])
{
    int p=0;
    for(int i=0; str[i]; i++)
    {
        int u = str[i] - 'a';
        if(!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main()
{
    int M;
    char op[2];
    cin >> M;
    while(M--)
    {
        scanf("%s %s", op, str); //字符数组名就是取地址名，不用加&
        if(op[0] == 'I') //op[1]存储\0
            insert(str);
        else
            printf("%d\n", query(str));
    }
    return 0;
}