#include <iostream>
#include <cstring>
#include <unordered_set>

using namespace std;

const int N = 110, M = 10010;

int k, n;
int s[N], f[M];

int sg(int x)
{
    if (f[x] != -1) return f[x];

    unordered_set<int> S;

    for (int i = 0; i < k; i ++ )
        if (x >= s[i])
            S.insert(sg(x - s[i]));

    for (int i = 0; ; i ++ )
        if (!S.count(i))
            return f[x] = i;
}

int main()
{
    cin >> k;
    for (int i = 0; i < k; i ++ ) cin >> s[i];

    int res = 0;
    memset(f, -1, sizeof f);

    cin >> n;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        res ^= sg(x);
    }

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}