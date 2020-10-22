#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include "tools_stack.cpp"

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
        // reorderList_1(head);
        reorderList_2(head);
    }

    // 找到中间节点将链表拆分 （快慢指针）
    // 将后段链表逆序
    // 重新组合链表
    void reorderList_1(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* slow =  middleNode(head);  //偶数返回中间靠左节点
        ListNode* newHead = slow->next;
        slow->next = nullptr;

        newHead = reverseList(newHead);

        while (nullptr != newHead ) {
            ListNode* temp = newHead->next;
            newHead->next = head->next;
            head->next = newHead;
            head = newHead->next;
            newHead = temp;
        }
    }


    ListNode* reverseList(ListNode* head) {
        if (nullptr == head) return nullptr;
        ListNode* pre = nullptr;
        ListNode* pNext;

        while (nullptr !=  head) {
            pNext = head->next;  // 保存待移动节点的 next , 以防取下 head 后丢失
            head->next = pre;    // 当前节点断裂，指向前一个节点
            pre = head;          // pre改为为下一次移动节点的前驱
            head = pNext;        // 保存的后去变为下一轮移动的节点
        }
        return pre;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && (fast->next->next != nullptr)) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
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

