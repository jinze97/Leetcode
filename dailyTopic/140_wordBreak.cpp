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
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return wordBreak_1(s, wordDict);
        // return wordBreak_2(s, wordDict);
    }

    // dfs + 剪枝
    vector<string> wordBreak_1(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;  //记录子函数调用结果
        return dfs(s, 0, memo, wordSet);
    }

    vector<string> dfs(const string& s, int index, unordered_map<int, vector<string>>& memo, unordered_set<string>& wordSet) {
        // 遇到相同的子问题时，直接返回 memo 中的缓存值，避免进入重复的递归
        if (memo.count(index)) {
            return memo[index];
        }

        if (index == s.size()) {
            return {""};
        }

        vector<string> res = {};
        for (int i = index + 1; i <= s.size(); ++i) {
            string word = s.substr(index, i - index);           // 切出一个子串，看看是不是单词
            if (wordSet.count(word)) {
                auto restRes = dfs(s, i, memo, wordSet);
                for (const string& succ: restRes) {
                    res.push_back(succ.empty() ? word : word + " " + succ);
                }
            }
        }
        memo[index] = res;
        return res;
    }


    vector<string> wordBreak_2(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> ans;  // 存储字符串 s 的每个下标和从该下标开始的部分可以组成的句子列表
        unordered_set<string> wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        backtrack(s, 0, ans, wordSet);
        // for (auto i: ans) {
        //     cout << i.first << "second: ";
        //     for (auto j: i.second) {
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }
        return ans[0];
    }


    void backtrack(const string& s, int index, unordered_map<int, vector<string>>& ans, unordered_set<string>& wordSet) {
        // if (ans.count(index)) {     //跳过已搜寻的index
        //     return;
        // }

        if (index == s.size()) {
            ans[index] = {""};
            return;
        }

        ans[index] = {};
        for (int i = index + 1; i <= s.size(); ++i) {
            string word = s.substr(index, i - index);  // 切出一个子串，看看是不是单词
            if (wordSet.count(word)) {
                backtrack(s, i, ans, wordSet);                        // 为单词表单词， 继续后半段
                for (const string& succ: ans[i]) {
                    ans[index].push_back(succ.empty() ? word : word + " " + succ);   // 把word和每个子数组拼接，然后推入res
                }
            }
        }
    }

};


int main() {
    string str = "catsanddog";
    vector<string> nums = {"cat","cats","and","sand","dog"};
    auto res = Solution().wordBreak(str, nums);
    cout << endl << "res: " << res.size() <<  endl;
    copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));

    return 0;
}
