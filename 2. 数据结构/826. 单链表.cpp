#include <iostream>

using namespace std;

const int N = 100010;

int n;
int e[N], ne[N], idx = 1;

void add(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
}

int main()
{
    cin >> n;

    while (n -- )
    {
        char op;
        int k, x;
        cin >> op;

        if (op == 'H')
        {
            cin >> x;
            add(0, x);
        }
        else if (op == 'D')
        {
            cin >> k;
            ne[k] = ne[ne[k]];
        }
        else{
            cin >> k >> x;
            add(k, x);
        }
    }

    for (int i = ne[0]; i; i = ne[i]) cout << e[i] << ' ';
    cout << endl;
    
    return 0;
}