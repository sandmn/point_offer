#include<iostream>
#include<queue>
using namespace std;

//两个队列实现一个栈
class Stack
{
    public:
        void Push(int data)
        {
            //哪个队列不为空，则入队哪个
            if(queue1.empty())
            {
                queue2.push(data);
            }
            else
            {
                queue1.push(data);
            }
        }
        int Pop()
        {
            //将非空队列的前n-1个元素入队到另一个队列中，然后将最后一个元素出队
            if(queue1.empty() && queue2.empty())
            {
                cout<<"栈为空"<<endl;
                return -1;
            }
            if(queue1.empty() != 1)
            {
                while(queue1.size() != 1)
                {
                    int front = queue1.front();
                    queue2.push(front);
                    queue1.pop();
                }
                int front =  queue1.front();
                queue1.pop();
                return front;
            }
            else
            {
                while(queue2.size() != 1)
                {
                    int front = queue2.front();
                    queue1.push(front);
                    queue2.pop();
                }
                int front = queue2.front();
                queue2.pop();
                return front;
            }
        }
    private:
        queue<int> queue1;
        queue<int> queue2;
};

int main()
{
    Stack s;
    s.Push(1);
    s.Push(2);
    cout<<s.Pop()<<endl;
    cout<<s.Pop()<<endl;
    s.Pop();
    return 0;
}
