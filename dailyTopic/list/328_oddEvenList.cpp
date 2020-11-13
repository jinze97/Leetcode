#include <iostream>
#include <vector>
#include "tools_list.cpp"

using namespace std;


// https://leetcode-cn.com/problems/odd-even-linked-list/
class Solution {
public:
    // 双指针
    ListNode* oddEvenList(ListNode* head) {
        // 相同思路， 双指针分离奇偶链表最后相连
        // 一个利用了头节点充当双指针
        // return oddEvenList_1(head);
        return oddEvenList_2(head);
    }


    // 双指针
    ListNode* oddEvenList_1(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* n =  head->next;  // 记录偶数链表的头节点
        ListNode* p1 = head;        // 奇链表
        ListNode* p2 = head->next;  // 偶链表
        // 偶数指针一定比奇数指针先到尾
        while (p2 && p2->next) {
            p1->next = p1->next->next;  //连接奇链表
            p2->next = p2->next->next;  //连接偶链表
            p1 = p1->next;
            p2 = p2->next;

            // p1 = p1->next = p1->next->next;
            // p2 = p2->next = p2->next->next;

        }

        p1->next = n;       // 奇链表后接入偶链表
        return head;
    }

    // 利用头节点充当双指针；
    ListNode* oddEvenList_2(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* m = head;             // 记录头节点
        ListNode* n = head->next;       // 记录偶链表头节点
        while (head->next && head->next->next) {
            ListNode* p = head->next->next; // 保存待移动奇节点

            head->next->next = p->next; // 连接偶链表

            head->next = p;             // 连接奇链表

            head = p;                   // 处理下一个奇节点
            // head = head->next = p;
        }
        head->next = n;                 // 奇链表后接入偶链表
        return m;
    }
};


int main() {
    ::vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createList_NoHead(nums);
    // printList(head);
    head = Solution().oddEvenList(head);
    printList(head);
    // std::copy(res.begin(), res.end(), std::ostream_iterator<int>(cout, " "));

    return 0;
}
