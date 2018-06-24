/*
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * TreeNode(int x) :
 * val(x), left(NULL), right(NULL) {
 * }
 * };*/

//求一棵树的深度
class Solution {
    public:
        int TreeDepth(TreeNode* pRoot)
        {
            if(pRoot == NULL)
            {
                return 0;

            }
            int ret1 = TreeDepth(pRoot->left);
            int ret2 = TreeDepth(pRoot->right);
            if(ret1 > ret2)
            {
                return ret1 + 1;

            }
            else
            {
                return ret2 + 1;

            }

        }

};
