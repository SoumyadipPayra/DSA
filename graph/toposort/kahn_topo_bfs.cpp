#include <bits/stdc++.h>
using namespace std;

class KahnSolution {
public:
  vector<int> topoSort(int V, vector<vector<int>> &adj){
    vector<int> res;
    vector<int> indegree(V, 0);

    for (int i = 0; i<V; i++){
      for (auto &it : adj[i]) indegree[it]++;
    }

    queue<int> q;
    for (int i=0; i<V; i++) {
      if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()){
      int temp = q.front();
      q.pop();
      res.push_back(temp);

      for (auto it : adj[temp]) {
        indegree[it]--;
        if (indegree[it] == 0) q.push(it);
      }
    }
    return res;
  }

  bool hasCycle(int V, vector<vector<int>> &adj) {
    return topoSort(V, adj).size() != V;
  }
};


int main() {
    bool topoSort = false;
    if (topoSort) {
      vector<vector<int>> adj = {{1, 2}, {}, {3}, {1}, {0, 1}, {0, 2, 4}};
      int V = adj.size();
      KahnSolution obj;
      vector<int> ans = obj.topoSort(V, adj);

      for (auto node : ans) {
        cout << node << " ";
      }
      cout << endl;
    } else {
      vector<vector<int>> cycleadj = {{1, 2}, {5}, {0}, {1}, {0, 1}, {0, 2, 4}};
      int V = cycleadj.size();
      KahnSolution obj;
      cout << "has cycle : "<< obj.hasCycle(V, cycleadj) << endl;
    }
    return 0;
}
