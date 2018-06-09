/*
Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
*/
// bit operation
// get i for  divisor << i > dividend
// dividend -= divisor << i, i--
class Solution {
public:
    int divide(int dividend, int divisor) {
       
        int res = 0;
        int Neg_if = 0;
        if (divisor == 0) 
            return dividend>=0? INT_MAX:INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
         unsigned long long dvd = abs((long long)dividend);
         unsigned long long dvs = abs((long long)divisor);
        
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            Neg_if = 1;
        
        int i = 0;
        while (dvs<<(i+1) <= dvd) 
            i++;
        
        while(dvd >= dvs)
        {
            if(dvd >= (dvs<<i))
            {
                dvd-=dvs<<i;
                res+=1<<i;
            }
            i--;
        }
       
        
        
        return Neg_if?  0-res:res;
    }
};
