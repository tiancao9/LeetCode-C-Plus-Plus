/*
Given an integer, write a function to determine if it is a power of two.
*/
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        while(n > 1 && n %2 == 0)
            n /= 2;
        if(n!=1) return false;
        else
            return true;
    }
};
