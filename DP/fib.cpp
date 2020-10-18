#include <iostream>
#include <vector>
#include <functional>
#include <iterator>
#include <algorithm>


using namespace std;
// https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/dong-tai-gui-hua-xiang-jie-jin-jie

class range
{
public:
    range(int end) : _end(end), _begin(0), _step(1) {}
    range(int begin, int end, int step=1) : _begin(begin), _end(end), _step(step) {
        if (!_step) // 步长为0, 设为默认值1
            _step = 1;
    }


    class iterator
    {
    public:
        iterator(int x, int s=1) : n(x), step(s) {}
        ~iterator() = default;

        iterator &operator++() {
            n += step;
            return *this;
        }

        bool operator!=(const iterator &x) {
            return (step>0)? n<x.n : n>x.n;
        }

        int &operator*() {
            return n;
        }

    private:
        int n, step;
    };

    iterator begin()
    {
        return iterator(_begin, _step);
    }
    iterator end()
    {
        return iterator(_end, _step);
    }

private:
    int _begin, _end, _step;
};


int fib(int N) {
    ::vector<int> dp(N + 1, 0);

    // base case
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[N];
}


// 状态压缩， 只记录dp的前两次结果从而推出下一个解
int fib_1(int n) {
    if (n == 2 || n == 1)
        return 1;
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}




// 给 k 种面值的硬币，面值分别为 c1, c2 ... ck，每种硬币的数量无限
// 再给一个总金额 amount，最少需要几枚硬币凑出这个金额
//
// f(amount) => f(amount-min(coins)) + min(coins)
// dp 数组的定义：当目标金额为 i 时，至少需要 dp[i] 枚硬币凑出。
int coinChange(vector<int>& coins, int amount) {

    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;

     for(auto i: range(dp.size())) {
        for (int coin : coins) {
            if (i - coin < 0) continue;
            dp[i]  = min(dp[i], dp[i - coin] + 1);
        }
    }
    ::copy(dp.begin(), dp.end(), ostream_iterator<int>(cout, " "));
    ::endl(::cout);
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main(int argc, char const *argv[])
{
    // ::cout << fib_1(3) << ::endl;
    //
    ::vector<int> arr = {1, 2, 5};
    ::cout << coinChange(arr, 11) << ::endl;
    return 0;
}
