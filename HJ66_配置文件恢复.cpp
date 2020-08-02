//17:42-18:40  中间查询了erase和迭代器的
//还是写的有些复杂，实际上是可以用erase和迭代器的，用两个变量（一个记录最后一个匹配的命令id,一个记录匹配的个数）
//stringstream，也不是每次都需要创建的，使用stringstream.str("")可以清空字符串。注意，必须定时用str("")清空stringstream，否则stringstream的内存需求会不断增长。
//但是，对于同一个stringstream,如果是“多次”进行数据类型转换，必须用stringstream.clear()重置标志位，否则转换不正确。
//参考文献：https://blog.csdn.net/sunshineacm/article/details/78068987
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
string command[6] = {
    "reset", "reset board", "board add", "board delete", 
    "reboot backplane", "backplane abort"
};
string execute[6] = {
    "reset what", "board fault", "where to add", "no board at all", 
    "impossible", "install first"
};

bool isMatched(const string & command, const string & input)
{
    if(0==command.find(input))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void analysisCommand(const string & input)
{
    string temp;
    vector<string> inputStrings;
    istringstream out(input);//这里用stringstream就可以，既可以i也可以o
    while(out>>temp)
    {
        inputStrings.push_back(temp);
    }
    
    if(0==inputStrings.size() || inputStrings.size()>3)
    {
        cout<<"unknown command"<<endl;
    }
    else if(1==inputStrings.size())//如果只输入一个字符串
    {
        //如果匹配“reset”命令
        if(isMatched(command[0], inputStrings[0]))
        {
            cout<<execute[0]<<endl;
        }
        else//如果不匹配“reset”命令；或者，若只输入一字串，但本条命令有两个关键字，则匹配失败。
        {
            cout<<"unknown command"<<endl;
        }
    }
    else//如果输入2个字符串
    {
        vector<int> matchedId;
        for(int i=1;i<6;i++)
        {
            istringstream tempStream(command[i]);
            tempStream>>temp;
            if(isMatched(temp, inputStrings[0]))
            {
                matchedId.push_back(i);
            }
        }
        
        //如果存在第一个字符串匹配，则查验第二个字符串是否匹配
        if(matchedId.size())
        {
            for(auto itr = matchedId.begin(); itr!=matchedId.end(); )
            {
                istringstream tempStream(command[*itr]);
                tempStream>>temp>>temp;
                if(isMatched(temp, inputStrings[1]))
                {
                    //什么也不做
                    itr++;
                }
                else
                {
                    itr=matchedId.erase(itr);
                }
            }
            
            if(1==matchedId.size())
            {
                cout<<execute[matchedId[0]]<<endl;
            }
            else
            {
                cout<<"unknown command"<<endl;
            }
        }
        else
        {
            cout<<"unknown command"<<endl;
        }
    }
}


int main()
{
    string input;
    while(getline(cin, input))
    {
        analysisCommand(input);
    }
}
