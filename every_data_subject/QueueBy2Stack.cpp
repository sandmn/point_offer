class Solution
{
    public:
        void push(int node) {
            在栈1中进入栈的操作，栈2中进行出栈的操作
                //如果栈2不为空，则对栈2取栈顶元素，然后出栈2，插入到栈1中
                while(!stack2.empty())
                {
                    int top = stack2.top();
                    stack2.pop();
                    stack1.push(top);
                }
            //将栈2中的元素全部倒腾到栈1中之后，在对栈1进行入栈操作
            stack1.push(node);
        }

        int pop() {
            //如果栈1不为空，则将栈1中的元素进行取栈顶元素，出栈1，插入到栈2中
            while(!stack1.empty())
            {
                int top = stack1.top();
                stack1.pop();
                stack2.push(top);
            }
            //将栈1中的元素全部倒腾到栈2中之后，在对栈2进行出栈操作
            //如果倒腾完之后，栈2还是为空，说明，队列中元素为空
            if(stack2.empty())
            {
                return 0;
            }
            stack2.pop()
        }
}
