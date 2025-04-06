#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
	void dfs(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> &adj) {
		vis[node] = 1;
		for (auto it : adj[node]) {
			if (!vis[it]) dfs(it, vis, st, adj);
		}
		st.push(node);
	}

public:

	vector<int> topoSort(int V, vector<vector<int>> &adj)
	{
		vector<int> vis = vector<int> (V, 0);
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, vis, st, adj);
			}
		}

		vector<int> ans;
		while (!st.empty()) {
			ans.push_back(st.top());
			st.pop();
		}
		return ans;
	}
};

int main() {
  vector<vector<int>> adj = {{1}, {}, {3}, {1}, {0, 1}, {0, 2}};
  int V = adj.size();
  Solution obj;
  vector<int> ans = obj.topoSort(V, adj);

  for (auto node : ans) {
    cout << node << " ";
  }
  cout << endl;

  return 0;
}
