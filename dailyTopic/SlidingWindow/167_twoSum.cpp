#include <iostream>
#include <vector>
#include <cassert>
#include <map>

using namespace std;


// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // return twoSum_1(nums, target);
        return twoSum_2(nums, target);
    }

    // 哈希表法, 无序数组最优解
    vector<int> twoSum_3(vector<int>& nums, int target) {
        std::map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            int key = target - nums[i];
            if (mp.count(key) > 0 ) {
                return {i, mp[key]};
            }
            mp[nums[i]] = i;
        }
        return {-1, -1};
    }


    // 双指针法
    vector<int> twoSum_2(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int data = nums[low] + nums[high];
            if (data == target) {
                return {low, high};
            }
            if (data < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }


    // 二分搜索
    vector<int> twoSum_1(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            int data = target - nums[i];
            int right = binarySearch(nums, i+1, nums.size()-1, data);
            if (right != -1) {
                return {i+1, right+1};
            }
        }

        // throw invalid_argument("the input has no solution");
        return {-1, -1};

    }

    int binarySearch(const vector<int> &nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l)/2; // int mid = (l+r) / 2;
            if(nums[mid] == target)
                return mid;
            if (target > nums[mid]) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }

};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {2, 3, 4, 7, 11, 15};
    int target = 10;
    // Solution().twoSum(nums, target);
    // print_vec(Solution().twoSum(nums, target));
    print_vec(Solution().twoSum_3(nums, target));

    return 0;
}
