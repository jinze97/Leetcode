#include <iostream>
#include "tools_vector.cpp"

using namespace std;


// https://leetcode-cn.com/problems/count-of-range-sum/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int size = nums.size();
        if( size == 0 ) return 0;
        vector<long long > presum;//前缀和数组， [0,i] 区间和
        long long pre = 0;
        for( auto & num : nums) {
            pre += num;
            presum.emplace_back(pre);
        }

        return res;
    }


    // int countRangeSum(vector<int>& nums, int lower, int upper) {
    //     int res = 0;
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int count = 0;
    //         for (int j = i; j < nums.size(); ++j) {
    //             count += nums[j];
    //             if (count >= lower && count <= upper) {
    //                 res++;
    //             }
    //         }
    //     }
    //     return res;
    // }
};

int main() {
    vector<int> num = {-2,5,-1};
    int lower = -2, upper = 2;
    cout <<  Solution().countRangeSum(num, lower, upper);
    return 0;
}
