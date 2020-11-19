#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include "tools_vector.cpp"
using namespace std;

// https://leetcode-cn.com/problems/word-ladder/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return BFS(beginWord, endWord, wordList);
        return BFS_1(beginWord, endWord, wordList);
        return BFS_2(beginWord, endWord, wordList);
    }

    // 双向BFS
    int BFS_2(string beginWord, string endWord, vector<string>& wordList) {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // 如果endWord没有在wordSet出现，直接返回0
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        unordered_set<string> beginSet{beginWord};
        unordered_set<string> endSet{endWord};
        int level = 1;
        while (!beginSet.empty() ) {
            level++;
            unordered_set<string> nextSet;
            for(auto & word : beginSet) {
                wordSet.erase(word);    // 移除访问过的元素
            }

            for(auto & word: beginSet) {  //模拟出队列
                for(int i = 0; i < word.size(); i++) {
                    string nextWord = word;
                    for(char j = 'a'; j <= 'z'; j++) {
                        nextWord[i] = j;
                        if(endSet.find(nextWord) != endSet.end()) {
                            return level;     //访问到同一元素
                        }
                        if (wordSet.find(nextWord) != wordSet.end()) {
                            nextSet.insert(nextWord);   //wordSet中下一层元素入队列
                        }
                    }
                }
            }

            // 从小的队列中去搜寻
            beginSet = nextSet;
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }
        }

        return 0;
    }


    int BFS(string beginWord, string endWord, vector<string>& wordList) {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // 如果endWord没有在wordSet出现，直接返回0
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        //记录每层元素和层级
        queue<pair<string, int>> que;
        que.push(pair<string, int>(beginWord, 1));

        while (!que.empty()) {
            auto node = que.front(); que.pop();
            string word = node.first;
            int level = node.second;
            if (word == endWord) {
                return level;
            }
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word; // 用一个新单词替换word，因为每次置换一个字母
                for(int j = 0; j < 26; ++j) {
                    newWord[i] = j+'a';
                    // wordSet有这个新词
                    if (wordSet.find(newWord) != wordSet.end()) {
                        que.push(pair<string, int>(newWord, level+1));  // 下一层元素入栈
                        wordSet.erase(newWord);  // 避免该词重复入列
                    }
                }
            }
        }
        return 0;
    }


    int BFS_1(string beginWord, string endWord, vector<string>& wordList) {
        // 将vector转成unordered_set，提高查询速度
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        // 如果endWord没有在wordSet出现，直接返回0
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        unordered_map<string, int> visitMap; // <word, 查询到这个word路径长度>

        //BFS中常见的队列，我们可以把它想象成为一颗二叉树，记录每一层的节点。
        //或者把它想象成为一个图，记录挨着的节点，也就是每一圈的节点
        queue<string> que;
        que.push(beginWord);
        // 初始化visitMap
        visitMap.insert(pair<string, int>(beginWord, 1));

        while (!que.empty()) {
            string word = que.front(); que.pop();
            int path = visitMap[word]; // 这个word的路径（层级）
            for (int i = 0; i < word.size(); ++i) {
                string newWord = word; // 用一个新单词替换word，因为每次置换一个字母
                for(int j = 0; j < 26; ++j) {
                    newWord[i] = j+'a';
                    if (newWord == endWord) {
                        return path + 1; // 找到了end，返回path+1
                    }
                    // wordSet出现了newWord，并且newWord没有被访问过
                    if (wordSet.find(newWord) != wordSet.end()
                            && visitMap.find(newWord) == visitMap.end()) {
                        // 添加访问信息
                        visitMap.insert(pair<string, int>(newWord, path + 1));
                        que.push(newWord);
                    }
                }
            }
        }
        return 0;
    }
};


int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    cout << Solution().ladderLength(beginWord, endWord, wordList);

    return 0;
}
