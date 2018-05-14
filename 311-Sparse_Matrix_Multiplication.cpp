/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/
//res is a A.size() row and B[0].size() col matrix
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(), vector<int>(B[0].size(), 0));
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < B[0].size(); j++)
            {
                int cur = 0;
                for(int k = 0; k < B.size(); k++)
                        cur += A[i][k] * B[k][j];
                res[i][j] = cur;
            }
        return res;
    }
};
