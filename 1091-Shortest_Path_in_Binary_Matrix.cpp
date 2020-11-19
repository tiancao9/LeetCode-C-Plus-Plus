In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]


Output: 2

Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]


Output: 4

 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1

// Sol: BFS + visited matrix.
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        if (grid.empty() || grid[0].empty() || grid[0][0] != 0) return -1;
        if (grid.size() == 1 && grid[0].size() == 1) return 1;
        q.push(make_pair(0, 0));
        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        visited[0][0] = true;
        int cnt = 1;
        while(!q.empty()) {
            int n = q.size();
            std::cout << n << std::endl;
            for (int i = 0; i < n; i++) {
                auto cur = q.front(); q.pop();
                for (auto dir : dirs) {
                    int x = cur.first + dir[0];
                    int y = cur.second + dir[1];
                    if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 0 && !visited[x][y]) {
                        if (x == grid.size() - 1 && y == grid[0].size() - 1) return ++cnt;
                        q.push(make_pair(x, y));
                        visited[x][y] = true;
                    }
                }
            }
            cnt++;
        }
        return -1;
    }
};
