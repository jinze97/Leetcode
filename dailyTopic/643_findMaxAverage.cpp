#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }
        int maxSum = sum;
        for (int i=k; i < nums.size(); ++i) {
            sum = sum + nums[i] - nums[i-k];
            maxSum = max(sum, maxSum);
        }

        return  static_cast<double>(maxSum) / k;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    std::vector<int> nums{5};
    int k = 1;
    ::cout << Solution().findMaxAverage(nums, k);
    return 0;
}
