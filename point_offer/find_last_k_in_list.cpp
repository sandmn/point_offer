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
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            //方法一：提前不用遍历一遍了链表
            if(pListHead == NULL || k == 0)
            {
                return NULL;
            }
            //快指针先走k步，如果快指针指向空，有两种情况
            //一种是k值等于结点的个数（此时合法），一种是k值大于结点的个数（此时不合法）
            //所以不能用指针指向空来判断，可以利用k值来进行判断
            //如果循环迭代的次数小于k值时，指针指向空，说明此时k的个数大于链表的个数
            //当循环迭代的次数大于等于k值时，说明合法
            ListNode* fast = pListHead;
            ListNode* slow = pListHead;
            int i = 0;
            for(;i < k;i++)
            {
                if(fast == NULL)
                {
                    break;
                }
                fast = fast->next;
            }
            //此时k的值大于结点的个数
            if(i < k)
            {
                return NULL;
            }
            while(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;

            //方法二：需遍历一遍链表
            //if(pListHead == NULL || k == 0)
            //{
            //    return NULL;
            //}
            ////统计链表中的结点个数
            //ListNode* cur = pListHead;
            //int count = 0;
            //while(cur != NULL)
            //{
            //    count++;
            //    cur = cur->next;
            //}
            ////如果K的值大于链表中的结点个数，则出错
            //if(k > count)
            //{
            //    return NULL;
            //}
            ////定义一个快指针和一个慢指针，快指针先走k步,然后快慢指针一次一步，当快指针指向空时，慢指针即为倒数第k个结点
            //ListNode* fast = pListHead;
            //ListNode* slow = pListHead;
            //int i = 0;
            //for(;i < k;i++)
            //{
            //    fast = fast->next;
            //}
            //while(fast != NULL)
            //{
            //    fast = fast->next;
            //    slow = slow->next;
            //}
            //return slow;
        }
};
