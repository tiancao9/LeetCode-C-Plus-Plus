/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]] 
Output: true
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
 Hints:

This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegrees(numCourses,0);
        vector<vector<int>> next_list(numCourses,vector<int>(0));
        
        for(auto prerequisite: prerequisites)
        {
            indegrees[prerequisite.first]++;
            next_list[prerequisite.second].push_back(prerequisite.first);
        }
        
        queue<int> indegree_0;
        
        for(int i = 0; i < numCourses; i++)
        {
            if(!indegrees[i])
                indegree_0.push(i);            
        }
        
        int count = 0;
        while(!indegree_0.empty())
        {
            int cur = indegree_0.front();
            indegree_0.pop();
            for(int j = 0; j < next_list[cur].size(); j++)
            {
                indegrees[next_list[cur][j]]--;
                if(indegrees[next_list[cur][j]] == 0)
                    indegree_0.push(next_list[cur][j]);
            }         
            count++;
        }
        
        if(count == numCourses)
            return true;
        else
            return false;
        
    }
};
