/*
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * TreeNode(int x) :
 * val(x), left(NULL), right(NULL) {
 * } 
 * };*/

//因为二叉树的中序遍历序列与排序后的序列相同，所以这里采取中序遍历
void _Convert(TreeNode* root,TreeNode** tail)
{
    if(root == NULL)
    {
        return;
    }
    //对树的左子树进行排序
    _Convert(root->left,tail);
    //然后将根节点的左子树置为排序链表的尾节点
    root->left = *tail;
    //如果待排序链表的尾节点不为空，则将尾节点的右子树置为根节点
    if(*tail != NULL)
    {
        (*tail)->right = root;
    }
    //然后更新尾节点的值
    *tail = root;
    //然后对根节点的右子树进行排序
    _Convert(root->right,tail);
    return;
}

class Solution {
    public:
        TreeNode* Convert(TreeNode* pRootOfTree)
        {
            if(pRootOfTree == NULL)
            {
                return NULL;
            }
            //首先遍历二叉树，找到最左下方的结点
            TreeNode* cur = pRootOfTree;
            while(cur->left != NULL)
            {
                cur = cur->left;
            }
            //此时的cur即为待返回双向链表的头结点
            TreeNode* head = cur;
            //然后对二叉树进行排序
            //设置一个节点变量保存已经排序链表的尾节点
            TreeNode* new_tail = NULL;
            _Convert(pRootOfTree,&new_tail);
            return head;
        }
};
