#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

int n;
vector<PII> segs;

int main()
{
    cin >> n;

    while (n -- )
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    sort(segs.begin(), segs.end());

    int res = 0;
    int st = segs[0].first, ed = segs[0].second;

    for (auto i : segs)
    {
        int l = i.first, r = i.second;
        if (l > ed) 
        {
            res ++ ;
            st = l, ed = r;
        }
        else ed = max(ed, r);
    }

    res ++ ;
    cout << res << endl;

    return 0;
}