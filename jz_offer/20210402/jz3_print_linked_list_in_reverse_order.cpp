// 从尾到头打印链表
// 时间复杂度：O(n)
// 空间复杂度：O(n)

// code1：使用push_back(val)+reverse(vec.begin(), vec.end());
vector<int> result;
ListNode* p=head;
// 遍历linked list
while(p!=NULL)
{
    result.push_back(p->val);
    p=p->next;
}
reverse(result.begin(), result.end());
return result;



// code2：使用insert(vec.begin(), val);
vector<int> result;
ListNode* p=head;
while(p!=NULL)
{
    result.insert(result.begin(), p->val);
    p=p->next;
}
return result;
}