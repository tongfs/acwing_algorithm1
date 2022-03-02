// 开放寻址法
#include <iostream>
#include <cstring>

using namespace std;

const int N = 200003, null = 0x3f3f3f3f;

int n;
int h[N];

int find(int x)
{
    int k = (x % N + N) % N;
    while (h[k] != null && h[k] != x) k = (k + 1) % N;
    return k;
}

int main()
{
    cin >> n;

    memset(h, 0x3f, sizeof h);

    while (n -- )
    {
        char op;
        int x;
        
        cin >> op >> x;
        int k = find(x);
        
        if (op == 'I') h[k] = x;
        else cout << (h[k] == x ? "Yes" : "No") << endl;
    }
    
    return 0;
}


// 拉链法
#include <iostream>

using namespace std;

const int N = 100003;

int n;
int h[N], e[N], ne[N], idx = 1;

void insert(int x)
{
    int k = (x % N + N) % N;
    e[idx] = x, ne[idx] = h[k], h[k] = idx ++ ;
}

bool query(int x)
{
    int k = (x % N + N) % N;
    for (int i = h[k]; i; i = ne[i])
        if (e[i] == x) return true;
    
    return false;
}

int main()
{
    cin >> n;

    while (n -- )
    {
        char op;
        int x;

        cin >> op >> x;
        if (op == 'I') insert(x);
        else cout << (query(x) ? "Yes" : "No") << endl;
    }
    
    return 0;
}