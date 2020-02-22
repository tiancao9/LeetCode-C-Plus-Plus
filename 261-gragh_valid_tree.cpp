Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

Example 1:

Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
Output: true
Example 2:

Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
Output: false
Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.

// valid tree: edge # = node # - 1; start from one node, should be able to visit all other node.
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      if (n != edges.size() + 1) return false;
      unordered_map<int, unordered_set<int>> m_neighbors;
      unordered_set<int> visited_nodes;
      for (auto edge : edges) {
          m_neighbors[edge[0]].insert(edge[1]);
          m_neighbors[edge[1]].insert(edge[0]);
      }
      queue<int> neighbors;
      neighbors.push(0);
      while(!neighbors.empty()) {
          int cur = neighbors.front();
          neighbors.pop();
          if (!visited_nodes.count(cur)) {
              for (auto neighbor : m_neighbors[cur]) {
                  neighbors.push(neighbor);
              }
              visited_nodes.insert(cur);
          }
      }
      return visited_nodes.size() == n;
    }
};
