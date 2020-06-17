Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

// check the corner cases: if i,j < 0, i,j = 0, if i >= m or j >= n, i = m-1, j = n-1, i.j += 2.
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        bool up = true;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            res.push_back(matrix[i][j]);
            if (up) {
                i--; j++;
                if (j >= n) {
                    j = n-1;
                    i += 2;
                    up = false;
                } else if (i < 0) {
                    i = 0;
                    up = false;
                }
            } else {
                i++; j--;
                if (i >= m) {
                    i = m - 1;
                    j += 2;
                    up = true;
                } else if (j < 0) {
                    j = 0;
                    up = true;
                }
            }
        }
        return res;
    }
}; 
