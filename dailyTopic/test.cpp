#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include "tools_vector.cpp"

using namespace std;



void swap(int & a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int i = left, j = right, mid = nums[left];
    while (i < j) {
        while (i < j && nums[j] >= mid)
            --j;
        while (i < j && nums[i] <= mid)
            ++i;

        if (i < j) {
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i], nums[left]);
    quickSort(nums, left, i-1);
    quickSort(nums, i+1, right);
}






int main(int argc, char const *argv[])
{
    ::vector<int> nums = {37,64,63,2,41,78,51,36,2,20,25,41,72,100,17,43,54,27,34,86,12,48,70,44,87,68,62,98,68,30,8,92,5,10};
    quickSort(nums, 0, nums.size()-1);
    print(nums);

    return 0;
}

