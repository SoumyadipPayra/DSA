#include <bits/stdc++.h>
using namespace std;

class SlidingWindowMax
{
private:
  deque<int> dq;
  vector<int> res;
  int k;

public:
  SlidingWindowMax(int window_size)
  {
    dq = deque<int>();
    res = vector<int>();
    k = window_size;
  }
  vector<int> GetMax(vector<int> &arr)
  {
    dq = deque<int>();
    res = vector<int>();
    int n = arr.size();

    for (int i = 0; i < k; i++)
    {
      if (dq.empty())
        dq.push_back(i);
      else
      {
        while (!dq.empty() && arr[dq.back()] < arr[i])
          dq.pop_front();
        dq.push_back(i);
      }
    }

    res.push_back(arr[dq.front()]);

    for (int i = k; i < n; i++)
    {
      while (!dq.empty() && dq.front() < i - k)
        dq.pop_front();

      if (dq.empty())
        dq.push_back(i);
      else
      {
        while (!dq.empty() && arr[dq.back()] < arr[i])
          dq.pop_front();
        dq.push_back(i);
      }

      res.push_back(arr[dq.front()]);
    }

    return res;
  }
};

int main()
{
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int window_size = 2;

  SlidingWindowMax swm(window_size);
  vector<int> res = swm.GetMax(nums);

  for (int x : res)
  {
    cout << x << " ";
  }
  cout << endl;
}
