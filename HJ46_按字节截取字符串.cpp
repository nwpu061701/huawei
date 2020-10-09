#include<iostream>
#include<string>

using namespace std;


/*
本题考查编码格式:
UTF-8编码规则：如果只有一个字节则其最高二进制位为0；
如果是多字节，其第一个字节从最高位开始，连续的二进制位值为1的个数决定了其编码的字节数，
其余各字节均以10开头。
这就意味着，ASCIl字节（0x00-0x7F）不可能作为任何其他字符的一部分。
UTF-8是变长编码格式

关于一个汉字的字节长度，在UTF-8中，是三个字节

UTF-16比起UTF-8，好处在于大部分字符都以固定长度的字节（2字节）储存，
但UTF-16却无法兼容于ASCII编码。

汉字在ANSI(例如GB2312、GBK)中长度是2。

另外，题目中透露的意思“输入'我ABC汉DEF'6，应该输出为'我ABC'而不是'我ABC+汉的半个'”，
可以推测，汉字长度是2个字节

string本身就会判断最后一个字节是否是多余的半个汉字，是的恶化不输出该字节

*/
//方法1
int main1()
{
    string str;
    int num;
    while(cin>>str)
    {
        cin>>num;
        
        if(num<1)
        {
            cout<<endl;
        }
        else
        {
            if(str[num-1]>127)
            {
                int bytes = 0;
                int index = num-1;
                while(index>=0 && str[index]>127)
                {
                    ++bytes;
                    --index;
                }
                if(0==bytes%2)
                {
                    cout<<str.substr(0, num)<<endl;
                }
                else
                {
                    cout<<str.substr(0, num-1)<<endl;
                }
                
            }
            else
            {
                cout<<str.substr(0, num)<<endl;
            }
        }
    }
}

int main()
{
    string str;
    int num;
    while(cin>>str)
    {
        cin>>num;
        
        if(num<1)
        {
            cout<<endl;
        }
        else
        {
            cout<<str.substr(0, num)<<endl;
        }
    }
}