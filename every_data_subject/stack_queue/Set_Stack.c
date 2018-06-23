//请实现一种数据结构SetOfStacks，由多个栈组成，其中每个栈的大小为size，
//当前一个栈填满时，新建一个栈。该数据结构应支持与普通栈相同的push和pop操作。
//给定一个操作序列int[][2] ope(C++为vector<vector<int>>)，每个操作的第一个数代表操作类型，
//若为1，则为push操作，后一个数为应push的数字；若为2，则为pop操作，后一个数无意义。
//请返回一个int[][](C++为vector<vector<int>>)，为完成所有操作后的SetOfStacks，
//顺序应为从下到上，默认初始的SetOfStacks为空。保证数据合法。

class SetOfStacks {
    public:
        vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
            vector<vector<int> > stacklist;
            if(ope.empty())
            {
                return ope;
            }
            int index = 0;

            for(index = 0;index < ope.size();index++)
            {
                //入栈操作
                if(ope[index][0] == 1)
                {
                    //如果第一个栈为空，或当前栈中元素已满，则需要新创建一个栈
                    if(stacklist.empty() || stacklist.back().size() >= size)
                    {
                        vector<int> temp;
                        temp.push_back(ope[index][1]);
                        stacklist.push_back(temp);
                    }
                    else//如果当前栈存在且没有满
                    {
                        stacklist.back().push_back(ope[index][1]);
                    }
                }
                //出栈操作
                else if(ope[index][0] == 2)
                {
                    //如果当前栈为空
                    if(stacklist.back().size() == 0)
                    {
                        //将当前栈弹出
                        stacklist.pop_back();
                        //在弹出新的当前栈的栈顶元素
                        stacklist.back().pop_back();
                    }
                    else//如果当前栈不为空
                    {
                        //直接弹出当前栈的栈顶元素
                        stacklist.back().pop_back();
                    }
                }
            }
            return stacklist;
        }
};
