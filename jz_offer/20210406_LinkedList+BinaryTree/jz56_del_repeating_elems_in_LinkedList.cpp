// 删除链表中重复的结点{1,2,3,3,4,4,5} -> {1,2,5}
// 重点：删除链表的节点一般需要使用pre和curr两个双指针
// 方法1：一次遍历使用Hashmap统计元素个数，两次遍历删除>=1的元素



// 变种：将repeating elements转化为individual elements
// {1,2,3,3,4,4,5} -> {1,2,3,4,5}
// 思想：使用pre ptr和curr ptr，当pre ptr的值等于curr ptr时，删除curr ptr
ListNode* deleteDuplication(ListNode* pHead) {
    ListNode* p=pHead, * pre=pHead;
    if(pHead==NULL)
        return NULL;
    while(p->next!=NULL){
        p=p->next;
        if(pre->val==p->val){
            pre->next=p->next;
            p=pre;
            continue;
        }
        pre=pre->next;
    }
    return pHead;
}