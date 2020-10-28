#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        std::map<int, int> count;
        for (const auto& data: arr) {
            count[data]++;
        }
        // 合并相同数量,去除出现相同的数字
        set<int> res;
        for (const auto& item: count) {
            res.insert(item.second);
        }
        return res.size() == count.size();
    }
};



int main(int argc, char const *argv[])
{
    std::vector<int> arr = {1,2,2};
    ::cout << boolalpha << Solution().uniqueOccurrences(arr);

    return 0;
}

