#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// https://leetcode-cn.com/problems/valid-mountain-array/
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        return func_1(A);
        // return twoPoint(A);
    }

    bool func_1(vector<int>& A) {
        int size = A.size();
        int i = 0;
        while (i + 1 < size && A[i] < A[i + 1]) {
            ++i;
        }

        if (i == 0 || i == size-1) {
            return false;
        }
        while(i+1 < size && A[i] > A[i+1]) {
            ++i;
        }

        return i == size-1;
    }


    bool twoPoint(vector<int>& A) {
        int i = 0, j = A.size()-1, size = A.size();
        while (i + 1 < size && A[i] < A[i + 1]) {
            ++i;
        }
        while(j > 0 && A[j-1] >  A[j]) {
            --j;
        }
        return i > 0 && j < size-1 && i == j;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums = {0,3,2,1};
    ::cout << boolalpha << Solution().validMountainArray(nums);

    return 0;
}
