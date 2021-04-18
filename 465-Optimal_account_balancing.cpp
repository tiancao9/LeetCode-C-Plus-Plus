You are given an array of transactions transactions where transactions[i] = [fromi, toi, amounti] indicates that the person with ID = fromi gave amounti $ to the person with ID = toi.

Return the minimum number of transactions required to settle the debt.

 

Example 1:

Input: transactions = [[0,1,10],[2,0,5]]
Output: 2
Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.
Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
Example 2:

Input: transactions = [[0,1,10],[1,0,1],[1,2,5],[2,0,5]]
Output: 1
Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.
Therefore, person #1 only need to give person #0 $4, and all debt is settled.
 

Constraints:

1 <= transactions.length <= 8
transactions[i].length == 3
0 <= fromi, toi <= 20
fromi != toi
1 <= amounti <= 100


// Sol.
class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (auto transition : transactions) {
            m[transition[0]] -= transition[2];
            m[transition[1]] += transition[2];
        }
        vector<int> lders;
        vector<int> brwers;
        for (auto item : m) {
            if (item.second < 0) {
                brwers.push_back(-1 * item.second);
            } else if (item.second > 0) {
                lders.push_back(item.second);
            }
        }
        if (brwers.empty()) return 0;
        return dfs(brwers, lders, 0, 0);
    }
private:
    int dfs(vector<int>& brwers, vector<int>& lders, int m, int n) {
        if (brwers.size() == m) return 0;
        if (brwers.size() == m + 1) return lders.size() - n;
        if (lders.size() == n + 1) return brwers.size() - m;
        
        int min_val = INT_MAX;
        for (int i = m; i < brwers.size(); i++) {
            if (brwers[i] == lders[n]) {
                return 1 + dfs(brwers, lders, m + 1, n + 1);
            } else if (brwers[i] < lders[n]) {
                lders[n] -= brwers[i];
                min_val = min(min_val, 1 + dfs(brwers, lders, m + 1, n));
                lders[n] += brwers[i];
            } else {
                brwers[i] -= lders[n];
                min_val = min(min_val, 1 + dfs(brwers, lders, m, n + 1));
                brwers[i] += lders[n];
            }
        }
        return min_val;
    }
};
