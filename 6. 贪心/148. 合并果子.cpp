#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i ++ )
    {
        int x;
        cin >> x;
        heap.push(x);
    }

    int res = 0;
    while (heap.size() > 1)
    {
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        int t = a + b;
        res += t;
        heap.push(t);
    }
    
    cout << res << endl;

    return 0;
}