#include <iostream>

using namespace std;

const int N = 100010;

int n;
int q[N], hh, tt = -1;

int main()
{
    cin >> n;

    while (n -- )
    {
        string op;
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            q[ ++ tt] = x;
        }
        else if (op == "pop") hh ++ ;
        else if (op == "empty") cout << (hh > tt ? "YES" : "NO") << endl;
        else cout << q[hh] << endl;
    }

    return 0;
}