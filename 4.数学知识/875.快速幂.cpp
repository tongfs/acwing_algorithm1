#include <iostream>

using namespace std;

typedef long long LL;

// 迭代写法
LL qpow1(int a, int b, int p)
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

// 递归写法
LL qpow2(int a, int b, int p)
{
    if (b == 0) return 1;
    
    if (b & 1) return qpow2(a, b - 1, p) * a % p;
    
    LL t = qpow2(a, b / 2, p);
    return t * t % p;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int a, b, p;
        cin >> a >> b >> p;
        
        cout << qpow1(a, b, p) << endl;    
    }
    
    return 0;
}