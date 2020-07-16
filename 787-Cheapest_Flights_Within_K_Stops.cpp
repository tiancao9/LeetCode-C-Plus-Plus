There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.

Now given all the cities and flights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.

Example 1:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 1
Output: 200
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:
Input: 
n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
src = 0, dst = 2, k = 0
Output: 500
Explanation: 
The graph looks like this:


The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
 

Constraints:

The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
The size of flights will be in range [0, n * (n - 1) / 2].
The format of each flight will be (src, dst, price).
The price of each flight will be in the range [1, 10000].
k is in the range of [0, n - 1].
There will not be any duplicated flights or self cycles.

// BFS.
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int res = INT_MAX;
        unordered_map<int, vector<pair<int, int>>> next_stops;
        queue<pair<pair</*sum*/int, /*cur_stop*/int>, unordered_set<int>>> q;
        for (auto flight : flights) {
            next_stops[flight[0]].push_back(make_pair(flight[1], flight[2]));
            // next_stops[flight[1]].push_back(make_pair(flight[0], flight[2]));
        }
        unordered_set<int> init_visited;
        init_visited.insert(src);
        q.push(make_pair(make_pair(0, src), init_visited));
        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            for (auto next_stop : next_stops[cur.first.second]) {
                if (cur.second.count(next_stop.first)) continue;
                cur.second.insert(next_stop.first);
                if (next_stop.first == dst) {
                    res = min(res, cur.first.first + next_stop.second);
                } else if (cur.second.size() <= K+1 &&
                          cur.first.first + next_stop.second < res) {
                    q.push(make_pair(make_pair(cur.first.first + next_stop.second, next_stop.first), cur.second));
                }
                cur.second.erase(next_stop.first);
            }
        }
        return res == INT_MAX? -1 : res;
    }
};
