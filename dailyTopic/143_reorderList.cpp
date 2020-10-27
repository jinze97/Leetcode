#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include "tools_list.cpp"

using namespace std;

// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:

    void reorderList(ListNode* head) {
        reorderList_1(head);
        // reorderList_2(head);
    }

    void reorderList_1(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        //中间节点， 偶数返回中间靠左节点
        ListNode* slow =  middleNode(head);

        // 断开前后链表
        ListNode* newHead = slow->next;
        slow->next = nullptr;

        //将后段链表逆序
        newHead = reverseList(newHead);

         // 重新组合链表
        while (nullptr != newHead ) {
            ListNode* temp = newHead->next;
            newHead->next = head->next;
            head->next = newHead;
            head = newHead->next;
            newHead = temp;
        }
    }


    // 利用线性表存储链表， 使用下标重建该链表
    void reorderList_2(ListNode* head) {
        if (nullptr == head) {
            return ;
        }
        // 保存每个节点到vector中
        ::vector<ListNode *> vec;
        ListNode *node = head;
        while (nullptr != node) {
            vec.emplace_back(node);
            node = node->next;
        }
        // 重构链表
        int i = 0, j = vec.size()-1;
        while (i < j) {
            if (i == j) {
                break;
            }
            vec[i]->next = vec[j];
            i++;
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};



int main(int argc, char const *argv[])
{
    ::vector<int> nums = {1, 2, 3, 4, 5, 6};
    ListNode* head = createList(nums);
    // printList(head);
    Solution().reorderList(head->next);
    printList(head->next);
    return 0;
}

