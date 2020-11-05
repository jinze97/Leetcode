#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>


using namespace std;


// https://leetcode-cn.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // return doublePoint(nums1, nums2);
        // return intersection_1(nums1, nums2);
        return STL(nums1, nums2);
    }

    vector<int> STL(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v_intersection;
        std::sort(nums1.begin(), nums1.end());
        std::sort(nums2.begin(), nums2.end());


        // // 求交集 必须先排序
        // std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(v_intersection));
        // return v_intersection;

        // 求差集 必须先排序
        // set_difference(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(v_intersection));

        // 求并集 必须先排序
        std::set_union(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), std::back_inserter(v_intersection));

        return v_intersection;
    }

    vector<int> doublePoint(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        auto ptr1 = nums1.begin();
        auto ptr2 = nums2.begin();
        while (ptr1 != nums1.end() && ptr2 != nums2.end()) {
            if (*ptr1 == *ptr2) {
                // 保证加入元素的唯一性
                if (!res.size() || *ptr1 != res.back()) {
                    res.push_back(*ptr1);
                }
                ++ptr1, ++ptr2;
            } else if (*ptr1 > *ptr2) {
                ptr2++;
            } else {
                ptr1++;
            }
        }
        return res;
    }


    vector<int> intersection_1(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_set<int> set1, set2;
        for (auto& num : nums1) {
            set1.insert(num);
        }
        for (auto& num : nums2) {
            set2.insert(num);
        }
        return getIntersection(set1, set2);
    }


    vector<int> getIntersection(unordered_set<int>& set1, unordered_set<int>& set2) {
        if (set1.size() > set2.size()) {
            return getIntersection(set2, set1);
        }
        vector<int> res;
        for (const auto& num: set1) {
            if (set2.count(num)) {
                res.push_back(num);
            }
        }
        return res;
    }

};


int main() {
    // while (true) {
    //     int i = 0;
    // }
    string str = "catsanddog";
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    auto res = Solution().intersection(nums1, nums2);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));

    return 0;
}
