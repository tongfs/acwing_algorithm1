#include <iostream>
#include <vector>

using namespace std;

const int N = 5010;

bool st[N];
vector<int> primes, cnt;
vector<int> res = {1};

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int get_cnt(int n, int p)
{
    int res = 0;
    while (n)
    {
        n /= p;
        res += n;
    }
    return res;
}

vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;

    for (int i = 0; i < A.size() || t; i ++ )
    {
        if (i < A.size()) t = A[i] * b + t;
        C.push_back(t % 10);
        t /= 10;
    }
    
    return C;
}

int main()
{
    int a, b;
    cin >> a >> b;

    // 线性筛求质数
    get_primes(a);

    // 求每个质因子的次数
    for (int i = 0; i < primes.size(); i ++ )
    {
        int p = primes[i];
        cnt.push_back(get_cnt(a, p) - get_cnt(b, p) - get_cnt(a - b, p));
    }

    // 高精度乘法
    for (int i = 0; i < primes.size(); i ++ )
        for (int j = 0; j < cnt[i]; j ++ )
            res = mul(res, primes[i]);

    for (int i = res.size() - 1; i >= 0; i -- ) cout << res[i];
    cout << endl;

    return 0;
}