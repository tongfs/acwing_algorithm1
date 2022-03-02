#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];
bool st[N];

void dfs(int u)
{
    if (u == n)
    {
        for (int i = 0; i < n; i++) cout << path[i] << ' ';
        cout << endl;

        return;
    }

    for (int i = 0; i < n; i ++ )
    {
        if (!st[i])
        {
            st[i] = 1;
            path[u] = i + 1;
            dfs(u + 1);
            st[i] = 0;
        }
    }
}

int main()
{
    cin >> n;

    dfs(0);

    return 0;
}