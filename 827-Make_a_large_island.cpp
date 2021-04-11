You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.

// Paint islands with piant_num;
// Iterate grid[i][j] == 0, to get the max num.
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> island_sizes = {0, 0}; // paint number starts from 2.
        int res = 0;
        if (grid.empty() || grid[0].empty()) return res;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    island_sizes.push_back(PaintIsland(grid, i, j, island_sizes.size()));
                    std::cout << i << " " << j << " " << grid[i][j] << " " << island_sizes.back() << std::endl;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    int cur = 1;
                    unordered_set<int> s;
                    for (auto dir : dirs) {
                        s.insert(GetPaintNumber(grid, i + dir[0], j + dir[1]));
                    }
                    for (int paint_number : s) {
                        cur += island_sizes[paint_number];
                    }
                    res = max(res, cur);
                }
            }
        }
        if (!res) return grid.size() * grid[0].size();
        return res;
    }
private:
    vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // Paints the island with paint_num value.
    // Returns the island size.
    int PaintIsland(vector<vector<int>>& grid, int i, int j, int paint_num) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) return 0;
        grid[i][j] = paint_num;
        return 1 + PaintIsland(grid, i+1, j, paint_num) + PaintIsland(grid, i-1, j, paint_num) + PaintIsland(grid, i, j-1, paint_num) + PaintIsland(grid, i, j+1, paint_num);
    }
    // Gets the paint number for grid[i][j].
    int GetPaintNumber(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return 0;
        return grid[i][j];
    }
};
