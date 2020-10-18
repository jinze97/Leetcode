#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }

            }
        }
        return result;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {0,4,3,5};
    int target = 9;

    auto res = Solution().twoSum(nums, target);
    std::copy(res.begin(), res.end(), std::ostream_iterator<int>(cout, " "));
    
    return 0;
}