#include <bits/stdc++.h>
using namespace std;

class W
{
public:
  W(int n, int w, int h) : node(n), weight(w), hop(h) {};
  int weight;
  int node;
  int hop;
};

class CheapestFlightWithKStops
{
public:
  static int getCheapest(vector<vector<pair<int, int>>> &v, int &src, int &dst, int &k)
  {
    priority_queue<W, vector<W>, function<bool(W, W)>> pq([](const W &a, const W &b)
                                                          { if (a.hop == b.hop) return a.weight > b.weight;
                                                            return a.hop < b.hop; });

    vector<int> dist = vector<int>(v.size(), 1e9);
    dist[src] = 0;
    pq.push(W(src, 0, k + 1));

    cout << endl;
    while (!pq.empty())
    {
      W temp = pq.top();
      pq.pop();
      cout << temp.node << " " << temp.weight << " " << temp.hop << endl;

      if (!temp.hop)
        continue;

      for (auto &it : v[temp.node])
      {
        int nextNode = it.first;
        int wt = it.second;

        if (dist[nextNode] > dist[temp.node] + wt)
        {
          dist[nextNode] = dist[temp.node] + wt;
          cout << "dist[" << nextNode << "] = " << dist[nextNode] << endl;
          pq.push(W(nextNode, dist[nextNode], temp.hop - 1));
        }
      }
    }

    return dist[dst] == 1e9 ? -1 : dist[dst];
  }
};

int main()
{
  vector<vector<pair<int, int>>> adj(4);
  adj[0].push_back({1, 1});
  adj[0].push_back({2, 5});
  adj[1].push_back({2, 1});
  adj[2].push_back({3, 1});

  int src = 0;
  int dst = 3;
  int k = 1;

  cout << "Cheapest flight cost with at most " << k << " stops: "
       << CheapestFlightWithKStops::getCheapest(adj, src, dst, k) << endl;
  return 0;
}
