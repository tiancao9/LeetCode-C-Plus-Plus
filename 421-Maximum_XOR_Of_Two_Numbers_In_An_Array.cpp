/*
Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.

*/
// get pfrefix from 10000...00, 11....000 to 11111...10 & num into a set
// t = res | 1 << i, if we can find t ^prefix in the set, that means a^b = t, we set res = t
// a ^ b = c, a = b ^ c 
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int res = 0;
        for(int i = 31; i >= 0; i--)
        {
            mask |= 1 << i;
            set<int> s;
            for(int num: nums)
                s.insert(mask & num);
            int t = res | 1 << i;
            for(int prefix: s)
                if(s.count(prefix^t))
                {
                    res = t;
                    break;
                }
        }
        return res;
    }
};
