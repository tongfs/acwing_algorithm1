#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;
int g[N][N], dist[N];
bool st[N];

int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 1; i < n; i ++ )
    {
        int t = 0;  // 定义距离源点最近的点，初始为0表示还没有
        
        // 找到为访问过的且距离源点最近的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (!t || dist[j] < dist[t]))
                t = j;
        
        // 用这个点去更新剩下未访问点的距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    cout << dijkstra() << endl;

    return 0;
}