#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;




// Sliding Window
// Time Complexity: O(len(s))
// Space Complexity: O(len(charset))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstring_1(s);
        // return lengthOfLongestSubstring_2(s);
    }

    int lengthOfLongestSubstring_1(string s) {
        // 记录每个字符最后出现的下标
        // ASCII表共能表示256个字符，可以记录所有字符
        // int last[256] = {0};
        unordered_map<char, int> last;

        int left = 0, res = 0;
        for(int right = 0; right < s.size(); ++right) {
            // last[s[right]] == 0 当前遍历到的字符未出现过
            // last[s[right]] < left 当前遍历到的字符出现过，且不在滑动窗口内
            if(last[s[right]] == 0 || last[s[right]] < left) {
                // res = max(res, right - left + 1);
                res = right - left + 1;   //窗口长度+1
            } else {
                // 左窗口滑动
                left = last[s[right]];
            }
            //记录当前元素最后出现的后一位置
            last[s[right]] = right+1;
        }
        return res;
    }

    int lengthOfLongestSubstring_2(string s) {
        int res = 0, left = 0;
        // 记录一个字母如果后面出现重复时，left 应该调整到的新位置
        unordered_map<char, int> last;
        for (int right = 0; right < s.size(); ++right) {
            left = max(left, last[s[right]]);
            last[s[right]] = right + 1;
            res = max(res, right - left + 1);
        }
        return res;
    }

};




int main() {

    cout << Solution().lengthOfLongestSubstring( "abccchgbb" )<<endl; //4
    cout << Solution().lengthOfLongestSubstring( "bbbbb" )<<endl;    //1
    cout << Solution().lengthOfLongestSubstring( "pwwkew" )<<endl;   //3
    cout << Solution().lengthOfLongestSubstring( "c" )<<endl;        //1
    cout << Solution().lengthOfLongestSubstring( "" )<<endl;         //0

    return 0;
}
