#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

string start;

int bfs()
{
    string end = "12345678x";

    queue<string> q;
    unordered_map<string, int> d;

    q.push(start);
    d[start] = 0;

    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1};

    while (q.size())
    {
        string t = q.front();
        q.pop();

        int dist = d[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;
        for (int i = 0; i < 4; i ++ )
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[k], t[a * 3 + b]);
                if (!d.count(t))
                {
                    if (t == end) return dist + 1;
                    d[t] = dist + 1;
                    q.push(t);
                }
                swap(t[k], t[a * 3 + b]);
            }
        }
    }

    return -1;
}

int main()
{
    for (int i = 0; i < 9; i ++ ) 
    {
        char c;
        cin >> c;
        start += c;
    }

    cout << bfs() << endl;

    return 0;
}