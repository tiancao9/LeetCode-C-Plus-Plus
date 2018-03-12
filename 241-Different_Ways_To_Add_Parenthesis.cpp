/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]


*/

//DP + Recursion

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++)
        {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*')
            {
                vector<int> res_left;
                vector<int> res_right;
                if(m.count(input.substr(0,i)))
                    res_left = m[input.substr(0,i)];
                else
                    res_left = diffWaysToCompute(input.substr(0,i));
                if(m.count(input.substr(i+1)))
                    res_right = m[input.substr(i+1)];
                else
                    res_right = diffWaysToCompute(input.substr(i+1));
                for(int l = 0; l < res_left.size(); l++)
                    for(int r = 0; r < res_right.size(); r++)
                    {
                        if(input[i] == '-')
                            res.push_back(res_left[l] - res_right[r]);
                        else if(input[i] == '+')
                            res.push_back(res_left[l] + res_right[r]);
                        else if(input[i] == '*')
                            res.push_back(res_left[l] * res_right[r]);
                    }
            }
        }
        if(res.size() == 0)
            res.push_back(stoi(input));
        m[input] = res;
        return res;
        
    }
private:
    unordered_map<string, vector<int>> m;
};
