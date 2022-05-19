#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n;
int a[N], f[N];

// 状态表示：f[i]: 所有以第i个数结尾的上升子序列的最大长度
// 状态计算：前 i-1 个数，如果比 i 小，则可以更新 f[i]

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    for (int i = 1; i <= n; i ++ )
    {
        f[i] = 1;
        for (int j = 1; j < i; j ++ )
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }

    int res = f[1];
    for (int i = 2; i <= n; i ++ ) res = max(res, f[i]);
    
    cout << res << endl;

    return 0;
}
