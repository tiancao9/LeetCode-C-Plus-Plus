/*
Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
*/
// convert n to binary, either use bit operation n & 1 << i or bin(n)[2:][i]
// iterate from 0 to 31
// for each iteration, x *= x, res *= x if bin[i] == 1

class Solution {
public:
    double myPow(double x, int n) {
        
        bool neg;
        double res = 1;
        if(n < 0)
        {
            n = n * -1;
            neg = true;
        }
        else
            neg = false;
   // if int is really latge, will exceed time limit by simple iteration, need to transfer it to binary      
        for(int i = 0; i <= 31; i++)
        {
 
            if (n & 1 << i)
                res *= x;
            x *= x;
        }
        
        if(neg)
            res = 1/ res;
        
        return res;
    }
};
