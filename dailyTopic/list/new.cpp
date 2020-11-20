#include <iostream>
#include <vector>
#include "tools_list.cpp"

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // return insertionSortList_3(head);
        // return insertionSortList_1(head);
        return insertionSortList_2(head);
    }
    ListNode* insertionSortList_3(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // lastSorted记录已排序位置最后一个元素
        // curr 记录待处理节点
        ListNode* lastSorted = head;
        ListNode* curr = head->next;
        while (curr != nullptr ) {
            // 待处理节点比已排序最后一个节点大 不用处理，直接扩充，处理下一节点
            if (lastSorted->val <= curr->val) {
                lastSorted = curr;
                curr = curr->next;
                continue;
            }

            // 从呀节点开始找到待插入位置的前一节点
            ListNode *prev = dummy;
            while (prev->next->val <= curr->val) {
                    prev = prev->next;
            }

            // 记录下一个待处理节点
            lastSorted->next = curr->next;

            // 待插入节点后部连接到 待插入位置的后一节点
            curr->next = prev->next;
            // 前一节点后部连接待插入节点
            prev->next = curr;
            curr = lastSorted->next;
        }
        return dummy->next;
    }

    ListNode* insertionSortList_1(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        // head记录已排序位置最后一个元素
        ListNode* pre = head;
        while (head != nullptr && head->next != nullptr) {
            // 待处理节点比已排序最后一个节点大 不用处理，直接扩充，处理下一节点
            if (head->val <= head->next->val) {
                head = head->next;
                continue;
            }

            // 招待待插入位置前一节点
            pre = dummy;
            while (pre->next->val <  head->next->val) {
                pre = pre->next;
            }

            ListNode * curr = head->next; // 记录待处理节点
            // 记录下一个要处理的节点
            head->next = head->next->next;

            // 连接待处理节点
            // 带处理节点后部连接到 待插入位置的后一节点
            curr->next = pre->next;
            // 前一节点后部连接待插入节点
            pre->next = curr;
        }
        pre = dummy->next;
        delete(dummy);
        return pre;
    }


    ListNode* insertionSortList_2(ListNode* head) {
        ListNode* dummy = new ListNode(-1);

        ListNode* curr = head;
        while (curr) {
            ListNode* pre = dummy;
            // 找到需要插入位置点前一节点
            while (pre->next && pre->next->val < curr->val) {
                pre = pre->next;  // p为待插入节点位置的前一节点
            }
            ListNode* temp = curr->next;  // 记录待处理节点下一节点
            curr->next = pre->next;       // 待插入节点尾部连接到需要占位点的后一节点
            pre->next = curr;             // 待插入节点迁移节点连接插入节点

            curr = temp;
        }
        curr = dummy->next;
        delete(dummy);
        return curr;
    }

};


int main() {
    ::vector<int> nums = {4, 2, 1, 3};
    ListNode* head = createList_NoHead(nums);
    printList(head);
    head = Solution().insertionSortList(head);
    printList(head);
    // std::copy(res.begin(), res.end(), std::ostream_iterator<int>(cout, " "));

    return 0;
}
