#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N];

void down(int u)
{
    int t = u;
    if (u * 2 <= n && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= n && h[u * 2 + 1] < h[t]) t = u * 2 + 1;

    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> h[i];
    for (int i = n >> 1; i; i -- ) down(i);

    while (m -- )
    {
        cout << h[1] << ' ';
        h[1] = h[n -- ];
        down(1);
    }
    cout << endl;
    
    return 0;
}