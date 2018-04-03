/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string cur = "";
        vector<string> dict = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        dfs(digits, cur, res, 0, dict);
        return res;      
    }

private:
    void dfs(string digits, string cur, vector<string>& res, int i, vector<string> dict)
    {
        if(i == digits.size()) return;
        string temp = dict[digits[i]-'0'];
        if(temp.empty()) dfs(digits, cur, res, i+1, dict);
        for(int j = 0; j < temp.size(); j++)
        {
            cur.push_back(temp[j]);
            if(i == digits.size()-1) res.push_back(cur);
            dfs(digits, cur, res, i+1, dict);
            cur.pop_back();
        }
    }

};
