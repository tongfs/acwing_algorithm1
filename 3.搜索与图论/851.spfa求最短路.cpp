#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100010, INF = 0x3f3f3f3f;

int n, m;
int h[N], e[N], w[N], ne[N], idx = 1;
int d[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void spfa()
{
    memset(d, 0x3f, sizeof d);
    d[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i; i = ne[i])
        {
            int j = e[i];
            if (d[j] > d[t] + w[i])
            {
                d[j] = d[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    } 
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

    spfa();

    if (d[n] > INF / 2) cout << "impossible" << endl;
    else cout << d[n] << endl;

    return 0;
}