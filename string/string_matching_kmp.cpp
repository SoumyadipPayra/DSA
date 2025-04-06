#include <bits/stdc++.h>
using namespace std;

vector<int> lps(string &s)
{
    int prev = 0;
    int curr = 1;
    vector<int> lps_arr(s.size(), 0);
    while (curr < s.size())
    {
        if (s[curr] == s[prev])
        {
            lps_arr[curr] = prev + 1;
            curr++;
            prev++;
        }
        else
        {
            if (prev > 0)
            {
                prev = lps_arr[prev - 1];
            }
            else
            {
                lps_arr[curr] = 0;
                curr++;
            }
        }
    }
    return lps_arr;
}

int find_match_kmp(string &s, string &t)
{
    if (s.size() < t.size())
        return -1;

    vector<int> lps_arr = lps(t);
    int i = 0;
    int j = 0;
    while (i < s.size() && j < t.size())
    {
        if (t[j] == s[i])
        {
            i++;
            j++;
        }
        else
        {
            if (j > 0)
            {
                j = lps_arr[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return j == t.size() ? i - j : -1;
}

int main()
{
    string source = "abccxabccd";
    string target = "bcca";
    int id = find_match_kmp(source, target);
    cout << id << endl;
}