
TreeNode*  CreateTree(TreeNode* root)
{
    //如果二叉树为空
    if(root == NULL)
    {
        return NULL;
    }
    //如果二叉树不为空，则遍历到一个结点，创建该结点
   TreeNode* rootmirror =  CreateNode(root->data);
   if(root->lchild != NULL)
   {
       rootmirror->lchild = CreateTree(root->lchild);
   }
   if(root->rchild != NULL)
   {
       rootmirror->rchild = CreateTree(root->rchild);
   }
   return rootmirror;

}

//判断两棵树是否相同
int isequal(TreeNode* root1,TreeNode* root2)
{
    if(root1 == NULL && root2 ==NULL)
    {
        return 1;
    }
    if(root1->data == root2->data)
    {
        int ret1 = isequal(root1->lchild,root2->lchild);
        int ret2 = isequal(root1->rchild,root2->rchild);
        if(ret1 == 1 && ret2 == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
//判断一棵二叉树是否对称，对称就是该二叉树的镜像与其相同
int isSymmetrical(TreeNode* root)
{
    if(root == NULL)
    {
        return 1;
    }
    //先原样创建一棵二叉树
    TreeNode* rootmirror = CreateTree(root);
    //将新创建的二叉树转换为其镜像
    TreeMirror(rootmirror);
    //判断原二叉树与镜像是否相同
    return isequal(root,rootmirror);

}

//判断两棵子树是否对称
//如果两棵树对称，则
//1.这两棵树的根节点的值相同
//2.一棵树的左子树与另一棵树的右子树对称
//3.一棵树的右子树与另一棵树的左子树对称
int isTreeSymmetrical(TreeNode* root1,TreeNode* root2)
{
    //如果两棵树均为空，则相等
    if(root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    if(root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    if(root1->data == root2->data)
    {
        int ret1 = isTreeSymmetrical(root1->lchild,root2->rchild);
        int ret2 = isTreeSymmetrical(root1->rchild,root2->lchild);
        if(ret1 == 1 && ret2 == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
//判断一棵二叉树是否对称，对称就是该二叉树的镜像与其相同
//不额外创建二叉树
int isSymmetricalEx(TreeNode* root)
{
    //如果根节点为空，则二叉树对称
    if(root == NULL)
    {
        return 1;
    }
    //如果根节点不为空，则判断根节点的左右子树是否对称
    return isTreeSymmetrical(root->lchild,root->rchild);
}
