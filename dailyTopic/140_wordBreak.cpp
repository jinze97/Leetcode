#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;


// https://leetcode-cn.com/problems/word-break-ii/
class Solution {
public:
    unordered_map<int, vector<string>> ans;  // 存储字符串 s 的每个下标和从该下标开始的部分可以组成的句子列表
    unordered_set<string> wordSet;


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s, 0);

        // backtrack(s, 0);
        // for (auto i: ans) {
        //     cout << i.first << "second: ";
        //     for (auto j: i.second) {
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }
        // return ans[0];
    }

    vector<string> dfs(const string& s, int index) {
        if (index >= s.size()-1) {
            return {""};
        }
        vector<string> res = {};
        for (int i = index + 1; i <= s.size(); ++i) {
            string word = s.substr(index, i - index);           // 切出一个子串，看看是不是单词
            if (wordSet.count(word)) {
                auto restRes = dfs(s, i);
                for (const string& succ: restRes) {
                    res.push_back(succ.empty() ? word : word + " " + succ);
                }
            }
        }

        return res;
    }

    // void backtrack(const string& s, int index) {
    //     // if (ans.count(index)) {     //跳过已搜寻的index
    //     //     return;
    //     // }

    //     if (index == s.size()) {
    //         ans[index] = {""};
    //         return;
    //     }

    //     ans[index] = {};
    //     for (int i = index + 1; i <= s.size(); ++i) {
    //         string word = s.substr(index, i - index);  // 切出一个子串，看看是不是单词
    //         if (wordSet.count(word)) {
    //             backtrack(s, i);                        // 为单词表单词， 继续后半段
    //             for (const string& succ: ans[i]) {
    //                 ans[index].push_back(succ.empty() ? word : word + " " + succ);
    //             }
    //         }
    //     }
    // }

};


int main() {
    string str = "catsanddog";
    vector<string> nums = {"cat","cats","and","sand","dog"};
    auto res = Solution().wordBreak(str, nums);
    cout << endl << "res: " << res.size() <<  endl;
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}
