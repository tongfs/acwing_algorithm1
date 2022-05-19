#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int n, m;
int h[N], e[N], w[N], ne[N], idx = 1;
int d[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 1});

    while (q.size())
    {
        auto t = q.top();
        q.pop();

        int dist = t.first, ver = t.second;
        if (dist != d[ver]) continue;   // 不是最优，直接跳过
        if (ver == n) return dist;      // 已有最后的结果，直接返回

        for (int i = h[ver]; i; i = ne[i])
        {
            int j = e[i];
            if (d[j] > dist + w[i])
            {
                d[j] = dist + w[i];
                q.push({d[j], j});
            }
        }
    }

    if (d[n] == 0x3f3f3f3f) return -1;
    return d[n];
}

int main()
{
    cin >> n >> m;

    while (m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    cout << dijkstra() << endl;

    return 0;
}