#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

vector<PII> segs;

int main()
{
    int st, ed;
    cin >> st >> ed;

    int n;
    cin >> n;

    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        cin >> l >> r;
        segs.emplace_back(l, r);
    }

    sort(segs.begin(), segs.end());

    int cnt = 0;
    bool res = false;
    for (int i = 0; i < n; i ++ )
    {
        int j = i, max_r = -2e9;
        while (j < n && segs[j].first <= st)
        {
            max_r = max(max_r, segs[j].second);
            j ++ ;
        }
        
        // 当前右端点的最大值还不能够到起点
        if (max_r < st) break;

        // 当前右端点的最大值已经够到终点
        cnt ++ ;
        if (max_r >= ed)
        {
            res = true;
            break;
        }

        st = max_r;
        i = j - 1;
    }

    if (!res) cnt = -1;
    cout << cnt << endl;

    return 0;
}