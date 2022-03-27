#include <iostream>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

LL qpow(int a, int k, int p)
{
    LL res = 1;
    while (k)
    {
        if (k & 1) res = res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    int res = 1;
    for (int i = n * 2, j = 1; j <= n; i -- , j ++ )
    {
        res = (LL)res * i % MOD;
        res = (LL)res * qpow(j, MOD - 2, MOD) % MOD;
    }

    cout << res * qpow(n + 1, MOD - 2, MOD) % MOD << endl;

    return 0;
}