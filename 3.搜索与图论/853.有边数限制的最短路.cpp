#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 10010, INF = 0x3f3f3f3f;

int n, m, k;
int d[N], last[N];

struct Edge
{
    int a, b, w;
}edges[M];

void bellman_ford()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    for (int i = 0; i < k; i ++ )
    {
        memcpy(last, d, sizeof d);
        for (int j = 0; j < m; j ++ )
        {
            auto e = edges[j];
            d[e.b] = min(d[e.b], last[e.a] + e.w);
        }
    }
}

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i ++ )
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    bellman_ford();

    if (d[n] > INF / 2) cout << "impossible" << endl;
    else cout << d[n] << endl;
    
    return 0;
}
