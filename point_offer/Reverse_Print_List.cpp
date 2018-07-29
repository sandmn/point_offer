/**
 * *  struct ListNode {
 * *        int val;
 * *        struct ListNode *next;
 * *        ListNode(int x) :
 * *              val(x), next(NULL) {
 * *        }
 * *  };
 * */
class Solution {
    public:
        vector<int> printListFromTailToHead(ListNode* head) {
            //首先定义一个数组用于存放返回值
            vector<int> ArrayList;
            //如果链表为空直接返回空数组
            if(head == NULL)
            {
                return ArrayList;
            }
            //如果链表不为空，先获取当前节点之后结点的逆置序列数组
            ArrayList = printListFromTailToHead(head->next);
            //在将当前节点的值尾插到待返回数组中
            ArrayList.push_back(head->val);
            return ArrayList;
        }
};
