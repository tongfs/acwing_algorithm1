#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;
int g[N][N], d[N];
bool st[N];

int prim()
{
    memset(d, 0x3f, sizeof d);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = 0;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (!t || d[t] > d[j]))
                t = j;
        
        if (i && d[t] == INF) return INF;
        if (i) res += d[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ )
            if (!st[j])     // 加判断是为了避免自环的出现，导致自己更新自己
                d[j] = min(d[j], g[t][j]);
    }

    return res;
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while (m --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();

    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}