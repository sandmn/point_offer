

void _Reverse(SeqStack* stack,SeqStackType data)
{
    //如果此时栈中没有元素，则将参数的栈顶元素插入栈中
    if(stack->size == 0)
    {
        SeqStackPush(stack,data);
        return;
    }

    //如果栈中还有元素则一直出栈，直到栈中没有元素
    SeqStackType tmp;
    SeqStackTop(stack,&tmp);
    SeqStackPop(stack);
    _Reverse(stack,data);

    //将上一个函数的栈顶元素插入栈之后，在插入本次函数的栈顶元素
    SeqStackPush(stack,tmp);
}

void Reverse(SeqStack* stack)
{
    //当栈中没有元素或只有一个元素时，不用逆置
    if(stack->size == 0 || stack->size == 1)
    {
        return;
    }

    //当栈中元素大于1时，一直出栈，直到栈中只有一个元素
    SeqStackType top;
    SeqStackTop(stack,&top);
    SeqStackPop(stack);
    Reverse(stack);

    //当出栈到栈中只有一个元素时，将此时的栈顶元素作为参数调用该函数
    _Reverse(stack,top);
}
