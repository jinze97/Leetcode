#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    // // 贪心算法
    // int maxProfit(vector<int>& prices) {
    //     int ans = 0;
    //     for (int i=1; i< prices.size()-1; ++i) {
    //         if (prices[i] > prices[i-1]) {
    //             ans += prices[i]-prices[i-1];
    //         }
    //     }
    //     return ans;
    // }

    // DP第i天只有两种状态，不持有或持有股票，
    // 当天不持有股票的状态可能来自昨天卖出或者昨天也不持有，
    // 同理，当天持有股票的状态可能来自昨天买入或者昨天也持有中，
    // 取最后一天的不持有股票状态就是问题的解
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0,
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
};

int main() {
    vector<int> num = {7,1,5,3,6,4};
    cout <<  Solution().maxProfit(num);
    return 0;
}
