Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000

// Sol1. Time limit exeeds.
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0;
        if (A.empty()) return res;
        int mod_v = 1e9 + 7;
        std::cout << mod_v << std::endl;
        for (int i = 0; i < A.size(); i++) {
            int min_v = A[i];
            for (int j = i; j < A.size(); j++) {
                min_v = min(min_v, A[j]);
                res += min_v;
                res = res % mod_v;
            }
        }
        return res;
    }
};
// Sol2. Stack + DP.
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int res = 0;
        if (A.empty()) return res;
        int n = A.size();
        const int mod_v = 1e9 + 7;
        vector<int> dp(n+1);
        stack<int> s;
        s.push(-1);
        for (int i = 0; i < n; i++) {
            while (s.top() != -1 && A[i] <= A[s.top()]) {
                s.pop();
            }
            dp[i+1] = (dp[s.top() + 1] + (i - s.top()) * A[i]) % mod_v;
            s.push(i);
            res = (res + dp[i+1]) % mod_v;
        }
        return res;
    }
};
