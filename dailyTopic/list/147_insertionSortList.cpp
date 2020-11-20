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
        return insertionSortList_1(head);
        return insertionSortList_2(head);
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
            // 断开待处理节点  待处理节点前一节点 只想 待处理节点 后一节点
            head->next = curr->next;

            // 插入待处理节点
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

        ListNode* pNext = head;
        while (pNext) {
            ListNode* p = dummy;
            // 找到需要插入位置点前一节点
            while (p->next && p->next->val < pNext->val) {
                p = p->next;  // p为待插入节点位置的前一节点
            }
            ListNode* q = pNext;
            pNext = pNext->next;  //移动待排序节点时，需要将待处理的节点变为下一节点

            q->next = p->next;   // 待插入节点尾部连接到需要占位点的后一节点
            p->next = q;        // 待插入节点迁移节点连接插入节点
        }
        pNext = dummy->next;
        delete(dummy);
        return pNext;
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
