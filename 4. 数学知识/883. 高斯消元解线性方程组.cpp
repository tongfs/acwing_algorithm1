#include <iostream>
#include <cmath>

using namespace std;

const int N = 110;
const double EPS = 1e-6;

int n;
double a[N][N];

int gauss()
{
    int c, r;
    for (c = 0, r = 0; c < n; c ++ )
    {
        int t = r;
        for (int i = r + 1; i < n; i ++ )
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        
        if (fabs(a[t][c]) < EPS) continue;    // 当前列的系数全部为0

        for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);  // 将当前行换到最上面
        for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // 将当前行的第一个系数调整为1
        for (int i = r + 1; i < n; i ++ )
            if (fabs(a[i][c]) > EPS)    // 如果当前行的第一个系数不为0，则将其调整为0
                for (int j = n; j >= c; j -- )
                    a[i][j] -= a[r][j] * a[i][c];

        r ++ ;  // 记录了处理了多少行
    }

    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (fabs(a[i][n]) > EPS)
                return -1; // 无解

        return 1; // 有无穷多解
    }

    // 有唯一解
    for (int i = n - 1; i >= 0; i -- )
        for (int j = i + 1; j < n; j ++ )
            a[i][n] -= a[i][j] * a[j][n];

    return 0;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ )
        for (int j = 0; j <= n; j ++ )
            cin >> a[i][j];
    
    int t = gauss();

    if (t == 0)
    {
        for (int i = 0; i < n; i ++ )
        {
            if (fabs(a[i][n]) < EPS) a[i][n] = 0;
            printf("%.2lf\n", a[i][n]);
        }
    }
    else if (t == 1) cout << "Infinite group solutions" << endl;
    else cout << "No solution" << endl;

    return 0;
}