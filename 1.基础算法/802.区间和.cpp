#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 300010;

int n, m;
int s[N];

vector<int> alls;
vector<PII> add, segs;

int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }

    return l + 1;
}

int main()
{
    cin >> n >> m;

    while (n -- )
    {
        int x, c;
        cin >> x >> c;

        alls.push_back(x);
        add.push_back({x, c});
    }

    while (m -- )
    {
        int l, r;
        cin >> l >> r;

        alls.push_back(l);
        alls.push_back(r);
        segs.push_back({l, r});
    }

    // 去重并排序
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    sort(alls.begin(), alls.end());

    // 插入数值
    for (auto i : add)
    {
        int x = find(i.first);
        s[x] += i.second;
    }

    // 求前缀和
    for (int i = 1; i <= alls.size(); i ++ ) s[i] += s[i - 1];

    for (auto i : segs)
    {
        int l = find(i.first), r = find(i.second);
        cout << s[r] - s[l - 1] << endl;
    }

    return 0;
}