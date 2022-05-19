#include <iostream>
#include <algorithm>

using namespace std;

const int N = 6010;

int n;
int happy[N];
int h[N], e[N], ne[N], idx = 1;
int f[N][2];
bool has_father[N];

/*
 * 状态表示：
 *      集合：
 *          f[u][0]: 所有从以 u 为根的子树中选择，并且不选 u 这个点的方案
 *          f[u][1]: 所有从以 u 为根的子树中选择，并且选择 u 这个点的方案
 *      属性：
 *          最大值 
 */

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u)
{
    f[u][1] = happy[u];

    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; i ++ ) cin >> happy[i];

    for (int i = 0; i < n - 1; i ++ )
    {
        int a, b;
        cin >> a >> b;
        has_father[a] = true;   // 记录是否有父亲节点
        add(b, a);
    }

    // 找到树的根节点
    int root = 0;
    while (has_father[ ++ root]);

    dfs(root);

    cout << max(f[root][0], f[root][1]) << endl;

    return 0;
}
