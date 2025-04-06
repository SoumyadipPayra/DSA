#include <bits/stdc++.h>
using namespace std;

vector<int> next_greater(vector<int> &arr)
{
    stack<int> s;
    vector<int> result(arr.size(), -1);
    s.push(arr[arr.size() - 1]);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (s.top() >= arr[i])
        {
            result[i] = s.top();
            s.push(arr[i]);
        }
        else
        {
            while (!s.empty() && s.top() < arr[i])
            {
                s.pop();
            }
            if (!s.empty())
            {
                result[i] = s.top();
            }
            s.push(arr[i]);
        }
    }
    return result;
}

int main()
{
    vector<int> arr = {4, 12, 5, 5, 1, 2, 5, 3, 1, 2, 4, 6};
    vector<int> result = next_greater(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " -> " << result[i] << endl;
    }
    return 0;
}