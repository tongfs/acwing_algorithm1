#include <iostream>
#include <algorithm>

using namespace std;

const int N = 510;

int n;
int a[N][N], f[N][N];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= i; j ++ )
            cin >> a[i][j];

    for (int i = n; i >= 1; i -- )
        for (int j = 1; j <= i; j ++ )
            f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + a[i][j];
    
    cout << f[1][1] << endl;

    return 0;
}
