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
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
        {
            if(pHead1 == NULL)
            {
                return pHead2;

            }
            else if(pHead2 == NULL)
            {
                return pHead1;

            }
            ListNode* cur1 = pHead1;
            ListNode* cur2 = pHead2;
            ListNode* new_head = NULL;
            ListNode* new_tail = NULL;
            while(cur1 != NULL && cur2 != NULL)
            {
                if(cur1->val < cur2->val)
                {
                    if(new_head == NULL)
                    {
                        new_head = new_tail = cur1;

                    }
                    else
                    {
                        new_tail->next = cur1;
                        new_tail = new_tail->next;

                    }
                    cur1 = cur1->next;

                }
                else
                {
                    if(new_head == NULL)
                    {
                        new_head = new_tail = cur2;

                    }
                    else
                    {
                        new_tail->next = cur2;
                        new_tail = new_tail->next;

                    }
                    cur2 = cur2->next;

                }

            }
            if(cur1 != NULL)
            {
                new_tail->next = cur1;

            }
            else
            {
                new_tail->next = cur2;

            }
            return new_head;

        }

};
