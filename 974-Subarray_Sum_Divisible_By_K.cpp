Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

// sum[i] = A[0] + ...+A[i]
// if sum[i] % K == sum[j] % K, sunarray[i,j] is divisible by K
// remain[i] = # of sum[n] % K == i
// choose pair from remain[i], remain[i] * (remain[i] - 1) / 2
// also need to add remain[0] since they do not need pair
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> remain(K, 0);
        int sum = 0;
        int res = 0;
        for (int i = 0; i < A.size(); i++) { 
            sum += A[i];
            int prefix = sum % K;
            if (prefix < 0) prefix += K;
            remain[prefix]++;
        }
        
        for (int i = 0; i < K; i++) {
            int x = remain[i];
            res += (x-1)*x/2;
        }
        
        return res+remain[0];
    }
};
