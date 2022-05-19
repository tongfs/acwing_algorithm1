#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20, M = 1 << N;

int n;
int w[N][N];
int f[M][N];

// 状态表示：f[i][j]: 从 0 走到 j，所有走过的点是 i（二进制表示状态） 的最短路径长度

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ )
            cin >> w[i][j];
    
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;    // 从 0 走到 0，只经过 0 这个点

    for (int i = 1; i < 1 << n; i += 2 )    // 理解一下这里步长为什么可以设置成2
        for (int j = 1; j < n; j ++ )
            if (i >> j & 1)
                for (int k = 0; k < n; k ++ )
                    if ((i - (1 << j)) >> k & 1)
                        f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[j][k]);

    cout << f[(1 << n) - 1][n - 1] << endl;

    return 0;
}