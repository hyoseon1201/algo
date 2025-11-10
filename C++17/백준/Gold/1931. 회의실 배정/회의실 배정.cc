#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int ret = 0;
	vector<pair<int, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int start, end;
		cin >> start >> end;

		v.push_back({ start, end });
	}

	sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) 
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		});

	int currentTime = v[0].second;
	ret = 1;

	for (int i = 1; i < n; i++)
	{
		if (v[i].first >= currentTime)
		{
			ret++;
			currentTime = v[i].second;
		}
	}

	cout << ret << endl;

	return 0;
}