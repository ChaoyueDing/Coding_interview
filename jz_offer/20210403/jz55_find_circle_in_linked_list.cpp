// jz55: 链表中环的入口结点
// 时间复杂度：O(N)，其中N为链表中节点的数目。在最初判断快慢指针是否相遇时，
// slow指针走过的距离不会超过链表的总长度；随后寻找入环点时，走过的距离也不会超过链表的总长度。
// 空间复杂度：O(1)。我们只使用了slow,fast两个指针。

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    ListNode* p1=pHead;
    ListNode* p2=pHead;
    while(p2->next!=NULL && p2->next->next!=NULL){
        p2 = p2->next->next;
        p1 = p1->next;
        if(p2==p1){
            p1 = pHead;
            while(p2!=p1){
                p2 = p2->next;
                p1 = p1->next;
            }
            return p1;
        }
    }
    return NULL;
}