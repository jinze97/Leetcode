#include <iostream>



using namespace std;



class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        return isLongPressedName_1(name, typed);
        // return isLongPressedName_2(name, typed);
    }


    // 返回下标移动步数
    int parse(string &str, int & index) {
        int pos = 0;
        while (index < str.length()-1 && str[index] == str[index+1]) {
            ++pos;
            ++index;
        }
        return pos;
    }

    bool isLongPressedName_1(string name, string typed) {
        int pos_i = 0, pos_j = 0;
        while (pos_j < typed.length()) {
            if (parse(name, pos_i) > parse(typed, pos_j)) {
                return false;
            } else if (name[pos_i] != typed[pos_j]) {
                return false;
            }
            ++pos_i;
            ++pos_j;
        }

        return pos_i == name.length();
    }

    bool isLongPressedName_2(string name, string typed) {
        int pos_i = 0, pos_j = 0;
        while (pos_j < typed.length()) {
            if (pos_i < name.length() && name[pos_i] == typed[pos_j]) {
                ++pos_i;
                ++pos_j;
            } else if (pos_j > 0 && typed[pos_j] == typed[pos_j-1]) {
                ++pos_j;
            } else {
                return false;
            }
        }
        return pos_i == name.length();
    }
};



int main(int argc, char const *argv[])
{
    /* code */
    string name = "alex";
    string typed = "aaleex";
    cout << Solution().isLongPressedName(name, typed);
    return 0;
}


