#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution
{
private:
  set<string> st;
  vector<int> dp;
  bool check(string &s, int ind)
  {
    if (ind <= 0)
      return true;
    if (dp[ind] != -1)
      return dp[ind];

    bool flag = false;
    for (int i = ind - 1; i >= 0; i--)
    {
      string substr = s.substr(i, ind - i);
      if (st.find(substr) != st.end())
      {
        // cout<< "\t" << substr <<"\t";
        flag = (true && check(s, i)) || flag;
      }
    }

    return dp[ind] = flag;
  }

public:
  Solution(vector<string> &dict)
  {
    st = set<string>();
    for (auto &it : dict)
    {
      st.insert(it);
    }
  }

  bool isPossible(string &s)
  {
    dp = vector<int>(s.size() + 1, -1);
    dp[0] = 1;
    return check(s, s.size());
  }
};

int main()
{
  vector<string> dict = {"leet", "code"};
  Solution *obj = new Solution(dict);
  string s = "leetcode";
  cout << obj->isPossible(s) << endl;
  return 0;
}
