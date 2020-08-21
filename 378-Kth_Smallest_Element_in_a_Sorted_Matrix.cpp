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
