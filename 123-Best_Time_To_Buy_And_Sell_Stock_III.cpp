/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<int>> g(prices.size(), vector<int>(3, 0));
        vector<vector<int>> l(prices.size(), vector<int>(3, 0));
        for(int i = 1; i < prices.size(); i++)
        {
            int diff = prices[i] - prices[i-1];
            for(int j = 1; j < 3; j++)
            {
                l[i][j] = max(g[i-1][j-1] + max(0, diff), l[i-1][j] + diff); // max(last trans: but prices[i-1], sell prices[i], last trans: change from prices[i-1] to prices[i])
                g[i][j] = max(g[i-1][j], l[i][j]);
            }
        }
        return g[prices.size()-1][2];
    }
};
