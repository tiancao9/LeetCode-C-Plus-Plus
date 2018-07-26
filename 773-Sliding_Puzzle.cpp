/*
On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.

A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.

The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].

Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

Examples:

Input: board = [[1,2,3],[4,0,5]]
Output: 1
Explanation: Swap the 0 and the 5 in one move.
Input: board = [[1,2,3],[5,4,0]]
Output: -1
Explanation: No number of moves will make the board solved.
Input: board = [[4,1,2],[5,0,3]]
Output: 5
Explanation: 5 is the smallest number of moves that solves the board.
An example path:
After move 0: [[4,1,2],[5,0,3]]
After move 1: [[4,1,2],[0,5,3]]
After move 2: [[0,1,2],[4,5,3]]
After move 3: [[1,0,2],[4,5,3]]
After move 4: [[1,2,0],[4,5,3]]
After move 5: [[1,2,3],[4,5,0]]
Input: board = [[3,2,4],[1,5,0]]
Output: 14
Note:

board will be a 2 x 3 array as described above.
board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
*/
//BFS, queue<pair<string, int>>, string is e.g. "123405", int is step, use unordered_set to save all visited permutation
class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        string goal = "123450";
        string cur = "";
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                cur += to_string(board[i][j]);
        q.push(make_pair(cur, 0));
        visited.insert(cur);
        
        while(!q.empty())
        {
            string tmp = q.front().first;
            int step = q.front().second; q.pop();
            if(tmp == goal) return step;
            int pos = tmp.find('0');
            int x = pos / 3;
            int y = pos % 3;
            if(x == 0) 
            {
                string next = tmp;
                next[pos] = tmp[pos+3];
                next[pos+3] = '0';
                if(!visited.count(next))
                {
                    q.push(make_pair(next, step+1));
                    visited.insert(next);
                }
            }
            else
            {
                string next = tmp;
                next[pos] = tmp[pos-3];
                next[pos-3] = '0';
                if(!visited.count(next))
                {
                    q.push(make_pair(next, step+1));
                    visited.insert(next);
                }                    
            }
            
            if(y > 0)
            {
                string next = tmp;
                next[pos] = tmp[pos-1];
                next[pos-1] = '0';
                if(!visited.count(next))
                {
                    q.push(make_pair(next, step+1));
                    visited.insert(next);
                }   
            }
            if(y < 2)
            {
                string next = tmp;
                next[pos] = tmp[pos+1];
                next[pos+1] = '0';
                if(!visited.count(next))
                {
                    q.push(make_pair(next, step+1));
                    visited.insert(next);
                }   
            }
        }
        return -1;
            
    }
};
