#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], q[N];

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ ) cin >> a[i];

    int len = 0;    // 记录 q[N] 里的有效元素个数
    for (int i = 0; i < n; i ++ )
    {
        int l = 0, r = len;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= a[i]) r = mid;
            else l = mid + 1;
        }

        if (len == l) len ++ ;
        q[l] = a[i];
    }

    cout << len << endl;

    return 0;
}