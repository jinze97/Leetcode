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
    while(l->next != NULL){
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
    while(list->next != NULL){
        list = list->next;
    }
    ListNode* node = new ListNode(data);
    list->next = node;
    return true;
}

int getLenList(ListNode* list)
{
    ListNode* tmp = list;
    int length = 1;
    while(tmp->next != nullptr){
        length += 1;
        tmp = tmp->next;
    }
    return length;
}

ListNode *listReverse(ListNode *pHead)
{
    if(pHead == nullptr) {
        return pHead;
    }
    ListNode *pCurrent ,*pPre, *pNext;   //一、指针的初始化阶段
    pPre = pHead;
    pCurrent = pPre->next ;

    while(pCurrent)                     //二、反转单链表的核心代码
    {
        pNext = pCurrent->next ;        //1. 缓冲pCurrent后面的单链表
        pCurrent->next = pPre ;         //2. 反转单链表
        pPre = pCurrent;                //3.让pPre指针后移
        pCurrent = pNext ;              //4. 让pCurrent指针后移
    }
                                        //三、处理并返回头指针
    pHead->next = nullptr;              //把原头结点的next域变成空指针
    pHead = pPre ;                      //把头结点指向最后一个结点产生新的头结点，也就是把原单链表的尾结点变成头结点

    return pHead;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int lenL1 = getLenList(l1);
        int lenL2 = getLenList(l2);

         //将两个链表填充长度相同
        if(lenL1 < lenL2) {
            for(int n=lenL2-lenL1; n>0; --n){
                // listAddZero(l1);
                pushList(l1, 0);
            }
        }else if (lenL1 > lenL2) {
            for(int n=lenL1-lenL2; n>0; --n){
                // listAddZero(l2);
                pushList(l2, 0);
            }
        }

        //相加到l1
        ListNode* l3 = l1;
        int carry=0;
        while(true) {
            l1->val += carry;
            carry = 0;
            l1->val += l2->val;
            if(l1->val >= 10 ){
                carry = (l1->val)/10;  //进位
                l1->val = (l1->val)%10;
            }

            if(l1->next == nullptr) break;
            l1 = l1->next;
            ListNode *temp = l2->next;
            delete l2;
            l2 = temp;
        }

        //最后一个节点进位
        if(carry!=0){
            ListNode* node = new ListNode(carry);
            l1->next = node;
        }

        return l3;
        // return listReverse(l3);
    }
};






int main() {

    ListNode* list1= new ListNode(5);
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