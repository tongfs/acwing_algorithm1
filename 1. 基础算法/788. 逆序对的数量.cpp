#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;

int n;
int a[N], t[N];

LL merge_sort(int l, int r)
{
    if (l >= r) return 0;

    int mid = l + r >> 1;
    LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);

    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) t[k ++ ] = a[i ++ ];
        else
        {
            res += mid - i + 1;
            t[k ++ ] = a[j ++ ];
        }
    
    while (i <= mid) t[k ++ ] = a[i ++];
    while (j <= r) t[k ++ ] = a[j ++ ];

    for (i = l, j = 0; i <= r; i ++ , j ++ ) a[i] = t[j];

    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    cout << merge_sort(0, n - 1) << endl;
    return 0;
}