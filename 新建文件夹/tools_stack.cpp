#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

// 偶数返回中间靠左节点
ListNode* middleNode(ListNode* head) {
    ListNode * slow = head;
    ListNode * fast = head;
    while (nullptr != fast->next && (fast->next->next != nullptr)) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow为中间节点的下一节点， 偶数为中间靠右节点
    // while (nullptr != fast) {
    //     slow = slow->next;
    //     fast = fast->next ? fast->next->next : fast->next;
    // }
    return slow;
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


void printList(ListNode* head)
{
    if (nullptr == head) {
        return;
    }
    while(head->next != NULL){
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << head->val << std::endl;
}





ListNode* createList(std::vector<int> arr)
{
    ListNode *head, *p;
    head = new ListNode;
    p = head;
    for (const auto &data: arr) {
        ListNode* temp = new ListNode(data);
        p->next = temp;
        p = temp;
    }

    return head;
}
