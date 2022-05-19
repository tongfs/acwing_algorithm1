#include <iostream>

using namespace std;

typedef long long LL;

LL qpow(int a, int b, int p)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int a, p;
        cin >> a >> p;

        if (a % p == 0) cout << "impossible" << endl;
        else cout << qpow(a, p - 2, p) << endl;
    }
    
    return 0;
}