#include <iostream>
#include <vector>
#include "tools_vector.cpp"
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;




void print(vector<vector<int>>& intervals)
{
    ::cout << '(';
    for(auto i: intervals) {
        ::cout << '(';
        for(auto j: i) {
            ::cout << j << ' ';
        }
        ::cout << "), ";
    }
    ::cout << ')';
    ::cout << ::endl;
}

class Solution {
public:
    vector<int> partitionLabels(string S) {
        //找到每个字符存在的区间
        std::vector<std::vector<int>> intervals;
        int start = 0, end = 0;
        for (int i = 0; i< 26; ++i) {
            char chr = char(97+i);
            if (S.find(chr) == std::string::npos) {
                continue;
            }
            start = S.find(chr);
            end = S.rfind(chr);
            std::vector<int> tmp {start, end};
            intervals.push_back(tmp);
        }
        print(intervals);

        // 以区间左端点排序
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {return a[0] < b[0]});
        print(intervals);

        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
             int L = intervals[i][0], R = intervals[i][1];
             if (!merged.size() || merged.back()[1] < L) {    // 当前左区间大于数组 merged 中最后一个区间的右端点之后
                merged.push_back({L, R});
             } else { //更新右端点
                merged.back()[1] = max(merged.back()[1], R);
             }
        }


        print(merged);

        return res;
    }

    // vector<int> partitionLabels(string S) {
    //     vector<int> res;
    //     unordered_map<char, int> charLastIndex;
    //     for (int i = 0; i< S.length(); ++i) {
    //         charLastIndex[S[i]] = i;
    //     }
    //     print(charLastIndex);

    //     int start = 0, end = 0;
    //     for (int i = 0; i < S.length(); ++i) {
    //         end = max(end, charLastIndex[S[i]]);    //获取当前片段的最小右端点
    //         if (i == end) { //已到达最小右端点 则为了最多片段 就在此分割
    //             res.push_back(end-start+1);
    //             start = end+1;
    //         }
    //     }

    //     return res;
    // }
};



int main(int argc, char const *argv[])
{
    /* code */
    string str = "ababcbacadefegdehijhklij";
    print(Solution().partitionLabels(str));
    // cout << Solution().isLongPressedName(name, typed);
    return 0;
}


