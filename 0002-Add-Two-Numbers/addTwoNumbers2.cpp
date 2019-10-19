#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int printList(ListNode * list)
{
    ListNode *l = list;
    while(l->next != nullptr){
        cout << l->val << " -> ";
        l = l->next;
    }
    cout << l->val << endl;
    return 1;
}

bool insertList(ListNode* list, int idx, int data)
{

    if (idx < 1) {
        return false;
    }

    ListNode* p = list;
    int j=1;
    while (p &&  j<idx) {
        p = p->next;
        ++j;
    }

    if (!p || j>idx) {
        return false;
    }

    ListNode* s = new ListNode(data);
    s->next = p->next;
    p->next = s;
    return true;
}

bool pushList(ListNode* list, int data)
{
    while(list->next != nullptr){
        list = list->next;
    }
    ListNode* node = new ListNode(data);
    list->next = node;
    return true;
}


bool getNextFreeNode(ListNode ** node) {
    if (*node == nullptr) {
        return false;
    }
    ListNode *tmp = *node;
    *node = (*node)->next;
    delete tmp;
    return true;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resList = new ListNode(0);
        ListNode *cursor = resList;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0) {
            int l1Val = l1 != nullptr? l1->val : 0;
            int l2Val = l2 != nullptr? l2->val : 0;
            int sumVal = l1Val + l2Val + carry;
            carry = sumVal / 10;

            ListNode *node = new ListNode(sumVal % 10);
            cursor->next = node;
            cursor = node;

            if(l1 != nullptr) {
                getNextFreeNode(&l1);
                // tmp = l1;
                // l1 = l1->next;
                // delete tmp;
            }

            if(l2 != nullptr) {
                getNextFreeNode(&l2);
                // tmp = l2;
                // l2 = l2->next;
                // delete tmp;
            }
        }
        getNextFreeNode(&resList);
        return resList;
    }
};





int main() {

    ListNode* list1= new ListNode(2);
    pushList(list1, 4);
    pushList(list1, 3);

    ListNode* list2= new ListNode(5);
    pushList(list2, 6);
    pushList(list2, 4);

    printList(list1);
    printList(list2);
    printList(Solution().addTwoNumbers(list1, list2));
    return 0;
}