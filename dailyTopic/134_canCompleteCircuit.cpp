#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;



// https://leetcode-cn.com/problems/gas-station/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return canCompleteCircuit_1(gas, cost);
        return canCompleteCircuit_2(gas, cost);

    }

    int canCompleteCircuit_1(vector<int>& gas, vector<int>& cost) {
        int rest = 0;   // 总共消耗的油
        int run = 0;    // 邮箱剩余的油
        int start = 0;  // 起点
        for (int i = 0; i < gas.size(); ++i) {
            run += (gas[i] - cost[i]);
            rest += (gas[i] - cost[i]);
            if (run < 0) {  // 油为负数，说明不可能开到i这一站
                start = i + 1;
                run = 0;
            }
        }
        return rest < 0 ? -1: start;
    }

    int canCompleteCircuit_2(vector<int>& gas, vector<int>& cost) {
        vector<int> a;  // 记录到每个点的收益
        int count = 0;
        int num = 0;
        for (int i = 0; i < gas.size(); ++i) {
            num = gas[i] - cost[i];
            a.push_back(num);
            count += num;
        }
        if (count < 0) {
            return -1;
        }

        int start = 0;
        count = 0;
        for (int i = 0; i < gas.size(); ++i) {
            count += a[i];  // 收益为负说明根本到不了i
            if (count < 0) {
                count = 0;
                start = i+1;
            }
        }
        return start;
    }
};



int main() {
    vector<int> gas  = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    auto res = Solution().canCompleteCircuit(gas, cost);
    cout << res;
    return 0;
}
