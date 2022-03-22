#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

struct Edge
{
    int a, b, w;

    bool operator < (const Edge &e) const
    {
        return w < e.w;
    }
}edges[M];

int n, m;
int p[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
    sort(edges, edges + m);

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        auto e = edges[i];
        int a = find(e.a), b = find(e.b);
        if (a != b)
        {
            p[a] = b;
            cnt ++ ;
            res += e.w;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < m; i ++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }

    int t = kruskal();

    if (t == INF) cout << "impossible" << endl;
    else cout << t << endl;

    return 0;
}