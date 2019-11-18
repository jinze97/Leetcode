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
        int strLen = str.size();
        if(strLen < 2) {
            return str;
        }

        int left = 0, right = 0;
        // int dp[strLen] = {0, };
        int dp[strLen];
        for(int i=0; i < strLen; ++i) {
            dp[i] = 0;
        }

        for(int i = 0; i < strLen; ++i) {
            for(int j = 0; j < i; ++j) {
                if(!(dp[j] = dp[j+1] || str[i] != str[j]) && (right - left) <= (i - j)) {
                    left = j, right = i;
                }
            }
        }   
        return str.substr(left, right-left+1);
    }
};




int main(int argc, char const *argv[])
{
    
   cout << Solution().longestPalindrome("babad") << endl;
   cout << Solution().longestPalindrome("avcca") << endl;
    return 0;
}






