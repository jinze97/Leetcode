#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <algorithm>
#include <cstring>

// https://mp.weixin.qq.com/s?__biz=MzA5ODk3ODA4OQ==&mid=2648167219&idx=1&sn=a168412bc5b0c6038e11924baeff7ac8&chksm=88aa2375bfddaa63a69c08c38239dc42519af799e53fbc8eac1202847abb0f2260d6f9055826&token=1297748297&lang=zh_CN&scene=21#wechat_redirect
using namespace std;


// f(k) => max( f(k-1),   f(k-2)+H(k-1) )
// 当 k=0 时，没有房子，所以 f(0) = 0
// 当 k=1 时，只有一个房子，f(1) = H(0)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1] = {0};
        dp[0] = 0;
        dp[1] = nums[0];

        for (int k = 2; k <= n; ++k) {
            dp[k] = max(dp[k-1], dp[k-2] + nums[k-1]);
        }

        return dp[n];
    }

    int rob_1(vector<int>& nums) {
        int dp_0 = 0;  //表示 dp[k-2]
        int dp_1 = nums[0];  //表示 dp[k-1]

        for (auto i : nums) {
            int temp = max(dp_1, dp_0 + i);  // 计算出 dp[k] 的值
            dp_0 = dp_1;
            dp_1 = temp;
        }

        return dp_1;
    }


};



int main(int argc, char const *argv[])
{
    ::vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << Solution().rob_1(arr) << endl;
    return 0;
}







