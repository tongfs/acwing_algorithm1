#include <iostream>
#include <algorithm>

using namespace std;

const int N = 31 * 100010;

int n;
int son[N][2], idx = 1;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (!son[p][u]) son[p][u] = idx ++ ;
        p = son[p][u];
    }
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i -- )
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            res += 1 << i;
            p = son[p][!u];
        }
        else p = son[p][u];
    }
    
    return res;
}

int main()
{
    cin >> n;
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t;
        cin >> t;
        insert(t);
        res = max(res, query(t));
    }
    
    cout << res << endl;
    return 0;
}