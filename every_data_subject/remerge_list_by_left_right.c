class Solution {
    public:
        /**
         *  *按照左右半区的方åSuperTab('n')
         *          ¼重新组合单链表
         *           *输入：一个单链表的头节点head
         *                      *将链表调整成题目要求的样子
         *                       *
         *                        *后台的单链表节点类如下：
         *                         *
         *                          struct ListNode {
         *                          int val;
         *                          struct ListNode *next;
         *                          ListNode(int x) :
         *                          val(x), next(NULL) {
         *                          }
         *                          };
         *                           */
        void relocateList(struct ListNode* head) {
//            if(head == NULL)
//            {
//                return;
//
//            }
//            //统计链表中结点的个数
            struct ListNode* cur = head;
            int count = 0;
            while(cur != NULL)
            {
                count++;
                cur = cur->next;
            }

            //如果链表中节点个数小于等于3,则该链表不需要进行重新组合
            if(count < 4)
            {
                return;
            }
            //左半部分结点的个数
            int lsize = count/2;

            //rcur从左半部分的末尾开始
            //每次分离rcur之后的节点
            int index = 0;
            struct ListNode* rcur = head;
            for(;index < lsize - 1;index++)
            {
                rcur = rcur->next;
            }
            //lcur从头结点开始
            struct ListNode* lcur = head;
            index = 0;

            //定义要分离的节点指针
            struct ListNode* to_remove = NULL;
            //如果左半部分有lsize个节点，只需要分离lsize-1次即可实现
            for(index = 0;index < lsize - 1;index++)
            {
                //将需前移的结点从链表中分离出来
                //rcur一直保持不变，变化的是rcur之后的节点
                //分离的也是rcur之后的节点
                to_remove = rcur->next;
                rcur->next = to_remove->next;

                //再将分离出来的前结点插入到前面
                to_remove->next = lcur->next;
                lcur->next = to_remove;

                //lcur后移两步
                lcur = lcur->next->next;
            }
        }
};
}
}
}
}
*                          }
*                          }
}
