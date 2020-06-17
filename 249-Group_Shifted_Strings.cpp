Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

Example:

Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Output: 
[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

//sol. hashmap.
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string item : strings) {
            string cur_unified = item;
            int diff = item[0] - 'a';
            for (int i = 0; i < item.size(); i++) {
                if (item[i] - diff - 'a' < 0) {
                    cur_unified[i] = item[i] - diff + 26;
                } else {
                    cur_unified[i] = item[i] - diff;
                }
            }
            m[cur_unified].push_back(item);
        }
        for (auto item : m) {
            res.push_back(item.second);
        }
        return res;
    }
};
