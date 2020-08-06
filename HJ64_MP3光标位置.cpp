//20200805 22:34-22:37
#include<string>
#include<iostream>

using namespace std;

void up(int & currentFirst, int & selected, int songsNum)
{
    if(songsNum<=4)
    {
        currentFirst  = 1;
        selected = (selected==currentFirst)?songsNum:(selected-1);
    }
    else
    {
        if(1==currentFirst)
        {
            if(1==selected)//特殊翻页
            {
                currentFirst = songsNum-4+1;
                selected = songsNum;
            }
            else
            {
                currentFirst  = 1;
                selected--;
            }
        }
        else
        {
            if(currentFirst == selected)//一般翻页
            {
                currentFirst--;
                selected--;
            }
            else
            {
                currentFirst = currentFirst;//保持不变
                selected--;
            }
        }
    }
}

void down(int & currentFirst, int & selected ,int songsNum)
{
    if(songsNum<=4)
    {
        currentFirst=1;
        selected = (selected == currentFirst+songsNum-1)?1:(selected+1);
    }
    else
    {
        if(currentFirst == songsNum-4+1)
        {
            if(selected== songsNum)//特殊翻页
            {
                currentFirst = 1;
                selected = 1;
            }
            else
            {
                currentFirst = currentFirst;
                selected++;
            }
        }
        else
        {
            if(selected == currentFirst+4-1)//一般翻页
            {
                currentFirst++;
                selected++;
            }
            else
            {
                selected++;
                currentFirst = currentFirst;//保持不变
            }
        }
    }
}


void calcListCurrentSong(int num, const string &input)
{
    int currentFirst = 1;
    int selected = 1;
    
    for(int i=0; i<input.length(); i++)
    {
        if('U'==input[i])
        {
            up(currentFirst, selected, num);
        }
        else
        {
            down(currentFirst, selected, num);
        }
    }
    
    int currentEnd = (currentFirst+3>=num)?num:(currentFirst+3);
    for(int current = currentFirst;current<=currentEnd;current++)
    {
        cout<<current<<" ";
    }
    cout<<endl;
    cout<<selected<<endl;
}


int main()
{
    int num = 0;
    string input;
    while(cin>>num)
    {
        cin>>input;
        calcListCurrentSong(num, input);
    }
}