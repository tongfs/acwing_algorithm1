#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N], dp[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

    // 二维写法
    // for (int i = 1; i <= n; i ++ )
    //     for (int j = 0; j <= m; j ++ )
    //         if (j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
    //         else f[i][j] = f[i - 1][j];

    // 一维写法
    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= v[i]; j -- )
            dp[j] = max(dp[j], dp[j - v[i]] + w[i]);

    cout << dp[m] << endl;

    return 0;
}