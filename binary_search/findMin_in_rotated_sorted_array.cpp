#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    int ans = nums[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int prev = (mid - 1 + n) % n;
        int next = (mid + 1) % n;

        if (nums[mid] <= nums[prev] && nums[mid] <= nums[next])
        {
            return nums[mid];
        }
        else if (nums[mid] >= nums[low])
        {
            ans = min(nums[low], ans);
            low = mid + 1;
        }
        else
        {
            ans = min(nums[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {3, 4, 2};
    cout << findMin(nums) << endl;
}