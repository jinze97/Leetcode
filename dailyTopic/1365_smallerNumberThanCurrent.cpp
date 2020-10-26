#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include "tools_vector.cpp"

using namespace std;


class Solution {
public:
    void swap(int & a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int i = left, j = right, mid = nums[left];
        while (i < j) {
            while (i < j && nums[j] >= mid)
                --j;
            while (i < j && nums[i] <= mid)
                ++i;

            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i], nums[left]);
        quickSort(nums, left, i-1);
        quickSort(nums, i+1, right);
    }


    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        quickSort(vec, 0, vec.size()-1);
        // copy(nums.rbegin(), nums.rend(), ostream_iterator<int>(cout, " ")); // ostream_iterator<int, char> os_iter(cout, " ");

        // 从后向前，记录 vec[i] 对应的下标
        int hasn[101] = {0};
        for (int i = vec.size()-1; i >= 0; --i) {
            hasn[vec[i]] = i;
        }

        // copy(std::begin(hasn), std::end(hasn), ostream_iterator<int>(cout, " "));
        // std::endl(std::cout);

        vector<int> res;
        for(auto &elem: nums) {
            res.push_back(hasn[elem]);
        }
        return res;
    }
};



int main(int argc, char const *argv[])
{
    ::vector<int> nums = {37,64,63,2,41,78,51,36,2,20,25,41,72,100,17,43,54,27,34,86,12,48,70,44,87,68,62,98,68,30,8,92,5,10};
    print(Solution().smallerNumbersThanCurrent(nums));
}

