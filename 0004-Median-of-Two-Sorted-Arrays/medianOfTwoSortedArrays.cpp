#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// 中位数的定义，如果某个有序数组长度是奇数，那么其中位数就是最中间那个，如果是偶数，那么就是最中间两个数字的平均值
// 对于两个有序数组也是一样的，假设两个有序数组的长度分别为m和n，由于两个数组长度之和 m+n 的奇偶不确定，因此需要分情况来讨论
// 对于奇数的情况，直接找到最中间的数即可，偶数的话需要求最中间两个数的平均值
// 为了简化代码，不分情况讨论，我们使用一个小trick，我们分别找第 (m+n+1) / 2 个，和 (m+n+2) / 2 个，然后求其平均值即可
// 这对奇偶数均适用。假如 m+n 为奇数的话，那么其实 (m+n+1) / 2 和 (m+n+2) / 2 的值相等，相当于两个相同的数字相加再除以2，还是其本身
class Solution {  
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int m = nums1.size(), n = nums2.size();
        int left = (m+n+1) / 2;
        int right = (m+n+2) / 2;
         return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    //i: nums1的起始位置 j: nums2的起始位置
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if( i >= nums1.size()) return nums2[j + k - 1]; //nums1为空数组
        if( j >= nums2.size()) return nums1[i + k - 1]; //nums2为空数组
        if(k == 1) {
            return min(nums1[i], nums2[j]);
        }

        // 二分查找法
        // 检查数组中是否存在第K/2个数字，如果存在就取出来，否则就赋值上一个整型最大值
        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if(midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j , k - k / 2);
        }else{
            return findKth(nums1, i, nums2, j + k / 2 , k - k / 2);
        }
    }
};




int main()
{

    vector<int> nums1 = {1};
    vector<int> nums2 = {2, 4};
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}