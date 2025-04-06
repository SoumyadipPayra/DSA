#include <bits/stdc++.h>
using namespace std;

string start_seq = "0";

string get_kth_bit_nth_seq(int n, int k, vector<int> &seqsize)
{
  if (k == 0)
    return "0";
  if (k == seqsize[n] / 2)
    return "1";
  else if (k > seqsize[n] / 2)
  {
    return get_kth_bit_nth_seq(n - 1, seqsize[n] - k - 1, seqsize) == "0" ? "1" : "0";
  }
  else
  {
    return get_kth_bit_nth_seq(n - 1, k, seqsize);
  }
}

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> seq_sizes = vector<int>(n + 1, 0);
  seq_sizes[0] = 1;
  for (int i = 1; i <= n; i++)
  {
    seq_sizes[i] = seq_sizes[i - 1] * 2 + 1;
    // cout << i <<"\t"<< seq_sizes[i]<<endl;
  }
  cout << get_kth_bit_nth_seq(n, k, seq_sizes) << endl;
}
