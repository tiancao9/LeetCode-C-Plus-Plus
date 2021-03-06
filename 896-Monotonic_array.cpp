An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true
 

Note:

1 <= A.length <= 50000
-100000 <= A[i] <= 100000

// Check A.back() with A[0], define if it is increasig or decreasing.
// Trach each A[i] with A[i-1] to see if it keeps monotonic.
class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if (A.empty() || A.size() == 1) return true;
        bool increasing = false;
        if (A.back() >= A[0]) increasing = true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1] && !increasing) return false;
            if (A[i] < A[i-1] && increasing) return false;
        }
        return true;
    }
};
