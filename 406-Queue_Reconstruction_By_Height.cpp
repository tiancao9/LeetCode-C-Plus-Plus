/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.


Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
         auto cmp = [](pair<int, int>& a, pair<int, int>& b)
        {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(pair<int, int> p: people)
            pq.push(p);
        vector<pair<int, int>> res;
        while(!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            res.insert(res.begin()+cur.second, cur);
        }
        return res;
    }
    
    
};
