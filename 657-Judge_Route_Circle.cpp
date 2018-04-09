/*
Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        int count_l = 0;
        int count_r = 0;
        int count_d = 0;
        int count_u = 0;
        
        for(char move: moves)
        {
            if(move == 'L') count_l++;
            else if(move == 'R') count_r++;
            else if(move == 'D') count_d++;
            else if(move == 'U') count_u++;
        }
        
        if(count_l != count_r) return false;
        if(count_d != count_u) return false;
        
        return true;
    }
};
