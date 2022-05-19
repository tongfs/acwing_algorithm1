#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N][N];
char a[N], b[N];

// 状态表示：f[i][j]: 将 a[1~i] 变成 b[1~j] 的操作次数的最小值
// 和最长公共子序列类似，i 和 j 都表示两个字符串的最后一位

int main()
{
    cin >> n >> a + 1;
    cin >> m >> b + 1;

    for (int i = 1; i <= n; i ++ ) f[i][0] = i;
    for (int i = 1; i <= m; i ++ ) f[0][i] = i;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            f[i][j] = min(f[i][j - 1], f[i - 1][j]) + 1;
            f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
        }

    cout << f[n][m] << endl;

    return 0;
}