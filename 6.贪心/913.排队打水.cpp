#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int t[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ ) cin >> t[i];

    sort(t, t + n);

    LL res = 0;
    for (int i = 0; i < n; i ++ ) res = (LL)res + t[i] * (n - i - 1);

    cout << res << endl;

    return 0;
}