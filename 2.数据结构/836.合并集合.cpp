#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N];

int find(int x)
{
    // 返回x的祖宗节点 + 路径压缩
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) p[i] = i;

    while (m -- )
    {
        char op;
        int a, b;
        cin >> op >> a >> b;

        a = find(a), b = find(b);

        if (op == 'M') p[a] = b;
        else cout << (a == b ? "Yes" : "No") << endl;
    }

    return 0;
}