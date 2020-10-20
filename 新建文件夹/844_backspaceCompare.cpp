#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    int getBackspaceNum(string str, int index) {
        int skip = 0;
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

    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1;
        int skipS = 0, skipT = 0;   //记录连续#个数

        while (i >= 0 || j >= 0) {
            i = getBackspaceNum(S, i);
            j = getBackspaceNum(T, j);

            if (S[i] != T[j]) {
                return false;
            }
            i--, j--;
            ::cout << getBackspaceNum(S, i) << "\n";
            ::cout << getBackspaceNum(T, j) << "\n";
        }

        return true;
        // while (i >= 0 || j >= 0) {
        //     while (i > 0) {
        //         if (S[i] == '#') {
        //             skipS++;, i--;
        //         } else if (skipS > 0) {
        //             skipS--; --;
        //         } else {
        //             break;
        //         }
        //     }
        // }
        // return true;
    }

    // bool backspaceCompare(string S, string T) {
    //     std::stack<char> stack_s, stack_t;
    //     parseString(S, stack_s);
    //     parseString(T, stack_t);
    //     printStack(stack_s);
    //     printStack(stack_t);

    //     return stack_s == stack_t;
    //     // return build(S) == build(T);
    // }

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
    ::string s("ab##");
    ::string t("ad#c");

    ::cout << Solution().backspaceCompare(s, t);

    return 0;
}

