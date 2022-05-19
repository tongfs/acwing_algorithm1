#include <iostream>

using namespace std;

void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
    {
        int s = 0;
        while (x % i == 0) x /= i, s++;
        if (s) cout << i << ' ' << s << endl;
    }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;
        divide(x);
    }
    
    return 0;
}