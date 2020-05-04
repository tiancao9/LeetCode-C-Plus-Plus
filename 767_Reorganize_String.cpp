Given a string S, check if the letters can be rearranged so that two characters that are adjacent to each other are not the same.

If possible, output any possible result.  If not possible, return the empty string.

Example 1:

Input: S = "aab"
Output: "aba"
Example 2:

Input: S = "aaab"
Output: ""
Note:

S will consist of lowercase letters and have length in range [1, 500].

// Sol1: hash_map + priority_queue, adding 2 chars form pq every time.
class Solution {
public:
    string reorganizeString(string S) {
        // Uses hash map and priority queue.
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> pq;
        for (char c : S) {
            m[c]++;
        }
        for (auto item : m) {
            if (item.second > (S.size() + 1) / 2) {
                return "";
            }
            pq.push({item.second, item.first});
        }
        string res;
        while (pq.size() >= 2) {
            auto most_freq = pq.top(); pq.pop();
            auto second_freq = pq.top(); pq.pop();
            res.push_back(most_freq.second);
            res.push_back(second_freq.second);
            if (--most_freq.first > 0) pq.push(most_freq);
            if (--second_freq.first > 0) pq.push(second_freq);
        }
        if (pq.size() > 0) res.push_back(pq.top().second);
        return res;
    }
};

// Sol2: vector<int> char_num, char_num[c] = 100*n + i; sort char_num and insert 1 by 1.
class Solution {
public:
    string reorganizeString(string S) {
      vector<int> char_num(26, 0);
      for (char c : S) {
          char_num[c - 'a'] += 100;
      }
      for (int i = 0; i < 26; i++) {
          char_num[i] += i;
      }
      // By default, small to large;
      sort(char_num.begin(), char_num.end());
      int index = 1;
      for (int num : char_num) {
          int count = num / 100;
          char c = num % 100 + 'a';
          if (count > (S.size() + 1) / 2) {
              return "";
          }
          for (int i = 0; i < count; i++) {
              if (index >= S.size()) index = 0;
              S[index] = c;
              index += 2;              
          }
      }
        return S;
    }
};
