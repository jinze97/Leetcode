#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>
#include <vector>
#include "tools_list.cpp"

using namespace std;

class Solution {
public:
    ListNode * sortList(ListNode * head)
    {
        return  (head == NULL)? NULL: mergeSort(head);
    }

private:
    ListNode * findMid(ListNode * head)
    {
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * previous = NULL;
        while (fast != NULL && fast->next != NULL)
        {
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // split the list into two parts
        previous->next = NULL;
        return slow;
    }

    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2)
    {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    ListNode * mergeSort(ListNode * head)
    {
        if (head->next == NULL) return head;
        ListNode * mid = findMid(head);
        ListNode * l1 = mergeSort(head);
        ListNode * l2 = mergeSort(mid);
        return mergeTwoLists(l1, l2);
    }

};


void printList_1(ListNode* head)
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



int main(int argc, char const *argv[])
{
    ::vector<int> nums = {4, 2, 1, 3};
    ListNode* head = createList_NoHead(nums);
    printList(head);
    head = Solution().sortList(head->next);
    printList_1(head);
    return 0;
}

