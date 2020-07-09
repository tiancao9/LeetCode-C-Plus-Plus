You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
Example:

Input: [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0

Output: 7 

Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2),
             the point (1,2) is an ideal empty land to build a house, as the total 
             travel distance of 3+3+1=7 is minimal. So return 7.
Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.

// BFS, queue.
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return -1;
        int res = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist_sum(m, vector<int>(n, 0));
        vector<vector<int>> cnt_visited(m, vector<int>(n, 0));
        vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int ones = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // BFS.
                    ones++;
                    queue<pair<int, int>> q;
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int dist = 1;
                    q.push({i, j});
                    while (!q.empty()) {
                        int size = q.size();
                        for (int k = 0; k < size; k++) {
                            auto cur = q.front(); q.pop();
                            for (auto dir : dirs) {
                                int next_x = cur.first + dir[0];
                                int next_y = cur.second + dir[1];
                                if (next_x >= 0 && next_x < m && 
                                    next_y >= 0 && next_y < n &&
                                    grid[next_x][next_y] == 0 &&
                                    !visited[next_x][next_y]) {
                                    dist_sum[next_x][next_y] += dist;
                                    cnt_visited[next_x][next_y]++; 
                                    visited[next_x][next_y] = true;
                                    q.push({next_x, next_y});
                                }
                            }
                        }
                        dist++;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && cnt_visited[i][j] == ones) {
                    res = min(res, dist_sum[i][j]);
                }
            }
        }
        return res == INT_MAX? -1 : res;
        
    }
};
