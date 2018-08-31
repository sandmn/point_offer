/*
 * struct TreeNode {
 * int val;
 * struct TreeNode *left;
 * struct TreeNode *right;
 * TreeNode(int x) :
 * val(x), left(NULL), right(NULL) {
 * }
 * };*/
class Solution {
    public:
        void Mirror(TreeNode *pRoot) {
            if(pRoot == NULL)
            {
                return;

            }
            //对二叉树进行层序遍历，遍历到一个节点，就交换两个子树
            //利用队列来辅助层序遍历
            queue<TreeNode*> q;
            q.push(pRoot);
            while(1)
            {
                //取队首元素，如果队首元素不为空，则将队首元素出队，并交换左右子树
                //如果队首元素的左右子树不为空，则将队首元素的左右子树入队
                if(q.empty() == 1)
                {
                    break;
                }
                TreeNode* top = q.front();
                swap(top->left,top->right);
                q.pop();
                if(top->left != NULL)
                {
                    q.push(top->left);
                }
                if(top->right != NULL)
                {
                    q.push(top->right);
                }
            }

        }
};
