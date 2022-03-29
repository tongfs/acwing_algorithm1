#include <cstring>
#include <iostream>

using namespace std;

const int N = 12, M = 1 << N;

int n, m;
long long f[N][M];
bool st[M];     // 表示当前状态是否不存在连续奇数个空白

// 状态表示：f[i][j]: 现在要摆放第i列，上一列有j（二进制形式表示的状态）伸出来了的方案数

int main()
{
    while (cin >> n >> m, n || m)
    {
        memset(f, 0, sizeof f);

        // 预处理每一种状态
        // 预处理的作用在于，先得出 1 << n 种状态中，哪些是可行的，哪些不可行
        for (int i = 0; i < 1 << n; i ++ )  // 枚举每一种状态
        {
            st[i] = true;   // 默认状态可行
            int cnt = 0;    // 当前这一段连续0的个数
            for (int j = 0; j < n; j ++ )
                if (i >> j & 1)
                {
                    if (cnt & 1) st[i] = false;
                    cnt = 0;
                }
                else cnt ++ ;
            
            if (cnt & 1) st[i] = false;
        }

        f[0][0] = 1;
        for (int i = 1; i <= m; i ++ )
            for (int j = 0; j < 1 << n; j ++ )
                for (int k = 0; k < 1 << n; k ++ )
                    if ((j & k) == 0 && st[j | k])
                        f[i][j] += f[i - 1][k];

        cout << f[m][0] << endl;
    }

    return 0;    
}
