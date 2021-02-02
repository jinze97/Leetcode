#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


// https://leetcode-cn.com/problems/sort-array-by-parity-ii/
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        // return sortArrayByParityII_1(A);
        return sortArrayByParityII_2(A);
    }

    // 双指针， 遍历偶数位，遇奇数。从奇数位上找偶数交换
    vector<int> sortArrayByParityII_1(vector<int>& A) {
        int odd_pos = 1;
        for (int i = 0; i < A.size(); i += 2) {
            // 最后一位是1，说明是奇数。最后一位是0，说明是偶数
            if (!(A[i] & 1)) {  //  跳过偶数下标
                continue;
            }

            while (A[odd_pos] & 1) {      //寻找偶数下标
                odd_pos += 2;
            }

            swap(A[i], A[odd_pos]);
        }
        return A;
    }

    // 双指针， 不修改原数组
    vector<int> sortArrayByParityII_2(vector<int>& A) {
        vector<int> res(A.size(), 0);
        int even_pos = 0;
        int odd_pos = 1;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] & 1) {   //A[i]%2 != 0
                res[odd_pos] = A[i];
                odd_pos += 2;
            } else {
                res[even_pos] = A[i];
                even_pos += 2;
            }
        }
        return res;
    }
};

int main() {
    vector<int> num = {4,2,5,7};

    auto res = Solution().sortArrayByParityII(num);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
