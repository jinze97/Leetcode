#include <iostream>
#include <vector>

using namespace std;


// https://leetcode-cn.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), left = 0, right = 0;
        vector<int> num(26);   // 记录区间内字符出现的次数
        int maxn = 0;
        while (right < n) {
            num[s[right] - 'A']++;
            maxn = max(maxn, num[s[right] - 'A']);

            // 右指针滑动后，区间不满足需求
            if (right - left + 1 - maxn > k) {
                // 左指针右移一位
                num[s[left] - 'A']--;
                left++;
            }
            right++;
        }
        return right-left;
    }
};



int main() {

    string s = "AABABBA";
    int k = 1;
    cout << Solution().characterReplacement(s, k);
    return 0;
}
