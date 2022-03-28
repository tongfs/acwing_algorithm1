#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 15, M = 1010;

int n, m;
int f[N][N];
char str[M][N];

int edit_dist(char a[], char b[])
{
    int n = strlen(a + 1), m = strlen(b + 1);

    for (int i = 1; i <= n; i ++ ) f[i][0] = i;
    for (int i = 1; i <= m; i ++ ) f[0][i] = i;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }
    
    return f[n][m];
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i ++ ) cin >> str[i] + 1;

    while (m -- )
    {
        char s[N];
        int k;
        cin >> s + 1 >> k;

        int res = 0;
        for (int i = 0; i < n; i ++ )
            if (edit_dist(str[i], s) <= k)
                res ++ ;
        
        cout << res << endl;
    }

    return 0;
}