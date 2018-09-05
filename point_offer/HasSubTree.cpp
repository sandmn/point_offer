/*
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * TreeNode(int x) :
 * val(x), left(NULL), right(NULL) {
 * }
 * };*/

bool IsSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
{
    if(pRoot2 == NULL)
    {
        return true;
    }
    else if(pRoot1 == NULL)
    {
        return false;
    }
    else //二者均不为空
    {
        if(pRoot1->val != pRoot2->val)
        {
            return false;
        }
        return IsSubtree(pRoot1->left,pRoot2->left) && IsSubtree(pRoot1->right,pRoot2->right);
    }
}


class Solution {
    public:
        bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
        {
            if(pRoot1 == NULL || pRoot2 == NULL)
            {
                return false;
            }
            return IsSubtree(pRoot1,pRoot2) || IsSubtree(pRoot1->left,pRoot2) || IsSubtree(pRoot1->right,pRoot2);
        }
};
