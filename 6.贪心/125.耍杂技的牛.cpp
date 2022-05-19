#include <iostream>
#include <algorithm>

using namespace std;

const int N = 50010;

struct Cow
{
    int w, s;

    bool operator < (const Cow &cow) const 
    {
        return w + s < cow.s + cow.w;
    }
}cows[N];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i ++ )
    {
        int w, s;
        cin >> w >> s;
        cows[i] = {w, s};
    }

    sort(cows, cows + n);

    int res = -2e9, sum = 0;
    for (int i = 0; i < n; i ++ )
    {
        auto c = cows[i];
        res = max(res, sum - c.s);
        sum += c.w;
    }

    cout << res << endl;

    return 0;
}
