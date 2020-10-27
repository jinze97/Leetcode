#include <iostream>
#include <vector>
#include "tools_list.cpp"
#include "tools_vector.cpp"
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        return isPalindrome_1(head);
        // return isPalindrome_2(head);
    }

    bool isPalindrome_1(ListNode* head) {
        if (nullptr == head) return true;
        // 找到中间（偶数为中间靠右）节点后一个节点
        ListNode* newHead =  middleNode(head)->next;

        // 翻转后段链表
        newHead = reverseList(newHead);

        // 比对值
        while (newHead != nullptr) {
            if (head->val != newHead->val) {
                return false;
            }
            head = head->next;
            newHead = newHead->next;
        }
        return true;
    }


    bool isPalindrome_2(ListNode* head) {
        // 保存每个节点到vector中
        ::vector<int> vec;
        ListNode *node = head;
        while (nullptr != node) {
            vec.emplace_back(node->val);
            node = node->next;
        }
        // 比较值
        int j = vec.size();
        for(int i = 0; i < (vec.size() / 2); ++i) {
            if (vec[i] != vec[--j]) {
                return false;
            }
        }
        return true;
    }
};




int main(int argc, char const *argv[])
{
    /* code */
    ::vector<int> nums = {1, 2, 4,  2,1};
    ListNode* head = createList(nums);
    printList(head);
    cout << boolalpha << Solution().isPalindrome(head->next);
    return 0;
}


