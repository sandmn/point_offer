class TwoStacks {
    public:
        vector<int> twoStacksSort(vector<int> numbers) {
            int index = 0;
            //统计数组的元素个数
            int size = sizeof(numbers)/sizeof(numbers[0]);
            //将数组元素全部插入到栈1中
            int top2;
            for(;index < size;index++)
            {
                stack1.push(numbers[index]);
            }

            //当栈1不为空时
            while(stack1.size() > 0)
            {
                //取栈1的栈顶元素
                int top1 = stack1.top();
                //如果此时栈2为空，则直接将栈1的栈顶元素插入到栈2中，然后弹出栈1的栈顶元素
                if(stack2.size() <= 0)
                {
                    stack2.push(top1);
                    stack1.pop();
                }
                //如果此时栈2不为空，则取栈2的栈顶元素
                //如果top1>top2,则直接将top1入栈到栈2中，并弹出栈1的栈顶元素
                //如果top1<top2,则先弹出top1，然后将循环将栈2的大于top1的栈顶元素进行弹出，入栈到栈1中。
                //                循环结束后，最后将top1入栈到栈2中
                else
                {
                    top2 = stack2.top();
                    if(top1 >= top2)
                    {
                        stack2.push(top1);
                        stack1.pop();
                    }
                    else
                    {
                        stack1.pop();
                        while(top1 < top2)
                        {
                            stack1.push(top2);
                            stack2.pop();
                            top2 = stack2.top();
                        }
                        stack2.push(top1);
                    }   
                }
            }
            for(index = 0;index < size;index++)
            {
                top2 = stack2.top();
                stack2.pop();
                numbers[index] = top2;
            }
            return numbers;
        }
    private:
        stack<int> stack1;//存放未排序的元素
        stack<int> stack2;//存放排序后的元素
};
