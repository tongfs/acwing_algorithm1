#include <cstring>
#include <iostream>

using namespace std;

const int N = 310;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int n, m;
int h[N][N];
int f[N][N];

/*
 * 状态表示：
 *      集合：f[i][j]: 所有从 (i, j) 开始滑的路径长度
 *      属性：最大值
 */

int dfs(int x, int y) {
    if (f[x][y]) return f[x][y];

    f[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a >= 0 && a < n && b >= 0 && b < m && h[a][b] < h[x][y])
            f[x][y] = max(f[x][y], dfs(a, b) + 1);
    }

    return f[x][y];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> h[i][j];

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, dfs(i, j));

    cout << res << endl;

    return 0;
}