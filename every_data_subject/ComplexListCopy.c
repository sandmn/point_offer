
//通过偏移量来进行拷贝
//创建复杂链表节点函数
RandomListNode* CreateNode(int value)
{
    RandomListNode* new_node = (RandomListNode*)malloc(sizeof(RandomListNode));
    new_node->label = value;
    new_node->next = NULL;
    new_node->random = NULL;
    return new_node;
}
//计算偏移量数
int Offset(RandomListNode* head,RandomListNode* random)
{
    //如果结点的random指向NULL，此时将偏移量设置为-1
    if(random == NULL)
    {
        return -1;//random指向NULL
    }
    //偏移量初始为0
    int offset = 0;
    while(head != random)
    {
        //当遇到一个不是random的结点，偏移量就加1
        head = head->next;
        offset++;
    }
    //返回偏移量
    return offset;
}
//根据偏移量设置random的值
RandomListNode* OffRan(RandomListNode* head,int offset)
{
    //如果偏移量为-1，说明random指向NULL,此时，直接返回NULL即可
    if(offset == -1)
    {
        return NULL;
    }
    //如果偏移量为0，说明指向头结点，此时，返回头结点即可，这步操作不要也可以
    if(offset == 0)
    {
        return head;
    }
    //然后从头结点开始，只要offset不为0，就往后移动，当offset为0时
    //此时head指向的就是rando指向的节点指针
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
            //如果原链表为空，直接返回NULL即可
            if(pHead == NULL)
            {
                return NULL;
            }
            //否则，原链表中至少有一个结点
            //首先创建该结点，得到新链表的头指针
            RandomListNode* newhead = CreateNode(pHead->label);

            //然后开始遍历原链表（从第二个节点开始遍历）和新链表（从第一个结点开始）
            //原链表中遇到非空结点就将该结点作为新链表结点的下一个节点
            RandomListNode* newcur = newhead;
            RandomListNode* cur = pHead->next;
            while(cur != NULL)
            {
                newcur->next = CreateNode(cur->label);
                cur = cur->next;
                newcur = newcur->next;
            }
            //再从头遍历原链表和新链表
            cur = pHead;
            newcur = newhead;
            while(cur != NULL)
            {
                //根据原链表中的结点计算该结点距头结点的偏移量
                int offset = Offset(pHead,cur->random);
                //根据偏移量设置新链表结点random的值
                newcur->random = OffRan(newhead,offset);
                cur = cur->next;
                newcur = newcur->next;
            }
            //当原链表中的所有节点都遍历完了，此时新链表也遍历完了，并且新链表中所有的random都已经设置好了
            //此时，直接返回新链表的头结点即可
            return newhead;
        }
};










