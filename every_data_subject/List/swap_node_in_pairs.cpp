//Given a linked list, swap every two adjacent nodes and return its head.
//For example,
//    Given1->2->3->4, you should return the list as2->1->4->3.
//    Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

//将链表的连续两个节点进行交换，不能修改链表的值
LinkListNode *swapPairs(LinkListNode *head)
{
    if(head == NULL)
    {
        return NULL;
    }
    //定义新链表的头指针，初始为原链表的头指针
    LinkListNode* new_head = head;
    //如果链表中不止有一个元素，则需要修改新链表指针的指向
    if(head->next != NULL)
    {
        new_head = head->next;
    }
    //保存当前元素
    LinkListNode* cur = head;
    //保存上一个元素
    LinkListNode* prev = head;
    //保存cur之后要移动的元素
    LinkListNode* delete = head;
    //保存delete之后的元素
    LinkListNode* next = NULL;
    //当前元素为空，说明元素个数为双数
    //当前元素的下一个元素为空，说明元素个数为单数
    while(cur != NULL && cur->next != NULL)
    {
        //保存要移动的元素
        delete = cur->next;
        //保存要移动元素的下一个元素
        next = delete->next;
        //对指针的指向进行修改
        cur->next =next;
        delete->next = cur;
        cur = cur->next;
        //如果操作的不是前两个元素，需要链接前一个元素
        //在修改前一个元素指针
        if(delete->next != head)
        {
            prev->next = delete;
            prev = delete->next;
        }
    }
    return new_head;
}
