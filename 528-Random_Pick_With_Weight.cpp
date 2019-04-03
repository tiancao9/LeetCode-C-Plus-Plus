# Example: [1, 3, 2]
# Construct the sum array with weighted sum [1, 4, 6] 
# r = rand() % 6, randomly pick a number r from [0, 5]
# find the 1st number in sum array > r, the index is the answer

class Solution {
public:
    Solution(vector<int> w) {
        if (!w.empty())
            sum.push_back(w[0]);
        for (int i = 1; i < w.size(); i++) {
            sum.push_back(sum[i-1] + w[i]);
        }
    }
    
    int pickIndex() {
        int r = rand() % sum.back();
        int left = 0, right = sum.size()-1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= r) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
private:
    vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
