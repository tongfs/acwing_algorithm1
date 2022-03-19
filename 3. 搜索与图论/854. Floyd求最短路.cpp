#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 210, INF = 0x3f3f3f3f;

int n, m, k;
int g[N][N];

void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int j = 1; j <= n; j ++ )
            for (int i = 1; i <= n; i ++ )
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main()
{
    cin >> n >> m >> k;

    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i ++ ) g[i][i] = 0;

    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    floyd();

    while (k -- )
    {
        int x, y;
        cin >> x >> y;
        
        if (g[x][y] > INF / 2) cout << "impossible" << endl;
        else cout << g[x][y] << endl;
    }
    
    return 0;
}