#include <iostream>

using namespace std;

const int N = 100010;

int n;
int son[N][26], cnt[N], idx = 1;

void insert(string str)
{
    int p = 0;  // 0表示根节点或者不存在
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = idx ++ ;
        p = son[p][u];
    }

    cnt[p] ++ ;
}

int query(string str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }

    return cnt[p];
}


int main()
{
    cin >> n;

    while (n -- )
    {
        char op;
        string x;
        cin >> op >> x;

        if (op == 'I') insert(x);
        else cout << query(x) << endl;
    }

    return 0;
}