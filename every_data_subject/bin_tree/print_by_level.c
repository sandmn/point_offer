

//层序打印二叉树：
//从上到下按层打印二叉树，同一层节点从左到右输出。每一层输出一行。
//用二维数组保存输出的层序遍历结果
//二维数组中的一维数组存放二叉树的一层节点
//最后返回二维数组


/*
 * struct TreeNode {
 *     int val;
 *         struct TreeNode *left;
 *             struct TreeNode *right;
 *                 TreeNode(int x) :
 *                             val(x), left(NULL), right(NULL) {
 *                                 }
 *                                 };
 *                                 */
class Solution {
    public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            //定义一个二维数组
            vector<vector<int> > arr;
            if(pRoot == NULL)//如果二叉树为空，直接返回空的二叉树
            {
                return arr;
            }
            //定义一个队列，存放二叉树中的结点，将二叉树结点的地址存放在队列中
            std::queue<TreeNode*> q;
            //将根节点入队列
            q.push(pRoot);

            //当队列不为空时
            while(!q.empty())
            {
                //统计此时队列中的元素
                int size = q.size();
                //定义一维数组，存放二叉树每一层的数据
                vector<int> a;
                while(size--)
                {
                    TreeNode* front = q.front();//取队首元素
                    q.pop();//出队队首元素
                    a.push_back(front->val);//将出队的元素保存在一维数组中
                    //将出队元素的左右结点元素入队
                    //如果左结点不为空，则将该结点入队列
                    if(front->left != NULL)
                    {
                        q.push(front->left);   
                    }
                    //如果右结点不为空，则将该结点入队
                    if(front->right != NULL)
                    {
                        q.push(front->right);
                    }
                }
                //将一维数组存放在二维数组中
                arr.push_back(a);
            }          
            return arr;
        }

};

