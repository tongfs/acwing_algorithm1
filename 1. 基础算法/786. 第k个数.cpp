#include <iostream>

using namespace std;

const int N = 100010;

int n, k;
int a[N];

int quick_sort(int l, int r)
{
    if (l >= r) return a[l];

    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j)
    {
        while (a[ ++ i] < x);
        while (a[ -- j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    if (j + 1 >= k) return quick_sort(l, j);
    else return quick_sort(j + 1, r);
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    cout << quick_sort(0, n - 1) << endl;
    return 0;
}