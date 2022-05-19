#include <iostream>
#include <vector>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n;
int phi[N];     // 这里用 int 就可以了，欧拉函数值不会超过 i 本身
bool st[N];
vector<int> primes;

void get_eulers()
{
    phi[1] = 1; // 1 需要特判
    
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes.push_back(i);
            phi[i] = i - 1; // 如果 i 是质数，则欧拉函数的值为 i - 1
        }

        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            // 计算非质数的欧拉函数值
            if (i % primes[j] == 0)
            {
                phi[t] = phi[i] * primes[j];
                break;
            }
            phi[t] = phi[i] * (primes[j] - 1);
        }
    }
}

int main()
{
    cin >> n;

    get_eulers();

    LL res = 0;
    for (int i = 1; i <= n; i ++ ) res += phi[i];

    cout << res << endl;

    return 0;
}