
//20200823 17:33-17:50?
//9:27-9:45

//桶排序，或者字典的思想

//in "C" locale
//isalpha=islower+isupper
//isalnum=isalpha+isdigit
//ispunct=isgraph-isalnum
//isgraph = isprint-' '
//isspace= ' ' + '\t' + '\n' + '\v' + '\f' +'\r'


#include<iostream>
#include<string>
#include<cstring>
int count[256];

using namespace std;

void calc(const string& input, int &englishChar, int &blankChar, 
          int &numChar, int &otherChar)
{
    memset(count, 0, sizeof(count));
    englishChar = 0;
    blankChar = 0;
    numChar = 0;
    otherChar = 0;
    
    for(auto ch:input)
    {
        ++count[ch];
    }
    
    for(int ch = 'A';ch<='Z';ch++)
    {
        englishChar +=count[ch];
    }
    for(int ch = 'a';ch<='z';ch++)
    {
        englishChar +=count[ch];
    }
    
    blankChar = count[' '];
    
    for(int ch = '0';ch<='9';ch++)
    {
        numChar +=count[ch];
    }
    
    otherChar = input.size()- englishChar-blankChar-numChar ;
    
    //cout<<englishChar<<" "<<blankChar<<" "<<numChar<<" "<<otherChar<<endl;
    cout<<englishChar<<endl<<blankChar<<endl<<numChar<<endl<<otherChar<<endl;
}



int main()
{
    string input;
    int englishChar=0, blankChar=0, numChar=0, otherChar=0;
    while(getline(cin, input))
    {
        calc(input, englishChar, blankChar, numChar, otherChar);
    }
}