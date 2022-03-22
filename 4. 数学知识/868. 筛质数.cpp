#include <iostream>
#include <vector>

using namespace std;

const int N = 1000010;

int n;
bool st[N];
vector<int> primes;

// 埃式筛（朴素筛优化）
void get_primes1()
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j <= n; j += i) st[j] = true;
    }
}

// 线性筛
void get_primes2()
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
            // 如果可以被整除，就说明 i 不是质数
            // 那么下一轮 primes[j + 1] * i 的最小质因子就不是 primes[j] 了， 而应该是 i 的最小质因子
        }
    }
}

int main()
{
    cin >> n;

    get_primes1();
    // get_primes2();

    cout << primes.size() << endl;

    return 0;
}
