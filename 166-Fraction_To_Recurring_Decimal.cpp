/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

Example 1:

Input: numerator = 1, denominator = 2
Output: "0.5".
Example 2:

Input: numerator = 2, denominator = 1
Output: "2".
Example 3:

Input: numerator = 2, denominator = 3
Output: "0.(6)".

*/
// use a map to record numerator and the position to use numerator 
// when numerator repeats, return and add ( and ) to res
// 1) if numerator / denominator == 0, res begin with "0"; 2) when n / d > 0 3) add "." 4) when n
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        
        if (numerator == 0) 
            return "0";
        
        long long numerator_abs = abs((long long)numerator);
        long long denominator_abs = abs((long long)denominator);
        
        int flag = 1;
        if(numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            flag = -1;
        
        map<int,int> m;
        string res;
        bool recur = false;
        long long cur = numerator_abs / denominator_abs;
        numerator_abs = numerator_abs % denominator_abs;
        if(flag == -1)
            res += '-';
        res += to_string(cur);
        if(numerator_abs)
            res += '.';
        m[numerator_abs] = res.size();
       
        
        while(numerator_abs && !recur)
        {
            cur = numerator_abs * 10 / denominator_abs;
            numerator_abs = numerator_abs * 10 % denominator_abs;
            res.push_back(cur+'0');
            if(m.count(numerator_abs))
                recur = true;
            else
                m[numerator_abs] = res.size();
        }
            
        if(recur)
        {
            res.insert(m[numerator_abs],"(");
            res += ')';
        }
            
        return res;
        
    }
};
