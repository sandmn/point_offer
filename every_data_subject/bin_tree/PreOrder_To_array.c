

//将二叉树的先序遍历结果存入数组中

/**
 *
 *  * Definition for binary tree
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */

//非递归实现
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode *root) {
            vector<int> arr;
            if(root == NULL)
            {
                return arr;

            }
            //定义一个栈
            std::stack<TreeNode*> s;
            s.push(root);//将根节点入栈
            //当栈不为空时
            while(!s.empty())
            {
                TreeNode* top = s.top();//取栈顶元素
                arr.push_back(top->val);//将栈顶元素存入数组中
                s.pop();//弹出栈顶元素
                //如果栈顶元素的右结点不为空，入栈右结点
                if(top->right != NULL)
                {
                    s.push(top->right);
                }
                //如果栈顶元素的左结点不为空，入栈左结点
                if(top->left != NULL)
                {
                    s.push(top->left);
                }
            }
            return arr;
        }
};

//递归实现
void _PrintPreOrder(TreeType* arr,TreeNode* root,int* index)
{
    if(root == NULL)
    {
        return;
    }
    arr[*index] = root->data;
    (*index)++;
    if(root->lchild != NULL)
    {
        _PrintPreOrder(arr,root->lchild,index);
    }
    if(root->rchild != NULL)
    {
        _PrintPreOrder(arr,root->rchild,index);
    }
    return;    
}

//将一棵二叉树的先序序列存放在一个数组中（递归实现）
TreeType* PrintPreOrder(TreeNode* root)
{
    TreeType* arr = (TreeType*)malloc(10*sizeof(TreeType));
    memset(arr,0,sizeof(arr));
    int index = 0;
    _PrintPreOrder(arr,root,&index);
    return arr;
}

