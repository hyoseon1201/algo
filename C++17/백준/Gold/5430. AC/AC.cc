#include <bits/stdc++.h>

using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;

	while (t--)
	{
		string funcStr;
		int n;
		string arrStr;
		cin >> funcStr >> n >> arrStr;

		deque<int> dq;

		string temp = "";

		for (char c : arrStr)
		{
			if (isdigit(c))
			{
				temp += c;
			}
			else
			{
				if (!temp.empty())
				{
					dq.push_back(stoi(temp));
					temp = "";
				}
			}
		}

		bool isReversed = false;
		bool error = false;

		for (char cmd : funcStr)
		{
			if (cmd == 'R')
			{
				isReversed = !isReversed;
			}
			else if (cmd == 'D')
			{
				if (dq.empty())
				{
					error = true;
					break;
				}

				if (!isReversed)
				{
					dq.pop_front();
				}
				else
				{
					dq.pop_back();
				}
			}
		}

		if (error)
		{
			cout << "error\n";
		}
		else
		{
			cout << "[";
			if (isReversed)
			{
				for (auto it = dq.rbegin(); it != dq.rend(); ++it) 
				{
					cout << *it;
					if (it + 1 != dq.rend()) cout << ",";
				}
			}
			else
			{
				for (auto it = dq.begin(); it != dq.end(); ++it) 
				{
					cout << *it;
					if (it + 1 != dq.end()) cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}