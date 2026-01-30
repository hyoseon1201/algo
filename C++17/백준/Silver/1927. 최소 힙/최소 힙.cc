#include <bits/stdc++.h>

using namespace std;

int main() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n;
cin >> n;

priority_queue<int, vector<int>, greater<int>> min_heap;

while (n--)
{
    int x;
    cin >> x;

    if (x > 0)
    {
        min_heap.push(x);
    }
    else
    {
        if (min_heap.empty())
        {
            cout << "0\n";
        }
        else
        {
            cout << min_heap.top() << "\n";
            min_heap.pop();
        }
    }
}

return 0;
}