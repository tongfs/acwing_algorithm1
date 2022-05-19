#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N];

void quick_sort(int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = a[l + r >> 1];
    while (i < j)
    {
        while (a[ ++ i] < x);
        while (a[ -- j] > x);
        if (i < j) swap(a[i], a[j]);
    }

    // 当x取值靠左时，应该用j，不能用 i-1，此时有 i=j+1 或 i=j
    quick_sort(l, j);
    quick_sort(j + 1, r);
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    quick_sort(0, n - 1);

    for (int i = 0; i < n; i ++ ) cout << a[i] << ' ';
    cout << endl;
    
    return 0;
}