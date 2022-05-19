#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 1000010;

int n;
int a[N];

int main()
{
    cin >> n;

    for (int i = 0;  i < n; i ++ ) cin >> a[i];

    sort(a, a + n);

    LL res = 0, t = n / 2;
    for (int i = 0; i <= t; i ++ ) res += a[t] - a[i];
    for (int i = t + 1; i < n; i ++ ) res += a[i] - a[t];

    cout << res << endl;
    
    return 0;
}