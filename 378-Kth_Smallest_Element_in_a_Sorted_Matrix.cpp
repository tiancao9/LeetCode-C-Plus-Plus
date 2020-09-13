Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.

// PQ, O(nlogk)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;
        priority_queue<int> pq;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (pq.size() < k) {
                    pq.push(matrix[i][j]);
                } else {
                    int cur = pq.top();
                    if (cur > matrix[i][j]) {
                        pq.pop(); pq.push(matrix[i][j]);
                    }
                }
            }
        }
        return pq.top();
    }
};

// Sol2: binary search, O(nlogK), n is the column number and k is max - min.
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) return -1;
        int m = matrix.size(), n = matrix[0].size();
        int left = matrix[0][0];
        int right = matrix[m - 1][n - 1];
        while (left < right) {
            int mid = left + (right - left) / 2;
            int index = FindLessEqualIndex(matrix, mid);
            if (index < k) {
                left = mid + 1; 
            } else {
                right = mid;
            }
        }
        return left;
    }
private:
    int FindLessEqualIndex(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int res = 0;
        int i = m - 1, j = 0;
        while ( i >= 0 && j < n) {
            if (matrix[i][j] <= target) {
                res += i + 1;
                j++;
            } else {
                i--;
            }
        }
        return res;
    }
};
