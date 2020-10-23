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
        // return partitionLabels_1(S);
        return partitionLabels_2(S);
    }


    // 找到每个字符所在区间
    // 以区间左端点排序
    // 合并区间
    vector<int> partitionLabels_1(string S) {
        //找到每个字符存在的区间
        std::vector<std::vector<int>> intervals;
        int start = 0, end = 0;
        for (int i = 0; i< 26; ++i) {
            char chr = char(97+i);
            if (S.find(chr) == std::string::npos) {
                continue;
            }
            start = S.find(chr), end = S.rfind(chr);
            // std::vector<int> tmp {start, end};
            intervals.push_back({start, end});
        }
        // print(intervals);

        // 以区间左端点排序
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {return a[0] < b[0];});
        // print(intervals);

        // 合并区间
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
             int L = intervals[i][0], R = intervals[i][1];
             if (!merged.size() ||  L > merged.back()[1]) {    // 当前左区间大于数组 merged 中最后一个区间的右端点之后
                merged.push_back({L, R});
             } else { //更新右端点
                merged.back()[1] = max(merged.back()[1], R);
             }
        }
        // print(merged);

        // 计算区间元素数量
        std::vector<int> res;
        for (auto elem : merged) {
            res.push_back(elem[1] - elem[0] + 1);
        }
        return res;
    }


    // 找到每个元素最后出现的位置
    // 遍历字符串
    // 当字符最后出现的位置等于当前下标，已到达最小右端点，为了最多片段，就在此分割
    vector<int> partitionLabels_2(string S) {
        // 找到字符最后出现的位置
        unordered_map<char, int> charLastIndex;
        for (int i = 0; i< S.length(); ++i) {
            charLastIndex[S[i]] = i;
        }
        // print(charLastIndex);

        // 双指针寻找最小区间
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < S.length(); ++i) {
            end = max(end, charLastIndex[S[i]]);    //获取当前片段的最小右端点
            if (i == end) { //已到达最小右端点，为了最多片段，在此分割
                res.push_back(end-start+1);
                start = end+1;
            }
        }
        return res;
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    string str = "ababcbacadefegdehijhklij";
    print(Solution().partitionLabels(str));
    // cout << Solution().isLongPressedName(name, typed);
    return 0;
}


