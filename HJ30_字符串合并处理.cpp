#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<cctype>

using namespace std;

map<char, char> dictionary{
    make_pair<char, char>('0', '0'),
    make_pair<char, char>('1', '8'),
    make_pair<char, char>('2', '4'),
    make_pair<char, char>('3', 'C'),
    make_pair<char, char>('4', '2'),
    make_pair<char, char>('5', 'A'),
    make_pair<char, char>('6', '6'),
    make_pair<char, char>('7', 'E'),
    make_pair<char, char>('8', '1'),
    make_pair<char, char>('9', '9'),
    make_pair<char, char>('A', '5'),
    make_pair<char, char>('B', 'D'),
    make_pair<char, char>('C', '3'),
    make_pair<char, char>('D', 'B'),
    make_pair<char, char>('E', '7'),
    make_pair<char, char>('F', 'F'),
};

void toUpper(string & str)
{
     //转换为大写字母
     for(auto &ch:str)
     {
         if(ch>='a'&&ch<='f')//怎么也没想到是这里出错了。必须严格按照题意来(题目要求是小写字母'a'-'f'转大写字母)，否则会出错。
         {
             ch = ch - 'a'+'A';
         }
     }
}

void transform(string & str)
{
    toUpper(str);
    for(auto & ch:str)
    {
        if((ch>='0'&&ch<='9') || (ch>='A'&&ch<='F'))
        {
            ch=dictionary[ch];
        }
    }
}

 void ProcessingString(const string &str1, const string &str2)
 {
     string combined = str1+str2;

     string tempstr1, tempstr2;
     for(unsigned i=0; i<combined.length();i++)
     {
         if(0==i%2)
         {
             tempstr1 += combined[i];
         }
         else
         {
             tempstr2 += combined[i];
         }
     }
     
     //分别从小到大排序
     sort(tempstr1.begin(), tempstr1.end());
     sort(tempstr2.begin(), tempstr2.end());
     
     transform(tempstr1);
     transform(tempstr2);
     
     int combinedLength = combined.length();
     combined = "";
     
     for(int i=0;i<combinedLength;i++)
     {
         if(0==i%2)
         {
             combined+=tempstr1[i/2];
         }
         else
         {
             combined+=tempstr2[i/2];
         }
     }
     cout<<combined<<endl;
 }

int main()
{
    string str1, str2;
    while(cin>>str1)
    {
        cin>>str2;
        ProcessingString(str1, str2);
    }
}