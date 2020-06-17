The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

Example:

Input: 4
Output: [
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.

// DFS
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> res;
        vector<string> cur;
        set<int> s;
        if(!n) return res;
        find_next(res, cur, s, n);
        return res;
    }
    
private:
    void find_next(vector<vector<string>> & res, 
                   vector<string> & cur, 
                   set<int> & s, 
                   int n)
    {
        if(cur.size() == n)
        {
            res.push_back(cur);
            return;
        }
        
        for (int i = 0; i < n; i++)
        {
            string cur_s(n,'.');
            if(!s.count(i) && check_valid(cur,i)) 
            {
                cur_s[i] = 'Q';
                s.insert(i);
                cur.push_back(cur_s);
                find_next(res, cur, s, n);
                s.erase(i);
                cur.pop_back();
                cur_s[i] = '.';
            }
            
        }
    }
    
    bool check_valid(vector<string> cur, int new_l)
    {
        vector<int> col(cur.size(),0);
        
        for(int i = 0; i < cur.size(); i++)
            for(int j = 0; j < cur[i].size(); j++)
            {
                if(cur[i][j] == 'Q') col[i] = j;
            }
        
        
        for(int i = 0; i < col.size(); i++)
        {
            if(abs(cur.size()-i) == abs(new_l - col[i]))
                return false;
        }
            
        return true;
                
    }
};

// Re-factor
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> res;
      vector<string> cur;
      unordered_set<int> s; // record col position for Qs.
      FindSol(res, cur, s, n);
      return res;
    }

private:
    void FindSol(vector<vector<string>>& res, vector<string>& cur,
                unordered_set<int>& s, int n) {
      if (cur.size() == n) {
          res.push_back(cur);
          return;
      }
      // Iterate every col position for cur.size()'th Q.
      for (int i = 0; i < n; i++) {  
        if (!s.count(i) && !CheckDiag(cur, i)) {
            string new_q(n, '.');
            new_q[i] = 'Q';
            cur.push_back(new_q);
            s.insert(i);
            FindSol(res, cur, s, n);
            cur.pop_back();
            s.erase(i);
        }
      }
    }
    
    // Return false if no other Qs on the diags.
    bool CheckDiag(vector<string> cur, int q_col) {
        int m = cur.size();
        vector<int> q_cols(m, 0);
        for (int i = 0; i < m; i++) {
          for (int j = 0; j < cur[i].size(); j++) {
              if (cur[i][j] == 'Q') {
                  q_cols[i] = j;
              }
          }
        }
        for (int i = 0; i < m; i++) {
            // Check diags for each Q.
            if (abs(q_col - q_cols[i]) == abs(m - i)) {
                return true;
            }
        }
        return false;
    }

};
