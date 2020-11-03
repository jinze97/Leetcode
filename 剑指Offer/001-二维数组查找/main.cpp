#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e
class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        int  row = 0, col = array[0].size()-1;
        while (row < array.size() && col >=0) {
            if (array[row][col] == target) {
                return true;
            }
            if (array[row][col] > target) { //说明当前列都大于taget,左移
                --col;
            } else {                    // 下移寻找target
                ++row;
            }
        }
        return false;
    }
};

void print_vec(const vector<vector<int>>& vec){
    for(auto e: vec) {
        std::copy(e.begin(), e.end(), std::ostream_iterator<int>(cout, " "));
        std::cout << std::endl;
    }
}

int main() {

    vector<vector<int>> nums = {{1,2,8,9}, {2,4,9,12}, {4,7,10,13}, {6,8,11,15}};
    print_vec(nums);
    int target = 7;

    ::cout << boolalpha << Solution().Find(target, nums);

    return 0;
}
