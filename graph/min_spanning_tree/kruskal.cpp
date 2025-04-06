#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
  vector<int> parent;
  vector<int> size;

public:
  DSU(int n)
  {
    parent = vector<int>(n + 1);
    size = vector<int>(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int GetParent(int i)
  {
    if (parent[i] == i)
      return i;
    return parent[i] = GetParent(parent[i]);
  }

  void UnionBySize(int i, int j)
  {
    int par_i = GetParent(i);
    int par_j = GetParent(j);

    if (par_i == par_j)
      return;

    if (size[par_i] < size[par_j])
    {
      parent[par_i] = par_j;
      size[par_j] += size[par_i];
    }
    else
    {
      parent[par_j] = par_i;
      size[par_i] += size[par_j];
    }
    return;
  }
};

struct Edge
{
  int weight;
  int source;
  int dest;
};

class Kruskal
{
private:
  int size;
  vector<Edge> edges;

public:
  Kruskal(vector<vector<pair<int, int>>> &adj, int n)
  {
    size = n;
    for (int i = 0; i < n; i++)
    {
      int source = i;
      for (auto it : adj[i])
      {
        int dest = it.first;
        int wt = it.second;
        Edge temp_edge = {wt, source, dest};
        edges.push_back(temp_edge);
      }
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });
  }

  void ConstructMinSpanningTree()
  {
    DSU dsu(size);
    int total_wt = 0;
    char spanning_tree[1024];
    for (int i = 0; i < edges.size(); i++)
    {
      Edge edge = edges[i];
      if (dsu.GetParent(edge.source) == dsu.GetParent(edge.dest))
        continue;
      total_wt += edge.weight;
      dsu.UnionBySize(edge.source, edge.dest);

      cout << "source : " << edge.source << " dest : " << edge.dest << " weight : " << edge.weight << "\n"
           << "\t";
    }
    cout << "weight of the spanning tree : " << total_wt << endl;
  }
};

int main()
{

  vector<vector<pair<int, int>> adj = {
    {},
  }
  return 0;
}
