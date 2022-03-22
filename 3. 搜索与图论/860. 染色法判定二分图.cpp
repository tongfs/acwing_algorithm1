#include <iostream>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx = 1;
int color[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c)
{
    color[u] = c;

    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c)) return false;
        }
        else if (color[j] == c) return false;
    }

    return true;
}

int main()
{
    cin >> n >> m;

    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i ++ )
    {   // 这里需要遍历每一个节点
        if (!color[i])
            if (!dfs(i, 1))
            {
                flag = false;
                break;
            }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}