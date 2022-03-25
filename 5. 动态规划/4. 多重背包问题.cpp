#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N], w[N], s[N];
int f[N][N], dp[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i] >> s[i];

    // 二维写法
    // for (int i = 1; i <= n; i ++ )
    //     for (int j = 0; j <= m; j ++ )   // 这里的 j 不能从 v[i] 开始，不然无法更新部分 f[i][j]
    //         for (int k = 0; k <= s[i] && k * v[i] <= j; k ++ )
    //             f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
    
    // 一维写法
    for (int i = 1; i <= n; i ++ )
        for (int j = m; j >= v[i]; j -- )
            for (int k = 1; k <= s[i] && k * v[i] <= j; k ++ )
                dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);

    cout << dp[m] << endl;

    return 0;
}