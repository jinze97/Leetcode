#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if(hash.count(target - nums[i])) {
                return {hash[target - nums[i]], i};
                // return {hash.at(target - nums[i]), i};
            }
            hash[nums[i]] = i;
            // hash.insert({nums[i], i});
        }

        return {-1, -1};
    }

};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {0,4, 6, 7, 8, 2, 3, 5};
    int target = 9;
    // Solution().twoSum(nums, target);
    print_vec(Solution().twoSum(nums, target));

    return 0;
}