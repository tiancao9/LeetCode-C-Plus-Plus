Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.

// MarkAllOnes: recursion.
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int cur = 0;
                    MarkAllOnes(i, j, grid, cur);
                    res = max(res, cur);
                }
            }
        }
        return res;
    }
private:
    void MarkAllOnes(int i, int j,
                     vector<vector<int>>& grid, int& cur) {
        if (i >= 0 && i < grid.size()
            && j >= 0 && j < grid[0].size() &&grid[i][j] == 1) {
            cur++;
            grid[i][j] = 0;
            MarkAllOnes(i-1, j, grid, cur);
            MarkAllOnes(i, j-1, grid, cur);
            MarkAllOnes(i+1, j, grid, cur);
            MarkAllOnes(i, j+1, grid, cur);
        }
        return;
    }
};
