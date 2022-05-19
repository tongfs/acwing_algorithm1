#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010, MOD = 1e9 + 7;

int fact[N], infact[N];

LL qpow(int a, int p, int m)
{
    LL res = 1;
    while (p)
    {
        if (p & 1) res = res * a % m;
        p >>= 1;
        a = (LL)a * a % m;
    }
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;

    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (LL)fact[i - 1] * i % MOD;
        infact[i] = (LL)infact[i - 1] * qpow(i, MOD - 2, MOD) % MOD;
    }
}

// 2. 预处理阶乘（O(nlogMOD)）
int main()
{
    init();

    int n;
    cin >> n;

    while (n -- )
    {
        int a, b;
        cin >> a >> b;
        cout << (LL)fact[a] * infact[b] % MOD * infact[a - b] % MOD << endl;
    }
    
    return 0;
}