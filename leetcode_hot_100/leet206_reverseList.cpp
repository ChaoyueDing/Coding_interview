#include<bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

 // 虚头+存后指前+head->next指空·
class Solution {
public:
    // head-use-after-free: 函数返回的值中包含已经被释放掉的内存。
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode* dummy = new ListNode();  // 定义dummy虚头节点
        ListNode* prev = NULL;  // 定义前节点prev
        dummy->next = head;
        ListNode* p = head;
        ListNode* rear = NULL;  // 定义后节点rear
        while(p != NULL){
            // 移动顺序 后rear->前prev->p，移动后之后要立即指前p->next=prev，需要注意p==head，p->next=null的情况
            rear = p->next;  // 存后：后节点移动到p->next处
            p->next = prev;  // 指前：用p—>next指向p前面一个节点prev
            prev = p;  // 前节点移到p处
            p = rear;  // p节点移到rear处
        }
        return prev;
    }
};