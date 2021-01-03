Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10

// Sol1, brute force, TLE.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        int max_sum = INT_MIN;
        for (int i = 0; i < heights.size(); i++) {
            int min_val = heights[i];
            for (int j = i; j >= 0; j--) {
                min_val = min(min_val, heights[j]);
                max_sum = max(max_sum, (i - j + 1) * min_val);
            }
        }
        return max_sum;
    }
};

// Sol2: stack.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.push_back(0);
        stack<int> s;
        for (int i = 0; i < heights.size(); i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int cur = heights[s.top()];
                s.pop();
                res = max(res, cur * (i - (s.empty()? -1 : s.top()) - 1));
            }
            s.push(i);
        }
        return res;
    }
};
