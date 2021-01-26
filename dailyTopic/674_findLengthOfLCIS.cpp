#include <iostream>
#include <vector>
#include <iterator>


using namespace std;

// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int count = 1;   //记录区间大小
        int ans = 1;     // 记录最大区间数
        for(int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] < nums[i+1]) {
                ++count;
            } else {
                count = 1;   //区间不满足要求，大小缩小为1
            }
            ans = max(ans, count);
        }
        return ans;
    }

    int findLengthOfLCIS_1(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int start = 0;   //记录区间开始位置
        int ans = 0;     // 记录最大区间长度
        for(int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] <= nums[i-1]) {   // 当前元素小于等于上一个元素，非递增区间
                start = i;
            }
            ans = max(ans, i-start+1);
        }
        return ans;
    }
};

int main() {
    // vector<int> num{1,3,5,4,7};
    vector<int> num{1, 3, 5, 7};
    cout << Solution().findLengthOfLCIS(num) << endl;
    return 0;
}
