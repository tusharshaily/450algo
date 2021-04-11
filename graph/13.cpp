#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, e;
	cin >> n >> e;
	
	vector<vector<int>> adj(n);

	std::vector<int> ans(n);

	vector<int> in(n, 0);

	int u, v;

	for (int i = 0; i < e; i++)
	{
		cin >> u >> v;

		adj[u].push_back(v);

		in[v]++;
	}

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		if (in[i] == 0)
		{
			q.push(i);
			ans[i] = 1;
		}
	}

	while (q.size())
	{
		int x = q.front();
		q.pop();

		for (auto j : adj[x])
		{
			in[j]--;
			if (in[j] == 0)
			{
				ans[j] = ans[x] + 1;
				q.push(j);
			}
		}
	}

	for (auto x : ans)
	{
		cout << x << " ";
	}
	return 0;
}