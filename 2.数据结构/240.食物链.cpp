#include <iostream>

using namespace std;

const int N = 500010;

int n, k;
int p[N], d[N];

int find(int x)
{
    if (p[x] != x)
    {
        // 这里 p[x] 变了，d[x] 没变
        int t = p[x];
        p[x] = find(p[x]);
        d[x] += d[t];
    }
    return p[x];
}

int main()
{
    cin >> n >> k;
    
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    
    int res = 0;
    while (k -- )
    {
        int t, x, y;
        cin >> t >> x >> y;
        
        if (x > n || y > n) res ++ ;
        else
        {
            int px = find(x), py = find(y);
            if (t == 1)
            {
                if (px == py && (d[x] - d[y]) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else 
            {
                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ;
                else if (px != py)
                {
                    p[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    
    cout << res << endl;
    return 0;
}