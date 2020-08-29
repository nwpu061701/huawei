#include<iostream>
#include<map>
#include<string>
#include<vector>

/*********************
*1、代码过长，用递归方法代码会少很多。参见后面注释部分
*2、题目意思是，如果百位上为0，就不用加and了。。。。按照英语习惯，2016，应翻译为two thousand and sixteen
*   英语19，为nineteen;90为ninety。注意不要少了e。
*难度等级：一般，主要难点在于对题目的理解，以及输出格式控制（是否多输出了一个结尾的空格。自验方法：将空格改为“|”输出）
           能想出那种递归的解法，却是需要一定积累的。
           20200829  还未手动递归解题
**********************/


using namespace std;

map<int,string> iTos = {
    make_pair<int, string>(0, "zero"),
    make_pair<int, string>(1, "one"),
    make_pair<int, string>(2, "two"),
    make_pair<int, string>(3, "three"),
    make_pair<int, string>(4, "four"),
    make_pair<int, string>(5, "five"),
    make_pair<int, string>(6, "six"),
    make_pair<int, string>(7, "seven"),
    make_pair<int, string>(8, "eight"),
    make_pair<int, string>(9, "nine"),
    make_pair<int, string>(10, "ten"),
    make_pair<int, string>(11, "eleven"),
    make_pair<int, string>(12, "twelve"),
    make_pair<int, string>(13, "thirteen"),
    make_pair<int, string>(14, "forteen"),
    make_pair<int, string>(15, "fifteen"),
    make_pair<int, string>(16, "sixteen"),
    make_pair<int, string>(17, "seventeen"),
    make_pair<int, string>(18, "eighteen"),
    make_pair<int, string>(19, "ninteen"),
    make_pair<int, string>(20, "twenty"),
    make_pair<int, string>(30, "thirty"),
    make_pair<int, string>(40, "forty"),
    make_pair<int, string>(50, "fifty"),
    make_pair<int, string>(60, "sixty"),
    make_pair<int, string>(70, "seventy"),
    make_pair<int, string>(80, "eighty"),
    make_pair<int, string>(90, "ninety"),//单词不要写错
    make_pair<int, string>(100,"hundred"),
};

string scale[4] ={"", "thousand", "million", "billion"};

//num<1000
string intTostring(int num)
{
    string result;
    int temp = num;
    if(temp>=100)
    {
        result +=iTos[temp/100];
        result +=" ";
        result +=iTos[100];
        temp %=100;
    }
    
    if(temp>=20)
    {
        if(num>=100)//如果之前有百位
        {
            result += " and ";
        }
        result +=iTos[temp/10*10];//十位

        if(temp%10)//个位
        {
            result += " ";
            result +=iTos[temp%10];//个位
        }
        
    }
    else if(temp>0)
    {
        if(num>=100)//如果之前有百位
        {
            result += " and ";
        }
        result +=iTos[temp];//十位和个位
    }
    
    return result;

}


void parse(long num)
{
    if(num<=0 || num>=1000000000)
    {
        cout<<"error"<<endl;
    }
    
    long temp = num;
    vector<int> vint;
    vector<string> vstr;
    string result;
    while(temp)
    {
        vint.push_back(temp%1000);
        temp/=1000;
    }
    
    for(int i=0;i<vint.size();i++)
    {
        vstr.push_back(intTostring(vint[i]));
    }
    
    //处理类似2002，2 thousand and 2
    int id_add_and = -1;
    for(int i=0;i<vint.size()-1;i++)
    {
        if(vint[i]>0 && vint[i]<100)
        {
            id_add_and = i;
            break;
        }
    }
    
    int start = vint.size()-1;
    result += vstr[start] + " " + scale[start];
    
    for(int i=start-1;i>=0;i--)
    {
        if(vstr[i].size())
        {
            
            //if(i==id_add_and)
            //{
            //    result += "and "+vstr[i] + " " + scale[i] +" ";
            //}
            //else
            if(0!=i)
            {
                result +=" " + vstr[i] + " " + scale[i];
            }
            else
            {
                result +=" " + vstr[i];
            }
        }
    }
    
        
    cout<<result<<endl;
}



int main()
{
    long input;
    while(cin>>input)
    {
        parse(input);
    }
}



/***
#include <iostream>
#include <string>
using namespace std;

const string ones[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
const string tens[] = { "ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nighteen" };
const string twenties[] = { "zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
const int ihundreds[] = { (int)1e2, (int)1e3, (int)1e6, (int)1e9, (int)1e12 };
const string hundreds[] = { "hundred", "thousand", "million", "billion" };

string itoe(long long n)
{
    if (0<=n && n<=9) return ones[n];
    if (10<=n && n<20) return tens[n%10];
    if (20<=n && n<1e2) return twenties[n/10] + (n%10 ? " " + ones[n%10] : "");
    for (int i=0; i < 5-1; i++) if (n < ihundreds[i+1]) {
        return itoe(n/ihundreds[i]) + " " + hundreds[i] + (n%ihundreds[i] ? (i ? " ": " and ") + itoe(n%ihundreds[i]) : "");
    }
    return "";  // ... ...
}

int main()
{
    for (long long N; cin>>N; ) cout<<itoe(N)<<endl;
    return 0;
}
***/