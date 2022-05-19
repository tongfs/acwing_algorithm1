#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long LL;

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> primes;

    while (n -- )
    {
        int x;
        cin >> x;

        for (int i = 2; i <= x / i; i ++ )
            while (x % i == 0)
            {
                x /= i;
                primes[i] ++ ;
            }
        
        if (x > 1) primes[x] ++ ;
    }

    LL res = 1;
    for (auto prime : primes)
    {
        int x = prime.first, k = prime.second;
        LL t = 1;
        while (k -- ) t = (t * x + 1) % MOD;    // 求前 n 项和
        res = res * t % MOD;
    }
    
    cout << res << endl;

    return 0;
}