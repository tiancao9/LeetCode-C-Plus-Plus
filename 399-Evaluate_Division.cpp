/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
*/

// use a map to save: a/b = 1.0, m[a][b] = 1.0; m[b][a] = 1.0; m[a][a] = 1.0; m[b][b] = 1.0;
// for each query, use queue<pair<string, double>> and unordered_set visited (avoid infinite loop) to find the path from queries[i].first to queries[i].second 

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res(queries.size(), -1.0);
        unordered_map<string, unordered_map<string, double>> m; // a/b = 1.0   -> m[a][b] = 1.0
        for(int i = 0; i < equations.size(); i++)
        {
            m[equations[i].first][equations[i].first] = 1.0;
            m[equations[i].second][equations[i].second] = 1.0;
            m[equations[i].first][equations[i].second] = values[i];
            m[equations[i].second][equations[i].first] = 1.0 / values[i];
        }
        
        for(int i = 0; i < queries.size(); i++)
        {
            pair<string, string> cur = queries[i];
            if(!m.count(cur.first) || !m.count(cur.second)) continue;
            queue<pair<string, double>> q; q.push(make_pair(cur.first, 1.0));
            unordered_set<string> visited; visited.insert(cur.first);
            while(!q.empty())
            {
                pair<string, double> temp = q.front(); q.pop();
                if(m[temp.first].count(cur.second))
                {
                    res[i] = temp.second * m[temp.first][cur.second];
                    break;
                }
                else
                {
                    for(auto next: m[temp.first]){
                        if(visited.count(next.first))
                            continue;
                        else
                        {
                            q.push(make_pair(next.first, temp.second*next.second));
                            visited.insert(next.first);
                        }
                    }
                }
            }            
        }
        return res;
    }
};
