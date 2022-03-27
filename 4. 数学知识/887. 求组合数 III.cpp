#include <iostream>

using namespace std;

typedef long long LL;

int p;

int qpow(int a, int k, int m)
{
    LL res = 1;
    while (k)
    {
        if (k & 1) res = res * a % m;
        k >>= 1;
        a = (LL)a * a % m;
    }
    return res;
}

int C(int a, int b)
{
    int res = 1;
    for (int i = 1, j = a; i <= b; i ++ , j -- )
    {
        res = (LL)res * j % p;
        res = (LL)res * qpow(i, p - 2, p) % p;
    }
    return res;
}

int lucas(LL a, LL b)
{
    if (a < p) return C(a, b);
    return (LL)C(a % p, b % p) * lucas(a / p, b / p) % p;
}

// 3. Lucas 定理
int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        LL a, b;
        cin >> a >> b >> p;
        cout << lucas(a, b) << endl;
    }

    return 0;
}