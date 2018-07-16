#include<iostream>
#include<stack>
using namespace std;


class Solution
{
    public:
        void Push(int data)
        {
            //入队列时，直接在插入栈中插入元素
            stack_input.push(data);
            cout<<"push:"<<data<<endl;
            return;
        }
        void Pop()
        {
            //出队列时，如果输出栈的元素为空，则需要将输入栈中的元素全部搬运到输出栈中
            if(stack_output.empty())
            {
                //如果输入队列不为空
                while(stack_input.empty() != 1)
                {
                    int top = stack_input.top();
                    stack_output.push(top);
                    stack_input.pop();
                }
            }
            //最后弹出输出栈的栈顶元素
            //如果两个栈均为空时
            if(stack_output.empty())
            {
                cout<<"队列为空"<<endl;
                return;
            }
            cout<<"pop:"<<stack_output.top()<<endl;
            stack_output.pop();
            return;
        }
    private:
        stack<int> stack_input;
        stack<int> stack_output;
};

int main()
{
    Solution queue;
    queue.Push(1);
    queue.Push(2);

    queue.Pop();
    queue.Pop();
    queue.Pop();
    return 0;
}

























////注意pop函数的返回值，无论队列是否为空，返回值均为队首元素
//class Solution
//{
//    public:
//        //无论栈2是否为空，在栈1中插入元素
//        void push(int node) {
//            stack1.push(node);
//        }
//
//        //出队列时：
//        //如果栈2的元素不为空，则直接出栈即可
//        //如果栈2中的元素为空，则将栈1中的元素全部倒腾到栈2中，再对栈2进行出栈
//        //     如果倒腾完之后的栈2还是为空，则说明该队列为空
//        //     最后返回出栈的元素即可
//        int pop() {
//            if(stack2.size() <= 0)
//            {
//                while(stack1.size() > 0)
//                {
//                    int top = stack1.top();
//                    stack2.push(top);
//                    stack1.pop();
//
//                }
//
//            }
//            if(stack2.size() == 0)
//            {
//                printf("queue is empty\n");
//
//            }
//            int head = stack2.top();
//            stack2.pop();
//            return head;
//        }
//
//    private:
//        stack<int> stack1;
//        stack<int> stack2;
//};



//class Solution
//{
//    public:
//        void push(int node) {
//            在栈1中进入栈的操作，栈2中进行出栈的操作
//                //如果栈2不为空，则对栈2取栈顶元素，然后出栈2，插入到栈1中
//                while(!stack2.empty())
//                {
//                    int top = stack2.top();
//                    stack2.pop();
//                    stack1.push(top);
//                }
//            //将栈2中的元素全部倒腾到栈1中之后，在对栈1进行入栈操作
//            stack1.push(node);
//        }
//
//        int pop() {
//            //如果栈1不为空，则将栈1中的元素进行取栈顶元素，出栈1，插入到栈2中
//            while(!stack1.empty())
//            {
//                int top = stack1.top();
//                stack1.pop();
//                stack2.push(top);
//            }
//            //将栈1中的元素全部倒腾到栈2中之后，在对栈2进行出栈操作
//            //如果倒腾完之后，栈2还是为空，说明，队列中元素为空
//            if(stack2.empty())
//            {
//                return 0;
//            }
//            stack2.pop()
//        }
//}
