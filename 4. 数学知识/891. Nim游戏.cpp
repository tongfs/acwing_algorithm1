#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t;
        cin >> t;
        res ^= t;
    }

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}