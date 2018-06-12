
//求链表的交点

int LinkLength(ListNode* pHead)
{
    int size = 0;
    while(pHead != NULL)
    {
        size++;
        pHead = pHead->next;

    }
    return size;

}

ListNode* CrossWithNotCircle(ListNode* pHead1,ListNode* pHead2)
{
    int size1 = LinkLength(pHead1);//求链表1中的结点个数
    int size2 = LinkLength(pHead2);//求链表2中的结点个数
    int more = 0;
    if(size1 > size2)
    {
        ListNode* fast = pHead1;
        ListNode* slow = pHead2;
        more = size1 - size2;//计算多余的步长
        while(more--)
        {
            fast = fast->next;

        }
        while(fast != NULL)
        {
            if(fast == slow)
            {
                return fast;

            }
            fast = fast->next;
            slow = slow->next;

        }
        return NULL;

    }
    else
    {
        ListNode* fast = pHead2;
        ListNode* slow = pHead1;
        more = size2 - size1;//计算多余的步长
        while(more--)
        {
            fast = fast->next;

        }
        while(fast != NULL)
        {
            if(fast == slow)
            {
                return fast;

            }
            fast = fast->next;
            slow = slow->next;

        }
        return NULL;

    }

}
int LinkLengthCircle(ListNode* pHead,ListNode* entry)
{
    int size = 0;
    while(pHead != entry)
    {
        size++;
        pHead = pHead->next;

    }
    return size;

}
ListNode* CrossWithCircle(ListNode* pHead1,ListNode* pHead2,ListNode* entry1,ListNode* entry2)
{
    //两带环链表的的环入口点相同，则一定相交
    if(entry1 == entry2)
    {
        int size1 = LinkLengthCircle(pHead1,entry1);//求链表1中的结点个数
        int size2 = LinkLengthCircle(pHead2,entry2);//求链表2中的结点个数
        if(size1 > size2)
        {
            int more = size1 - size2;
            ListNode* fast = pHead1;
            ListNode* slow = pHead2;
            while(more--)
            {
                fast = fast->next;
            }
            while(fast != entry1)
            {
                if(fast == slow)
                {
                    return fast;
                }
                fast = fast->next;
                slow = slow->next;
            }
            return entry1;
        }
        else
        {
            int more = size2 - size1;
            ListNode* fast = pHead2;
            ListNode* slow = pHead1;
            while(more--)
            {
                fast = fast->next;
            }
            while(fast != entry1)
            {
                if(fast == slow)
                {
                    return fast;
                }
                fast = fast->next;
                slow = slow->next;
            }
            return entry1;
        }
    }
    else
    {
        ListNode* cur = entry1->next;
        while(cur != entry1)
        {
            if(cur == entry2)
            {
                return cur;//或者为entry1
            }
            cur = cur->next;
        }
        return NULL;
    }
}
ListNode* EntryCircle(ListNode* pHead)
{
    ListNode* fast = pHead;
    ListNode* slow = pHead;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
        {
            return fast;
        }
    }
    return NULL;
}
class Solution {
    public:
        ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2 ) {
            //首先判断两个链表的带环情况
            ListNode* entry1 = EntryCircle(pHead1);
            ListNode* entry2 = EntryCircle(pHead2);
            ListNode* cur1 = pHead1;
            ListNode* cur2 = pHead2;
            //如果两个链表都不带环
            if(entry1 == NULL && entry2 == NULL )
            {
                return CrossWithNotCircle(pHead1,pHead2);
            }
            //如果一个带环，一个不带环，则一定没有公共节点
            else if((entry1 == NULL && entry2 != NULL) || (entry1 != NULL && entry2 == NULL))
            {
                return NULL;
            }
            //如果两个链表都带环
            else
            {
                return CrossWithCircle(pHead1,pHead2,entry1,entry2);
            }
        }
};
