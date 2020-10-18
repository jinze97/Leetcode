#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <algorithm>
#include <cstring>


using namespace std;


// dp[i][j]
// 第一个维度是天数，第二个维度表示是否持有股票，0表示不持有，1表示持有


class Solution {
public:
    int maxProfit_1(vector<int>& prices) {
        int n = prices.size();
        int dp[n][2];

        for (int i = 0; i < n; ++i) {
            if(i-1 == -1) {
                dp[i][0] = 0;       //第0天
                dp[i][1] = -prices[i];
                continue;
            }
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);  //昨天未持有今天无操作 + 昨天持有，今天卖
            // dp[i-1][0] - prices[i]  == -prices[i]  只允许交易一次，意味着之前不存在交易，利润为0
            dp[i][1] = max(dp[i-1][1], -prices[i]);   // 昨天持有今天不操作 + 昨天未持有，今天买
        }

        return dp[n - 1][0];   //最有一天未持有为最终结果
    }

    // 新状态只和相邻的一个状态有关, 不用保存整个dp数组，只需要记录前一天的状态
    int maxProfit_1_max(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = -1000;

        for (int i = 0; i < n; ++i) {
            dp_i_0  = max(dp_i_0, dp_i_1 + prices[i]);  //昨天未持有今天无操作 + 昨天持有，今天卖
            dp_i_1  = max(dp_i_1, -prices[i]);   // 昨天持有今天不操作 + 昨天未持有，今天买
        }

        return dp_i_0;
    }

    //不限制交易次数
    int maxProfit_2(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = -1000;

        for (int i = 0; i < n; ++i) {
            int temp = dp_i_0; // 记录上一次的利润
            dp_i_0  = max(dp_i_0, dp_i_1 + prices[i]);  //昨天未持有今天无操作 + 昨天持有，今天卖
            dp_i_1  = max(dp_i_1, temp-prices[i]);   // 昨天持有今天不操作 + 昨天未持有，今天买
        }

        return dp_i_0;
    }


    // 每次卖需要等一天才能继续交易
    int maxProfit_3(vector<int>& prices) {
        int n = prices.size();
        int dp_i_0 = 0;
        int dp_i_1 = -1000;
        int db_pre_0 = 0;   // 代表 dp[i-2][0]

        for (int i = 0; i < n; ++i) {
            int temp = dp_i_0; // 记录上一次的利润

            // 昨天未持有今天无操作 + 昨天持有，今天卖
            dp_i_0  = max(dp_i_0, dp_i_1 + prices[i]);
            // 昨天持有今天不操作 + 昨天未持有，今天买
            // 买的利润为i-2天的利润-今天的价格
            dp_i_1  = max(dp_i_1, db_pre_0 - prices[i]);
            //更新i-2状态
            db_pre_0 = temp;

        }

        return dp_i_0;
    }


    // // 最多进行两次交易
    // int maxProfit_4(vector<int>& prices) {
    //     int n = prices.size();
    //     int dp_i10 = 0;
    //     int dp_i11 = -1000;
    //     int dp_i20 = 0;
    //     int dp_i21 = -1000;

    //     for (int i = 0; i < n; ++i) {
    //         dp_i20 = max(dp_i20, dp_i21 + prices[i]);
    //         dp_i21 = max(dp_i21, dp_i10 - prices[i]);
    //         dp_i10 = max(dp_i10, dp_i11 + prices[i]);
    //         dp_i11 = max(dp_i11, -prices[i]);
    //     }
    //     return dp_i20;
    // }

    int maxProfit_4(vector<int>& prices) {
        int n = prices.size();
        int dp_i11[n+1] = {0};
        int dp_i10[n+1] = {0};
        int dp_i21[n+1] = {0};
        int dp_i20[n+1] = {0};

        dp_i10[0] = 0;
        dp_i11[0] = -1000;
        dp_i20[0] = 0;
        dp_i21[0] = -1000;
        for (int k = 1; k <= n; k++) {
            //今天未持有 =》 昨天未持有 + 昨天持有，今天卖出
            dp_i10[k] = max(dp_i10[k-1], dp_i11[k-1] + prices[k-1]);
            //今天持有 =》 昨天持有 + 昨天未持有，今天买入， 第一次交易利润未0-prices[k-1]
            dp_i11[k] = max(dp_i11[k-1], -prices[k-1]);
            //今天未持有 =》 昨天未持有 + 昨天持有，今天卖出
            dp_i20[k] = max(dp_i20[k-1], dp_i21[k-1] + prices[k-1]);
            //今天持有 =》 昨天持有 + 昨天未持有，今天买入， 第二次交易利润未第一次交易 - prices[k-1]
            dp_i21[k] = max(dp_i21[k-1], dp_i10[k-1] - prices[k-1]);
        }
        // return max(0, max(dp_i10[n], dp_i20[n]));
        return dp_i20[n];
    }


    // int maxProfit_4(vector<int>& prices) {
    //     int n = prices.size();
    //     int max_k  = 2;
    //     int dp[n][max_k +1][2];
    //     ::memset(dp, 0, sizeof(dp));  //<cstring>

    //     for (int i = 0; i < n; ++i) {

    //         for (int k = max_k; k >= 1; --k) {
    //             if(i-1 == -1) {
    //                 dp[i][k][0] = 0;          //第0天没有持有股票,所以无论交易多少次,收益都是0
    //                 dp[i][k][1] = -prices[0];
    //                 continue;
    //             }

    //             dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);  //昨天未持有今天无操作 + 昨天持有，今天卖
    //             dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);   // 昨天持有今天不操作 + 昨天未持有，今天买
    //         }
    //     }

    //     return dp[n - 1][max_k][0];
    // }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int beg = 0;  //买入点
//         int end = 0;  //卖出点
//         int pro = 0;  //利润初始化为0
//         int record = 0;   //记录当日卖出的最大利润
//         for (end = 0; end < prices.size(); ++end) {
//             if (prices[beg] > prices[end]) {    //遇到价格更低时直接重置买入价格
//                 beg = end;
//             }
//             record = prices[end] - prices[beg];
//             pro = record > pro? record : pro;
//         }

//         return pro;
//     }
// };




int main(int argc, char const *argv[])
{
    ::vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << Solution().maxProfit_4(arr) << endl;
    return 0;
}







