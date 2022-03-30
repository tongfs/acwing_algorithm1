#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

int main()
{
    int n;
    cin >> n;

    vector<PII> segs;
    for (int i = 0; i < n; i ++ )
    {
        int a, b;
        cin >> a >> b;
        segs.push_back({a, b});
    }

    sort(segs.begin(), segs.end());

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i ++ )
    {
        int l = segs[i].first, r = segs[i].second;
        if (heap.empty() || heap.top() >= l) heap.push(r);
        else
        {
            heap.pop();
            heap.push(r);
        }
    }

    cout << heap.size() << endl;

    return 0;
}