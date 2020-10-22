#include <iostream>
#include <vector>
#include "tools_stack.cpp"

using namespace std;

// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 // struct ListNode {
 //     int val;
 //     ListNode *next;
 //     ListNode() : val(0), next(nullptr) {}
 //     ListNode(int x) : val(x), next(nullptr) {}
 //     ListNode(int x, ListNode *next) : val(x), next(next) {}
 // };

class Solution {
public:
    int cur = 0;
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        head->next = removeNthFromEnd(head->next, n);
        cur++;
        if (n == cur) return head->next;
        return head;
    }


    ListNode* removeNthFromEnd_2(ListNode* head, int n) {
        // 定义哑节点dummy减少空判断
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode * fast = dummy, *slow = dummy;
        for (int i = 0; i< n; ++i) {
            fast = fast->next;
        }
        while (nullptr != fast) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;  //slow指向待删除结点的前一个结点
        return head;
    }

    ListNode* removeNthFromEnd_1(ListNode* head, int n) {
        ListNode * fast = head, *slow = head;
        for (int i = 0; i< n; ++i) {
            fast = fast->next;
        }
        if (nullptr == fast) {
            return head->next;
        }
        while (nullptr != fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;  //slow指向待删除结点的前一个结点
        return head;
    }
};



int main() {


    ::vector<int> nums = {1, 2, 3, 4, 5};
    ListNode* head = createList(nums);
    printList(head);
    head = Solution().removeNthFromEnd(head, 2);
    printList(head);
    // std::copy(res.begin(), res.end(), std::ostream_iterator<int>(cout, " "));

    return 0;
}
