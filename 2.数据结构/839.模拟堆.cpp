#include <iostream>

using namespace std;

const int N = 100010;

int n;
int h[N], hp[N], ph[N], cnt, idx = 1;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void up(int u)
{
    while (u >> 1 && h[u >> 1] > h[u])
    {
        heap_swap(u >> 1, u);
        u >>= 1;
    }
}

void down(int u)
{
    int t = u;
    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

int main()
{
    cin >> n;

    while (n -- )
    {
        string op;
        int k, x;
        cin >> op;

        if (op == "I")
        {
            cin >> x;
            h[ ++ cnt] = x;
            ph[idx] = cnt, hp[cnt] = idx ++ ;
            up(cnt);
        }
        else if (op == "PM") cout << h[1] << endl;
        else if (op == "DM") 
        {
            heap_swap(1, cnt -- );
            down(1);
        }
        else if (op == "D")
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, cnt -- );
            down(k), up(k);
        }
        else 
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    
    return 0;
}