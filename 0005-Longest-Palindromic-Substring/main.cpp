#include <iostream>
#include <vector>
#include <functional>




using namespace std;


template <typename T>
void print(T data)
{

    for(int i = 0; i < 5; ++i) {
        cout << data[i] << ' ';
    }
}


class Solution {
public:
    string longestPalindrome(string str) {
        int n = str.size();
        int maxLen = 1, begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int right = 1; right < n; ++right) {
            for (int left = 0; left < right; ++left) {
                if (str[left] != str[right]) {
                    dp[left][right] = false;
                    continue;
                } else {
                    // 即当s[i..j]的长度等于2或3的时候，只需要判断头尾两个字符是否相等
                    if (right - left < 3) {
                        dp[left][right] = true;
                    } else {
                        dp[left][right] = dp[left+1][right-1];
                    }
                }

                // 只要 dp[i][j]==true 成立，就表示子串 s[i..j] 是回文，此时记录回文长度和起始位置
                if (dp[left][right] && right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    begin = left;
                }
            }
        }
        return str.substr(begin, maxLen);
    }

    // string longestPalindrome(string str) {
    //     int strLen = str.size();
    //     if(strLen < 2) {
    //         return str;
    //     }

    //     int left = 0, right = 0;
    //     // int dp[strLen] = {0, };
    //     int dp[strLen];
    //     for(int i = 0; i < strLen; ++i) {
    //         dp[i] = 0;
    //     }

    //     for(int i = 0; i < strLen; ++i) {
    //         for(int j = 0; j < i; ++j) {
    //             if(!(dp[j] = dp[j+1] || str[i] != str[j]) && (right - left) <= (i - j)) {
    //                 ::cout << i << j << endl;
    //                 left = j, right = i;
    //             }
    //         }
    //     }
    //     return str.substr(left, right-left+1);
    // }
};




int main(int argc, char const *argv[])
{

   cout << Solution().longestPalindrome("babad") << endl;
   cout << Solution().longestPalindrome("avcca") << endl;
   cout << Solution().longestPalindrome("aacabdkacaa") << endl;
    return 0;
}







