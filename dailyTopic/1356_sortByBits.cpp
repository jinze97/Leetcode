#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include "tools_vector.cpp"
using namespace std;


// https://leetcode-cn.com/problems/sort-integers-by-the-number-of-1-bits/
class Solution {
public:
    int count_one(int a) {
        int cnt = 0;
        while (a) {
            a = a & (a-1);      // 清除最低位的1
            cnt++;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int x,int y){
            int numa = count_one(x), numb = count_one(y);
            return numa != numb? numa < numb: x < y;
        });
        return arr;

    }
};


int main() {
    vector<int> num = {2,3,5,7,11,13,17,19};
    auto res =  Solution().sortByBits(num);
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
