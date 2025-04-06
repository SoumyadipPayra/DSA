#include <bits/stdc++.h>
using namespace std;

int maxSquare(vector<vector<int>> &mat) {
  int col = mat[0].size();
  int row = mat.size();
  vector<vector<int>> dp(row, vector<int> (col, 0));

  int maxSquareSize = 0;

  for(int i=0; i<row; i++) {
    dp[i][0] = mat[i][0];
    maxSquareSize = max(maxSquareSize, mat[i][0]);
  }

  for (int j=1; j<col; j++) {
    dp[0][j] = mat[0][j];
    maxSquareSize = max(maxSquareSize, mat[0][j]);
  }


  for(int i=1; i<row; i++){
    for(int j=1; j<col; j++){
      if (mat[i][j]) {
        dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
        maxSquareSize = max(maxSquareSize, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }
  return maxSquareSize;
}

int main()
{
    vector<vector<int>> mat = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}};

    cout << maxSquare(mat) << endl;
}
