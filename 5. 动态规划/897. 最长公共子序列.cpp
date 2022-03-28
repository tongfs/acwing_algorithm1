#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int f[N][N];
char a[N], b[N];

// 状态表示：f[i][j]: 在第一个序列的前 i 个字母中出现且在第二个序列的前 j 个字母中出现的子序列长度的最大值
// 状态计算：若用 01 来表示是否分别以 i 和 j 结尾，则 01、10 不完全对应 f[i - 1][j] 和 f[i][j - 1]

int main()
{
    cin >> n >> m >> a + 1 >> b + 1;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            if (a[i] == b[j]) f[i][j] = f[i - 1][j - 1] + 1;
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]);

    cout << f[n][m] << endl;

    return 0;
}