#include <iostream>

using namespace std;

const int N = 1010, MOD = 1e9 + 7;

int n;
int f[N], dp[N][N];

/*
 * 背包问题：有容量为 n 的背包，有 n 个物品，物品的体积分别为 1~n，求恰好可以装满背包的方案数
 * 状态表示：f[i][j]: 从前 i 个物品中选，总体积恰好是 j 的方案数
 */
int method1()
{
    f[0] = 1;
    for (int i = 1; i <= n; i ++ )
        for (int j = i; j <= n; j ++ )
            f[j] = (f[j] + f[j - i]) % MOD;

    return f[n];
}

/*
 * 从集合中的最小数字是否是1来考虑
 * 状态表示：dp[i][j]: 总和是 i ，并且恰好表示成 j 个数的和的方案数
 * 状态计算：dp[i][j] 可以看成两个集合，一个集合中最小值是1，一个集合中最小值大于1
 */
int method2()
{
    dp[1][1] = 1;
    for (int i = 2; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - j][j]) % MOD;

    int res = 0;
    for (int i = 1; i <= n; i ++ ) res = (res + dp[n][i]) % MOD;

    return res;
}

int main()
{
    cin >> n;
    cout << method2() << endl;

    return 0;
}