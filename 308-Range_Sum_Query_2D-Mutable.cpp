/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
update(3, 2, 2)
sumRegion(2, 1, 4, 3) -> 10
Note:
The matrix is only modifiable by the update function.
You may assume the number of calls to update and sumRegion function is distributed evenly.
You may assume that row1 ≤ row2 and col1 ≤ col2.
*/

//BIT, Binary Index Tree
//find next, i += (i & -i), for update
//find parent, i -= (i & -i), for getSum

class NumMatrix {
    // too hard, IQ is not enough
public:
    NumMatrix(vector<vector<int>> matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size();
        int m = matrix[0].size();
        Matrix = vector<vector<int>> (n+1, vector<int>(m+1, 0));
        BIT = vector<vector<int>> (n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                update(i, j, matrix[i][j]);
    }
    
    void update(int row, int col, int val) {
        int diff = val - Matrix[row+1][col+1];
        Matrix[row+1][col+1] = val;
        for(int i = row+1; i < BIT.size(); i+=(i&-i))
            for(int j = col+1; j < BIT[i].size(); j+=(j&-j))
                BIT[i][j] += diff;               
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2+1, col2+1) - getSum(row2+1, col1) - getSum(row1, col2+1) + getSum(row1, col1);
    }

    int getSum(int row, int col)
    {
        int res = 0;
        for(int i = row; i > 0; i -= (i&-i))
            for(int j = col; j > 0; j -= (j&-j))
                res += BIT[i][j];
        return res;
    }
private:
    vector<vector<int>> Matrix;
    vector<vector<int>> BIT;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
