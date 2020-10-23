#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        // return backspaceStack(S, T);  //栈

        return backspacePtr(S, T);   //双指针法
        // return backspacePtr_1(S, T);
    }


    int getBackspaceNum(string str, int index) {
        int skip = 0;           // 记录连续#个数
        while(index >= 0) {
          if ('#' == str[index]) {
              ++skip, index--;
          } else if (skip > 0) {   //删除字符
              --skip; index--;
          } else {
              break;
          }
        }
        return index;
    }

    // 双指针， 逆序遍历字符串，统计退格符数量，删除字符
    // 时间复杂度：O(N+M)O(N+M)，其中 NN 和 MM 分别为字符串 SS 和 TT 的长度，需要遍历两字符串各一次。
    bool backspacePtr(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        while (i >= 0 || j >= 0) {
            i = getBackspaceNum(S, i), j = getBackspaceNum(T, j);
            if (i >= 0 && j >= 0) {
                if (S[i] != T[j]) {
                    return false;
                }
            } else {
                if (i >= 0 || j >= 0) {
                    // 有其中一方已经遍历完整个字符串, 但另外一方没有遍历完整个字符串, 直接返回false
                    return false;
                }
            }
            i--, j--;
        }
        return i < 0 && j < 0;
        // return true;
    }

    bool backspacePtr_1(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        while (i >= 0 || j >= 0) {
            i = getBackspaceNum(S, i), j = getBackspaceNum(T, j);
            if (i < 0 || j < 0) {
                break;
            }
            if (S[i--] != T[j--]) return false;
        }
        return i < 0 && j < 0;
    }

    // 栈解法
    bool backspaceStack(string S, string T) {
        std::stack<char> stack_s, stack_t;
        parseString(S, stack_s);
        parseString(T, stack_t);
        printStack(stack_s);
        printStack(stack_t);

        return stack_s == stack_t;
        // return build(S) == build(T);
    }

    string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }

    bool parseString(string str,  std::stack<char> &stk) {
        for (char ch: str) {
            if (ch != '#') {
                stk.push(ch);
            } else if (!str.empty()) {
                stk.pop();
            }
        }
        return true;
    }


    void printStack(::stack<char> &stk) {
        int size = stk.size();
        string str;
        for(int i = 0; i < size; ++i) {
            str.push_back(stk.top());
            stk.pop();
        }
        for_each(str.rbegin(),str.rend(),[](char w){::cout << w << ' ';});
        ::endl(::cout);
    }

};



int main(int argc, char const *argv[])
{
    ::string s("ab#c");
    ::string t("ad#c");

    ::cout << boolalpha << Solution().backspaceCompare(s, t);

    return 0;
}

