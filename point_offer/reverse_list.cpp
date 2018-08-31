/*
 * struct ListNode {
 * int val;
 * struct ListNode *next;
 * ListNode(int x) :
 * val(x), next(NULL) {
 * }
 * };*/
class Solution {
    public:
        ListNode* ReverseList(ListNode* pHead) {
            //方法三：递归求解
            //将第一个结点的next置空以便作为最后一个节点，对链表之后的结点进行逆置，再将第一个结点放置在逆置之后的链表后
            if(pHead == NULL)
            {
                return NULL;
            }
            if(pHead->next == NULL)
            {
                return pHead;
            }
            ListNode* last_node = pHead;
            //记录之后的结点以便进行反转
            ListNode* next_node = last_node->next;
            last_node->next = NULL;
            ListNode* newhead = ReverseList(next_node);
            next_node->next = last_node;
            return newhead;



            //方法一：
            //创建一个新的头结点，遍历原链表，删除一个节点，将该结点在插入到新链表中
            //if(pHead == NULL)
            //{
            //    return NULL;
            //}
            //ListNode* cur = pHead;
            //ListNode* newhead = NULL;
            //while(cur != NULL)
            //{
            //    //记录待删除结点的下一个节点
            //    ListNode* next_node = cur->next;
            //    //将待删除结点头插到新链表中
            //    cur->next = newhead;
            //    newhead = cur;
            //    cur = next_node;
            //}
            //return newhead;


            //方法二：
            //if(pHead == NULL)
            //{
            //    return NULL;
            //}
            // //首先找到最后一个节点
            // ListNode* last_node = pHead;
            // while(last_node->next != NULL)
            // {
            //     last_node = last_node->next;
            // }
            // //然后从头开始遍历链表
            // //遍历到一个节点，将该结点删除，然后插入到最后一个节点之后
            // //知道遍历到最后一个节点为止
            // ListNode* to_delete = pHead;
            // while(to_delete != last_node)
            // {
            //     //首先记录最后一个节点的下一个节点
            //     ListNode* next_node = last_node->next;
            //     //将头指针后移，继而删除头结点
            //    pHead = to_delete->next;
            //     //将删除的结点插入到最后一个节点之后
            //     last_node->next = to_delete;
            //     to_delete->next = next_node;
            //     to_delete = pHead;
            //}
            // return last_node;
        }
};
}
}
}
}
}
}
}
}
}
* }
* }
