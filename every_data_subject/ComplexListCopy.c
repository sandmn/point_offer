
//复杂链表的复制
RandomListNode* CreateNode(int value)
{
    RandomListNode* new_node = (RandomListNode*)malloc(sizeof(RandomListNode));
    new_node->label = value;
    new_node->next = NULL;
    new_node->random = NULL;
    return new_node;

}
int Offset(RandomListNode* head,RandomListNode* random)
{
    if(random == NULL)
    {
        return -1;//random指向NULL

    }
    int offset = 0;
    while(head != random)
    {
        head = head->next;
        offset++;

    }
    return offset;

}
RandomListNode* OffRan(RandomListNode* head,int offset)
{
    if(offset == -1)
    {
        return NULL;

    }
    if(offset == 0)
    {
        return head;

    }
    while(offset--)
    {
        head = head->next;

    }
    return head;

}
class Solution {
    public:
        RandomListNode* Clone(RandomListNode* pHead)
        {
            if(pHead == NULL)
            {
                return NULL;

            }
            RandomListNode* cur = pHead->next;
            RandomListNode* newhead = CreateNode(pHead->label);
            RandomListNode* newcur = newhead;
            while(cur != NULL)
            {
                newcur->next = CreateNode(cur->label);
                cur = cur->next;
                newcur = newcur->next;

            }
            cur = pHead;
            newcur = newhead;
            while(cur != NULL)
            {
                //计算偏移量
                int offset = Offset(pHead,cur->random);
                //根据偏移量设置random的值
                newcur->random = OffRan(newhead,offset);
                cur = cur->next;
                newcur = newcur->next;
            }
            return newhead;
        }
};
