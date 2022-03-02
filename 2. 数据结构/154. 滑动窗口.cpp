#include <iostream>

using namespace std;

const int N = 1000010;

int n, k;
int a[N], q[N], hh, tt = -1;

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    // 求最小值时要保证单调增加
    for (int i = 0; i < n; i ++ )
    {
        // 判断队头是否已经出窗口
        if (tt >= hh && i - k + 1 > q[hh]) hh ++ ;
        while (tt >= hh && a[q[tt]] >= a[i]) tt -- ;
        q[ ++ tt] = i;
        if (i - k + 1 >= 0) cout << a[q[hh]] << ' ';
    }
    cout << endl;

    // 求最大值时要保证单调减少
    hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ )
    {
        if (tt >= hh && i - k + 1 > q[hh]) hh ++ ;
        while (tt >= hh && a[q[tt]] <= a[i]) tt -- ;
        q[ ++ tt] = i;
        if (i - k + 1 >= 0) cout << a[q[hh]] << ' ';
    }
    cout << endl;

    return 0;
}