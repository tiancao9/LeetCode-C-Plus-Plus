/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;
        for(int num: nums)
        {
            if(m.count(num))
                m[num]++;
            else
                m[num] = 1;
        }
        for(auto i = m.begin(); i != m.end(); i++) // can not use i < m.end()
        {
            pq.push(make_pair(i->second, i->first));
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        int n = pq.size(); // has to record pq size before the loop, otherwise the loop size gonna change every time you do pop()
        for(int i = 0; i < n; i++)
        {
            auto cur = pq.top(); pq.pop();
            res.push_back(cur.second);
            
        }
        
        return res;
    } 
};
