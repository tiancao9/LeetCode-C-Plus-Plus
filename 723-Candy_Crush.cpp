This question is about implementing a basic elimination algorithm for Candy Crush.

Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies. A value of board[i][j] = 0 represents that the cell at position (i, j) is empty. The given board represents the state of the game following the player's move. Now, you need to restore the board to a stable state by crushing candies according to the following rules:

If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
After the above steps, there may exist more candies that can be crushed. If so, you need to repeat the above steps.
If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
You need to perform the above rules until the board becomes stable, then return the current board.

 

Example:

Input:
board =
[[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]

Output:
[[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]

Explanation:

 

Note:

The length of board will be in the range [3, 50].
The length of board[i] will be in the range [3, 50].
Each board[i][j] will initially start as an integer in the range [1, 2000].

//Sol.
class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        if (board.empty()) return board;
        int n = board.size();
        int m = board[0].size();
        while (true) {
            // finds the candies to crush.
            vector<int> to_crash = FindCandyToCrash(board);
            if (to_crash.empty()) break;
            // crashes the candy.
            for (int item : to_crash) {
                board[item / m][item % m] = 0;
            }
            // drops candies.
            DropCandy(board);
        }
        return board;
    }
private:
    vector<int> FindCandyToCrash(vector<vector<int>>& board) {
        vector<int> to_crash;
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) continue;
                int x_left = j - 1, x_right = j + 1;
                int y_up = i - 1, y_down = i + 1;
                while (x_left >= 0 && board[i][x_left] == board[i][j]) x_left--;
                while (x_right < m && board[i][x_right] == board[i][j]) x_right++;
                while (y_up >= 0 && board[y_up][j] == board[i][j]) y_up--;
                while(y_down < n && board[y_down][j] == board[i][j]) y_down++;
                if (x_right - x_left - 1 >= 3 || y_down - y_up - 1 >= 3) to_crash.push_back(i * m + j);
            }
        }
        return to_crash;
    }
    void DropCandy(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int j = 0; j < m; j++) {
            for (int i = n - 1; i >= 0; i--) {
                if (board[i][j] == 0) {
                    int temp_i = i - 1;
                    while (temp_i >= 0) {
                        if (board[temp_i][j] != 0) {
                            swap(board[i][j], board[temp_i][j]);
                            break;
                        }
                        temp_i--;
                    }
                }
            }
        }
    }
};
