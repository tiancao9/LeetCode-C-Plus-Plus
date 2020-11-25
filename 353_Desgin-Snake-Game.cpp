Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:

Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)

// Sol: use a vector to keep the snake positions.
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) : kWidth(width), kHeight(height) {
        head_ = {0, 0};
        score_ = 0;
        for (int i = 0; i < food.size(); i++) {
            q_.push(make_pair(food[i][0], food[i][1]));
        }
        s_.push_back(head_);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto tail = s_.back();
        auto cur_food = make_pair(kWidth, kHeight);
        if (!q_.empty()) {
            cur_food= q_.front();   
        }
        s_.pop_back();
        if (direction == "U") {
            head_[0] -= 1;
        } else if (direction == "L") {
            head_[1] -= 1;
        } else if (direction == "R") {
            head_[1] += 1;
        } else if (direction == "D") {
            head_[0] += 1;
        }
        if (head_[0] < 0 || head_[0] >= kHeight || head_[1] < 0 || head_[1] >= kWidth || count(s_.begin(), s_.end(), head_)) {
            return -1;
        } else if (head_[0] == cur_food.first && head_[1] == cur_food.second) {
            q_.pop();
            s_.insert(s_.begin(), head_);
            s_.push_back(tail);
            return ++score_;
        } else {
            s_.insert(s_.begin(), head_);
            return score_;
        }
    }
private:
    vector<int> head_;
    int score_;
    queue<pair<int, int>> q_;
    const int kWidth;
    const int kHeight;
    vector<vector<int>> s_;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
