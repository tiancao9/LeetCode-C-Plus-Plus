Given a sorted array arr, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

 

Example 1:

Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
Example 2:

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
 

Constraints:

1 <= k <= arr.length
1 <= arr.length <= 10^4
Absolute value of elements in the array and x will not exceed 104

// Sol1: map<int, vector<int>> m[abs(arr[i] - x)].push_back(arr[i]).
// Time: nlog(n). Space: O(n).
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int, vector<int>> m;
        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {
            m[abs(arr[i] - x)].push_back(arr[i]);
        }
        for (auto item : m) {
            if (k >= item.second.size()) {
                res.insert(res.end(), item.second.begin(), item.second.end());
                k -= item.second.size();
            } else {
                for (int i = 0; i < k; i++) {
                    res.push_back(item.second[i]);
                }
                break;
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};
// Sol2. Find the min_diff's index, and 2 pointer search, add 1 item per time.
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      int index = 0;
      int min_diff = INT_MAX;
      vector<int> res;
      for (int i = 0; i < arr.size(); i++) {
          if (abs(arr[i] - x) < min_diff) {
              min_diff = abs(arr[i] - x);
              index = i;
          }
      }
      int left = index-1, right = index+1;
      k--;
      while(k > 0) {
        if (left >= 0 && right < arr.size()) {
            if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--;
            } else {
                right++;
            }
        } else if (left >= 0) {
            left--;
        } else {
            right++;
        }
        k--;
      }
      left++; right--;
      for (int i = left; i <= right; i++) {
          res.push_back(arr[i]);
      }
      return res;
    }
};
