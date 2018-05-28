/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.

Example 1:
Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3
Example 2:
Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
Note:
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/

// iterate twice
// the 1st time find the case if two parent exist, put into ans1 and ans2, delete edge ans2
// the 2nd time check if closed loop happens, if yes, check if ans1 exist, if yes, return ans1, else, return the last edge that cause the closed loop
// return ans2 if no closed look
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> m;
        vector<int> ans1 = {};
        vector<int> ans2 = {};
        for(auto& edge: edges) // use reference since we need to 'delete' edge when duplicate parent happen
        {
            //check if edge[1] already been a leaf 
            for(auto key: m)
                if(m[key.first].count(edge[1]))
                {
                    ans1 = {key.first, edge[1]};
                    ans2 = edge;
                    edge[0] = -1;
                    edge[1] = -1;
                    break;
                }
            if(edge[0] == -1 && edge[1] == -1) break;
            m[edge[0]].insert(edge[1]);
        }
        
        unordered_map<int, unordered_set<int>> m1;
        for(vector<int> edge: edges)
        {
            if(edge[0] == -1 && edge[1] == -1) continue;
            //check if edge cause a closed circle
            queue<int> q;
            q.push(edge[1]);
            while(!q.empty())
            {
                int cur = q.front(); q.pop();
                if(m1[cur].count(edge[0])){
                    if(!ans1.empty()) return ans1;
                    else return edge;
                    //return edge;
                }
                for(auto next: m1[cur])
                    q.push(next);
            }
            
            m1[edge[0]].insert(edge[1]);
        }
        
        return ans2;
    }
};
