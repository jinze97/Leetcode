#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

// https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    void replaceSpace(char *str,int length) {
        int count = 0;
        for(int i = 0; i < length; ++i) {
            if(str[i] == ' ') {
                ++count;
            }
        }

        for (int i = length-1; i >=0; --i) {
            if (str[i] != ' ') {
                str[i + count*2] = str[i];
            }
            if (str[i] == ' ') {
                count--;
                str[i+count*2] = '%';
                str[i+count*2 + 1] = '2';
                str[i+count*2 + 2] = '0';
            }
        }
    }
};


int main() {
    char str[] = "We Are Happy";
    Solution().replaceSpace(str, sizeof(str)/sizeof(str[0]));
    cout << str;

    return 0;
}
