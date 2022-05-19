#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (x / i != i) res.push_back(x / i);
        }
    }
    
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;

    while (n -- )
    {
        int x;
        cin >> x;

        auto res = get_divisors(x);
        for (auto i : res) cout << i << ' ';
        cout << endl;
    }
    
    return 0;
}