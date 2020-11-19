#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

// https://leetcode-cn.com/problems/move-zeroes/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        return moveZeroes_1(nums);
        return moveZeroes_2(nums);
    }

    void moveZeroes_1(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }

    void moveZeroes_2(vector<int>& nums) {
        int n = nums.size(), l = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[l++] = nums[i];
            }
        }
        while (l < n) {
            nums[l++] = 0;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> nums = {0,1,0,3,12};
    Solution().moveZeroes(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));
    return 0;
}


