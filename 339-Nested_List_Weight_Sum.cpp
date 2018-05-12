/*
Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)

*/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

//for each item in nestedList, use a queue, for each level in the queue, wuse same depth.res += depth*cur.getInteger()
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        int res = 0;
        for(int i = 0; i < nestedList.size(); i++)
        {
            queue<NestedInteger> q;
            int count = 1;
            q.push(nestedList[i]);
            while(!q.empty())
            {
                int n = q.size();
                for(int k = 0; k < n; k++)
                {
                    NestedInteger cur = q.front(); q.pop();
                    if(cur.isInteger())
                        res += count * cur.getInteger();
                    else
                    {
                        vector<NestedInteger> next_l = cur.getList();
                        for(int j = 0; j < next_l.size(); j++)
                            q.push(next_l[j]);
                    }          
                }
                count++;
                      
            }
        }
        return res;
    }
};

