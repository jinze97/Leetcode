#include <vector>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

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
