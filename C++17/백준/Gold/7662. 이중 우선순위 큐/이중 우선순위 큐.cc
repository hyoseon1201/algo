#include <bits/stdc++.h>

using namespace std;

int t;

void solve() 
{
    int k;
    cin >> k;
    multiset<int> ms;

    while (k--) 
    {
        char op;
        int n;
        cin >> op >> n;

        if (op == 'I') 
        {
            ms.insert(n);
        }
        else 
        {
            if (ms.empty()) continue;
            if (n == 1) 
            {
                auto it = prev(ms.end());
                ms.erase(it);
            }
            else 
            {
                ms.erase(ms.begin());
            }
        }
    }

    if (ms.empty()) cout << "EMPTY\n";
    else cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}