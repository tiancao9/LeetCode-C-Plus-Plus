You are given an m x n integer matrix heights representing the height of each unit cell in a continent. The Pacific ocean touches the continent's left and top edges, and the Atlantic ocean touches the continent's right and bottom edges.

Water can only flow in four directions: up, down, left, and right. Water flows from a cell to an adjacent one with an equal or lower height.

Return a list of grid coordinates where water can flow to both the Pacific and Atlantic oceans.

 

Example 1:


Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Example 2:

Input: heights = [[2,1],[1,2]]
Output: [[0,0],[0,1],[1,0],[1,1]]
 

Constraints:

m == heights.length
n == heights[i].length
1 <= m, n <= 200
0 <= heights[i][j] <= 105

// DFS from the edge for both Pacific and Atlantic (check the visited/reached).
// Get all nodes that in both reach_pacific and reach_atlantic.
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        vector<vector<bool>> reach_pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> reach_atlantic(heights.size(), vector<bool>(heights[0].size(), false));

        vector<vector<int>> res;
        
        for (int i = 0; i < heights.size(); i++) {
            dfs(i, 0, heights, reach_pacific);
            dfs(i, heights[0].size() - 1, heights, reach_atlantic);
        }
        for (int j = 0; j < heights[0].size(); j++) {
            dfs(0, j, heights, reach_pacific);
            dfs(heights.size() - 1, j, heights, reach_atlantic);
        }
        
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[0].size(); j++) {
                if (reach_pacific[i][j] && reach_atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
private:
    void dfs(int i, int j, const vector<vector<int>>& heights, vector<vector<bool>>& reach) {
        reach[i][j] = true;
        
        if (i - 1 >= 0 && i - 1 < heights.size() && j >= 0 && j < heights[0].size() 
            && heights[i - 1][j] >= heights[i][j] && !reach[i - 1][j]) {
            dfs(i - 1, j, heights, reach);
        } 
        if (i >= 0 && i < heights.size() && j - 1 >= 0 && j - 1 < heights[0].size() 
            && heights[i][j - 1] >= heights[i][j] && !reach[i][j - 1]) {
            dfs(i, j - 1, heights, reach);
        }
        if (i + 1 >= 0 && i + 1 < heights.size() && j >= 0 && j < heights[0].size() 
            && heights[i + 1][j] >= heights[i][j] && !reach[i + 1][j]) {
            dfs(i + 1, j, heights, reach);
        } 
        if (i >= 0 && i < heights.size() && j + 1 >= 0 && j + 1 < heights[0].size() 
            && heights[i][j + 1] >= heights[i][j] && !reach[i][j + 1]) {
            dfs(i, j + 1, heights, reach);
        }
    }
};
