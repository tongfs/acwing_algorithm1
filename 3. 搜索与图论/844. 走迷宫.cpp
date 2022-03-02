#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int g[N][N], d[N][N];
queue<PII> q;
PII path[N][N];

void init()
{
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < m; j ++ )
            cin >> g[i][j];

    memset(d, -1, sizeof d);
    d[0][0] = 0;
}

int bfs()
{
    q.push({0, 0});

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1};

    while (q.size())
    {
        PII t = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i ++ )
        {
            int x = dx[i] + t.first, y = dy[i] + t.second;
            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
                path[x][y] = t;
            }
        }
    }

    // 输出路径
    // int i = n - 1, j = m - 1;
    // while (i || j)
    // {
    //     cout << i << ' ' << j << endl;
    //     PII t = path[i][j];
    //     i = t.first, j = t.second;
    // }
    
    return d[n - 1][m - 1];
}

int main()
{
    cin >> n >> m;

    init();
    cout << bfs() << endl;

    return 0;
}
