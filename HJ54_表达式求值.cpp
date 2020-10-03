#include<stack>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<map>
#include<vector>
#include<sstream>

using namespace std;

//不合法输出啥呢？题目里也没有说明，好像也不用管.....虽然说了做题者要负责合法性检查....
//思路，先求后缀表达式，再用后缀表达式求值。代码还是有些场，200行了

/*
char转string，不要用to_string(参数)，因为这个调用的是to_string(int)，会把char当做一个整数，翻译做数字
              要用string(1,char)，或者string={char}，都是调用string的构造函数，直接生成一个string

使用stringstream>>int>>string;//这个语句中，如果向int输入后，stringstream中不存在其他东西后，string将仍然保持原来的值，不会被清空。
              所以，循环输入的时候，需要清空int、string，否则无法知道int或者string中是否是新输入的数据
*/

/*
bool isOperator(char c)
{
    if('+'==c || '-'==c ||'*'==c ||'/'==c)
    {
        return true;
    }
    else
    {
        return false;
    }
}



int calc(const string & express)
{
    stack<char> sigStack;
    stack<int> dataStack;//float?
    
    char charTemp[100];
    memset(charTemp,0,100);
    string expressTemp = express;
    int dataTemp = 0;
    
    while(!expressTemp.empty())
    {
        if(isdigit(expressTemp[0]))
        {
            //如果第一个数字是0，则表达式有问题
            
            sscanf(expressTemp.c_str(), "%d%s", &dataTemp, charTemp);
            expressTemp = string(charTemp);
            dataStack.push(dataTemp);
        }
        else if(isOperator(expressTemp[0]))
        {
            if(sigStack.empty()||'('==sigStack.top())
            {
                sigStack.push(expressTemp[0]);
                expressTemp = expressTemp.substr(1);//1会不会超出界限？
            }
            else
            {
                while(('-'==expressTemp[0] || '+'==expressTemp[0])
                  && ('*'==sigStack.top() || '/'==sigStack.top()))
                {
                    if('*'==sigStack.top())
                    {
                        int right = dataStack.top();
                        dataStack.pop();
                        int left = dataStack.top();//需要检查是否为空吗？
                        dataStack.pop();
                        dataStack.push(right*left);
                    }
                    else if('/'==sigStack.top())
                    {
                        int right = dataStack.top();
                        dataStack.pop();
                        int left = dataStack.top();//需要检查是否为空吗？
                        dataStack.pop();
                        dataStack.push(left/right);
                    }
                    sigStack.pop();
                }
                
                sigStack.push(expressTemp[0]);
                expressTemp = expressTemp.substr(1);//1会不会超出界限？
            }
        }
        else if('('==expressTemp[0])
        {
            sigStack.push(expressTemp[0]);
            expressTemp = expressTemp.substr(1);//1会不会超出界限？
        }
        else if(')'==expressTemp[0])
        {
            while(!sigStack.empty()&&'('!=sigStack.top())
            {
                int right = dataStack.top();
                dataStack.pop();
                int left = dataStack.top();//需要检查是否为空吗？
                dataStack.pop();
                
                switch(sigStack.top())
                {
                    case '+':
                        dataStack.push(left+right);
                        break;
                    case '-':
                        dataStack.push(left-right);
                        break;
                    case '*':
                        dataStack.push(left*right);
                        break;
                    case '/':
                        dataStack.push(left/right);
                        break;
                    default:
                        break;
                }
                sigStack.pop();
            }
            
            if('('==sigStack.top())
            {
                sigStack.pop();
            }
            
            expressTemp = expressTemp.substr(1);//1会不会超出界限？
        }
    }
    
    while(!sigStack.empty())
    {
        int right = dataStack.top();
        dataStack.pop();
        int left = dataStack.top();//需要检查是否为空吗？
        dataStack.pop();
                
        switch(sigStack.top())
        {
            case '+':
                dataStack.push(left+right);
                break;
            case '-':
                dataStack.push(left-right);
                 break;
            case '*':
                 dataStack.push(left*right);
                 break;
             case '/':
                 dataStack.push(left/right);
                 break;
             default:
                break;
        }
        sigStack.pop();
    }
    
    if(1==dataStack.size())
    {
        return dataStack.top();
    }
    else
    {
        return 0;//error
    }
}
*/
map<char, int> priority = 
{
    make_pair<char,int>('+',1),
    make_pair<char,int>('-',1),
    make_pair<char,int>('*',2),
    make_pair<char,int>('/',2),
    make_pair<char,int>('(',0),
    make_pair<char,int>(')',0),
};

