#include <iostream>
#include <cstring>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx = 1;
int match[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x)
{
    for (int i = h[x]; i; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (!match[j] || find(match[j]))
            {
                match[j] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    cin >> n1 >> n2 >> m;

    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    int res = 0;    // 记录匹配的对数
    for (int i = 1; i <= n1; i ++ )
    {
        memset(st, 0, sizeof st);   // 将右半部全部置为未访问状态
        if (find(i)) res ++ ;
    }
    
    cout << res << endl;
    
    return 0;
}