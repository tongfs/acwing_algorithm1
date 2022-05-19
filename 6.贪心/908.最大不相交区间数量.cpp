#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

struct Seg
{
    int l, r;

    bool operator < (const Seg &s) const 
    {
        return r < s.r;
    }
}segs[N];

int n;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        segs[i] = {a, b};
    }

    sort(segs, segs + n);

    int cnt = 1, cur = segs[0].r;
    for (int i = 1; i < n; i ++ )
    {
        auto s = segs[i];
        if (s.l > cur)
        {
            cnt ++ ;
            cur = s.r;
        }
    }

    cout << cnt << endl;

    return 0;
}
