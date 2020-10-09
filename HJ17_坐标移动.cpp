//20201009 22:11
#include<sstream>
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

bool isValid(const string command)
{
    if(command.size())
    {
        if('A'==command[0] || 'D'==command[0] ||
          'W'==command[0] || 'S'==command[0])
        {
            if(3==command.size()&&isdigit(command[1])
              &&isdigit(command[2]))
            {
                return true;
            }
            else if(2==command.size()&&isdigit(command[1]))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void analysis(const string & input)
{
    stringstream ss(input);
    
    string command;
    int x=0,y=0;
    while(getline(ss,command,';'))
    {
        if(isValid(command))
        {
            int step = stoi(command.substr(1));
            switch(command[0])
            {
                case 'A':
                    x-=step;
                    break;
                case 'D':
                    x+=step;
                    break;
                case 'W':
                    y+=step;
                    break;
                case 'S':
                    y-=step;
                    break;
            }
        }
    }
    cout<<x<<","<<y<<endl;
}
int main()
{
    string input;
    while(getline(cin, input))
    {
        analysis(input);
    }
    
}