//20201007 16:41-17:04
#include<iostream>
#include<vector>
/*
std::accumulate(begin(), end(), init_value, binary_op)//binary_op可选，
binary_op表示以init_value为左操作数，迭代器范围元素为右操作数，进行相关运算；默认情况下，是累加
*/
using namespace std;
int num=0;
int flag = false;
int group1 = 0, group2=0;
vector<int> array;

void dfs(int step)
{
    if(step>=array.size())
    {
        if(group1==group2)
        {
            flag = 1;
        }
        return;
    }
    
    if(1 == flag)
    {
        return;
    }
    
    group1+=array[step];
    dfs(step+1);
    group1-=array[step];
    
    if(1 == flag)
    {
        return;
    }
    
    group2+=array[step];
    dfs(step+1);
    group2-=array[step];
}

int main()
{
    int temp;
    while(cin>>num)
    {
        array.clear();
        group1 = 0;
        group2 = 0;
        flag = false;
        
        for(int i=0;i<num;++i)
        {
            cin>>temp;
            array.push_back(temp);
        }
        
        for(auto itr =array.begin();itr!=array.end(); )
        {
            if(0==(*itr)%5)
            {
                group1+=(*itr);
                itr=array.erase(itr);
            }
            else if(0==(*itr)%3)
            {
                group2+=(*itr);
                itr=array.erase(itr);
            }
            else
            {
                ++itr;
            }
        }
        
        dfs(0);
        if(true ==flag)
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
    }
    
}


