#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int d[N], q[N], hh, tt = -1;
int h[N], e[N], ne[N], idx = 1;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool topsort()
{
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (tt >= hh)
    {
        int t = q[hh ++ ];
        for (int i = h[t]; i; i = ne[i])
        {
            int j = e[i];
            d[j] -- ;
            if (!d[j]) q[ ++ tt] = j;
        }
    }

    return tt == n - 1;
}

int main()
{
    cin >> n >> m;

    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++ ;
    }

    if (topsort())
        for (int i = 0; i < n; i ++ )
            cout << q[i] << ' ';
    else cout << -1;
    cout << endl;

    return 0;
}