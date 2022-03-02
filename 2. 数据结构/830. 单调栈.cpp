#include <iostream>

using namespace std;

const int N = 100010;

int n;
int stk[N], tt;

int main()
{
    cin >> n;

    // 单调增加
    for (int i = 0; i < n; i ++ ) 
    {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x) tt -- ;
        cout << (tt ? stk[tt] : -1) << ' ';
        stk[ ++ tt] = x;
    }

    cout << endl;
    return 0;
}