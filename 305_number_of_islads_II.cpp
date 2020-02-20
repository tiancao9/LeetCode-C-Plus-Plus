305. Number of Islands II
Hard

708

15

Add to List

Share
A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example:

Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
Output: [1,1,2,3]
Explanation:

Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
Follow up:

Can you do it in time complexity O(k log mn), where k is the length of the positions?

// Sol: union find.
// Time complexity O(k log mn) requires compare length before merge, union as a tree;
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> uf(m*n, -1);
        int count = 0;
        vector<int> res;
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
        for (auto pos : positions) {
            int id = pos[0] * n + pos[1];
            if (uf[id] != -1) {
                res.push_back(count);
                continue;
            }
            uf[id] = id;
            count++;
            for (auto dir : dirs) {
                int x = dir[0] + pos[0];
                int y = dir[1] + pos[1];
                int id_neighbor = x * n + y;
                if (x < 0 || x >= m || y < 0 || y >= n || uf[id_neighbor] == -1) {
                    continue;
                }
                int root_id_neighbor = find_root(id_neighbor, uf);
                if (id != root_id_neighbor) {
                    count--;
                    uf[root_id_neighbor] = id;
                }
            }
            res.push_back(count);
        }
        return res;
    }
private:
    int find_root(int id, vector<int>& uf) {
        if (uf[id] != id)
            return find_root(uf[id], uf);
        return id;
    }
};
