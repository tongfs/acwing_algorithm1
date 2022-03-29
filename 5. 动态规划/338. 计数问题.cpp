#include <iostream>
#include <vector>

using namespace std;

// 10^x
int pow10(int x)
{
    int res = 1;
    while (x -- ) res *= 10;
    return res;
}

// 求出来 num 中 l~r 位的数字是多少
int get(vector<int> num, int l, int r)
{
    int res = 0;
    for (int i = l; i >= r; i -- )
        res = res * 10 + num[i];
    
    return res;
}

// 1~n 中，有多少个 x 出现
int count(int n, int x)
{
    if (!n) return 0;

    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    n = num.size();

    int res = 0;
    for (int i = n - 1 - !x; i >= 0; i -- ) // 如果要找的是0，则应该跳过最高位
    {
        if (i != n - 1)
        {
            int t = get(num, n - 1, i + 1);
            if (x == 0) t -- ;  // 如果要找的是0，则应该去掉前导零的情况
            res += t * pow10(i);
        }

        if (num[i] == x) res += get(num, i - 1, 0) + 1;
        else if (num[i] > x) res += pow10(i);
    }

    return res;
}

int main()
{
    int a, b;
    
    while (cin >> a >> b, a || b)
    {
        if (a > b) swap(a, b);

        for (int i = 0; i < 10; i ++ )
            cout << count(b, i) - count(a - 1, i) << ' ';
        cout << endl;
    }

    return 0;
}