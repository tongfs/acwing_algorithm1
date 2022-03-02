#include <iostream>

using namespace std;

const int N = 100010;

int n;
int e[N], l[N], r[N], idx = 2;

void add(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx, r[k] = idx ++ ;
}

int main()
{
    // 初始化头尾结点
    l[1] = 0, r[0] = 1;

    cin >> n;

    while (n -- )
    {
        string op;
        int k, x;
        cin >> op;

        if (op == "L") 
        {
            cin >> x;
            add(0, x);
        }
        else if (op == "R")
        {
            cin >> x;
            add(l[1], x);
        }
        else if (op == "D")
        {
            cin >> k;
            l[r[k + 1]] = l[k + 1];
            r[l[k + 1]] = r[k + 1];
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            add(l[k + 1], x);
        }
        else 
        {
            cin >> k >> x;
            add(k + 1, x);
        }
    }
    
    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;
    
    return 0;
}