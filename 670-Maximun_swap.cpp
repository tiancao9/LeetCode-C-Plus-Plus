Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.

Example 1:
Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.
Example 2:
Input: 9973
Output: 9973
Explanation: No swap.
Note:
The given number is in the range [0, 108]

// Sol1. Track back_max string, back_max[i] is the maximum from num_string[i] ... num_string.back().
// Swap the 1st num that num_string[i] != back_max[i].
class Solution {
public:
    int maximumSwap(int num) {
        string num_string = to_string(num);
        string back_max = num_string;
        for (int i = back_max.size() - 1; i >= 0; i--) {
            back_max[i] = max(back_max[i], back_max[i+1]);
        }
        for (int i = 0; i < num_string.size(); i++) {
            if (back_max[i] != num_string[i]) {
                // swap cur pos with max
                for (int j = num_string.size(); j > i; j--) {
                    if (num_string[j] == back_max[i]) {
                        swap(num_string[i], num_string[j]);
                        return stoi(num_string);
                    }
                }
            }
        }
        return num;
    }
};

// Sol2. Save space, back track the max_pos and keeps tracking the item that needs to swap (num_string[i] < num_string[max_pos]).
class Solution {
public:
    int maximumSwap(int num) {
      string num_string = to_string(num);
      int n = num_string.size(), max_pos = n - 1, pos1 = -1, pos2 = -1;
      for (int j = n-2; j >= 0; j--) {
          if (num_string[j] < num_string[max_pos]) {
              pos1 = j;
              pos2 = max_pos;
          } else if (num_string[j] > num_string[max_pos]) {
              max_pos = j;
          }
      }
      if (pos1 != -1) swap(num_string[pos1], num_string[pos2]);
      return stoi(num_string);
    }
};
