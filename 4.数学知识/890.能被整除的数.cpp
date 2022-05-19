#include <iostream>

using namespace std;

typedef long long LL;

const int N = 20;

int n, m;
int p[N];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ) cin >> p[i];

    int res = 0;
    for (int i = 1; i < 1 << m; i ++ )
    {
        LL t = 1;
        int flag = -1;
        for (int j = 0; j < m; j ++ )
            if (i >> j & 1)
            {
                if ((t = t * p[j]) < n)
                {
                    t = -1;
                    break;
                }
                flag = -flag;
            }

        if (t != -1) res += n / t * flag;
    }
    
    cout << res << endl;

    return 0;
}