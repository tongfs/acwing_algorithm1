#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];
bool row[N], col[N], dg[N], udg[N];

// 解法1
void dfs1(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i ++ ) cout << g[i] << endl;
        cout << endl;

        return;
    }

    for (int i = 0; i < n; i ++ )
    {
        if (!col[i] && !dg[u + i] && !udg[n - u + i])
        {
            g[u][i] = 'Q';
            col[i] = dg[u + i] = udg[n - u + i] = 1;
            dfs1(u + 1);
            col[i] = dg[u + i] = udg[n - u + i] = 0;
            g[u][i] = '.';
        }
    }
}

// 解法2
void dfs2(int x, int y, int s)
{
    if (y == n) x ++ , y = 0;
    if (x == n)
    {
        if (s == n)
        {
            for (int i = 0; i < n; i ++ ) cout << g[i] << endl;
            cout << endl;
        }
        return;
    }

    // 不放皇后
    dfs2(x, y + 1, s);

    // 放皇后
    if (!row[x] && !col[y] && !dg[x + y] && !udg[n - x + y]) 
    {
        g[x][y] = 'Q';
        row[x] = col[y] = dg[x + y] = udg[n - x + y] = 1;
        dfs2(x, y + 1, s + 1);
        row[x] = col[y] = dg[x + y] = udg[n - x + y] = 0;
        g[x][y] = '.';
    }
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            g[i][j] = '.';

    // dfs1(0);
    dfs2(0, 0, 0);

    return 0;
}
