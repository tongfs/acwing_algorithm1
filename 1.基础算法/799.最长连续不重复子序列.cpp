#include <iostream>

using namespace std;

const int N = 100010;

int n;
int a[N], h[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    int res = 0;
    for (int i = 0, j = 0; i < n; i ++ )
    {
        h[a[i]] ++ ;
        while (h[a[i]] > 1)
        {
            h[a[j]] -- ;
            j ++ ;
        }
        res = max(res, i - j + 1);
    }

    cout << res << endl;
    return 0;
}


// 双指针模板
bool check(int i, int j) {}

void my_template()
{
    for (int i = 0, j = 0; i < n; i ++ )
    {
        while (j < i && check(i, j)) j ++ ;
        // 每道题的具体逻辑
    }
}