bool isOpr(char ch)
{
    if('+'==ch || '-'==ch || '*'==ch || '/'==ch)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void convert2Postfix(const string & midfix, vector<string> &postfix)
{
    stack<char> oprStack;
    
    int digits = 0;
    string temp;
    
    //cout<<prefix.size()<<" | ";
    for(size_t i=0;i<midfix.size();)
    {
        //cout<<prefix[i]<<" | ";
        if('-'==midfix[i]&&(0==i || '('==midfix[i-1]))
        {
            stringstream ss(midfix.substr(i));
            //sscanf(prefix.sub_str(i), "%d%s", &digits);
            digits = 0; temp = "";
            ss>>digits>>temp;
            postfix.push_back(to_string(digits));
            i = midfix.size()-temp.size();
            
        }
        else if(isdigit(midfix[i]))
        {
            stringstream ss(midfix.substr(i));
            digits = 0; temp = "";
            ss>>digits>>temp;
            postfix.push_back(to_string(digits));
            i = midfix.size()-temp.size();
        }
        else if('(' == midfix[i])
        {
            oprStack.push('(');
            ++i;
        }
        else if(')' == midfix[i])
        {
            while(oprStack.size() && '(' != oprStack.top())
            {
                 char opr = oprStack.top();
                 postfix.push_back(string(1,opr));
                 oprStack.pop();
            }
            if(oprStack.size() && '(' == oprStack.top())
            {
                oprStack.pop();
                ++i;
            }
            else
            {
                postfix.clear();
                return ;
            }
        }
        else if(isOpr(midfix[i]))
        {
            if(0==oprStack.size())
            {
                oprStack.push(midfix[i]);
            }
            else
            {
                int priority1 = priority[midfix[i]];
                
                while(oprStack.size())
                {
                    int priority2 = priority[oprStack.top()];
                    
                    if(priority1<=priority2)
                    {
                        char opr = oprStack.top();
                        postfix.push_back(string(1,opr));
                        oprStack.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                oprStack.push(midfix[i]);
            }
            ++i;
        }
        else
        {
            postfix.clear();
            return ;
        }
    }
    
    while(oprStack.size())
    {
         char opr = oprStack.top();
         postfix.push_back(string(1,opr));
         oprStack.pop();
    }
    
}


void calcPostfix(const vector<string> &postfix)
{
    stack<int> digitStack;
    for(int i=0;i<postfix.size();++i)
    {
        if(1==postfix[i].size()&& isOpr(postfix[i][0]))
        {
            int left = 0;
            int right = 0;
            switch(postfix[i][0])
            {
                case '+':
                    right = digitStack.top();
                    digitStack.pop();
                    left = digitStack.top();
                    digitStack.pop();
                    digitStack.push(right+left);
                    break;
                case '-':
                    right = digitStack.top();
                    digitStack.pop();
                    left = digitStack.top();
                    digitStack.pop();
                    digitStack.push(left-right);
                    break;
                case '*':
                    right = digitStack.top();
                    digitStack.pop();
                    left = digitStack.top();
                    digitStack.pop();
                    digitStack.push(left*right);
                    break;
                case '/':
                    right = digitStack.top();
                    digitStack.pop();
                    left = digitStack.top();
                    digitStack.pop();
                    if(0!=right)
                    {
                        digitStack.push(left/right);
                    }
                    else
                    {
                        cout<<"error"<<endl;
                        return;
                    }
                    break;
                default:
                    
                    break;
            }
        }
        else
        {
            digitStack.push(stoi(postfix[i]));
        }
    }
    
    if(1==digitStack.size())
    {
        cout<<digitStack.top()<<endl;
    }
    else
    {
        cout<<"error"<<endl;
    }
}


int main()
{
    string express;
    int result = 0;
    while(cin>>express)
    {
        //result = calc(express);
        vector<string> postfix;
        //cout<<express<<"  |  ";
        convert2Postfix(express, postfix);
        calcPostfix(postfix);
    }
}

//1hour 的结果，通过10% 段错误:您的程序发生段错误，可能是数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起