#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;

int n;
int s[N], f[N][N];

// 状态表示：f[i][j]: 将第 i 堆到第 j 堆石子合并成一堆石子代价的最小值

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ )
    {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    for (int len = 2; len <= n; len ++ )    // len 表示区间长度
        for (int i = 1; i + len - 1 <= n; i ++ ) // i 是左端点，i + len - 1 是右端点
        {
            int l = i, r = i + len - 1;
            f[l][r] = 0x3f3f3f3f;
            for (int k = l; k < r; k ++ )
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }

    cout << f[1][n] << endl;

    return 0;
}