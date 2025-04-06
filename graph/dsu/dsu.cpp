#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
  vector<int> parent;
  vector<int> size;
public:
  DSU(int n){
    parent = vector<int> (n+1);
    size = vector<int>(n+1, 1);
    for (int i=0; i<=n; i++) {
      parent[i] = i;
    }
  }

  int GetParent(int i){
    if (parent[i] == i) return i;
    return parent[i] = GetParent(parent[i]);
  }

  void UnionBySize(int i, int j) {
    int par_i = GetParent(i);
    int par_j = GetParent(j);

    if (par_i == par_j) return;

    if (size[par_i] < size[par_j]) {
      parent[par_i] = par_j;
      size[par_j] += size[par_i];
    } else {
      parent[par_j] = par_i;
      size[par_i] += size[par_j];
    }
    return;
  }

};

int main(){
  DSU dsu(10);
  dsu.UnionBySize(1, 3);
  dsu.UnionBySize(1, 5);
  dsu.UnionBySize(0, 1);

  dsu.UnionBySize(2, 6);
  dsu.UnionBySize(4, 2);

  cout << (dsu.GetParent(4) == dsu.GetParent(6)) <<endl;
  cout << (dsu.GetParent(5) == dsu.GetParent(0)) <<endl;
  cout << (dsu.GetParent(5) == dsu.GetParent(4)) <<endl;

  return 0;
}
