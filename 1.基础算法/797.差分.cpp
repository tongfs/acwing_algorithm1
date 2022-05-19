#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int a[N], b[N];

void insert(int l, int r, int c)
{
    b[l] += c;
    b[r + 1] -= c;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) insert(i, i, a[i]);

    // 差分
    while (m -- )
    {
        int l, r, c;
        cin >> l >> r >> c;
        insert(l, r, c);
    }

    // 前缀和
    for (int i = 1; i <= n; i ++ ) b[i] += b[i - 1];

    for (int i = 1; i <= n; i ++ ) cout << b[i] << ' ';
    cout << endl;

    return 0;
}