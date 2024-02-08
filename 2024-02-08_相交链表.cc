#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(headA==nullptr||headB==nullptr){
        return nullptr;
    }
    ListNode* nodeA = headA;
    ListNode* nodeB = headB;
    while(nodeA!=nodeB){
        if(nodeA==nullptr){
            nodeA=headB;
        }
        else{
            nodeA=nodeA->next;
        }
        if(nodeB==nullptr){
            nodeB=headA;
        }else{
            nodeB=nodeB->next;
        }
    }
    return nodeA;
}


ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if(headA==nullptr||headB==nullptr){
        return nullptr;
    }
    ListNode* nodeA = headA;
    ListNode* nodeB = headB;
    while(nodeA!=nodeB){
        nodeA=nodeA==nullptr?headB:nodeA->next;
        nodeB=nodeB==nullptr?headA:nodeB->next;
    }
    return nodeA;
}