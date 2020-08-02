#include<iostream>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;


/************************
    第二次AC的方式：DFS
    20200801 10:09
    next_permutation是从sort结果后的全排列
    next_permutation(first, last , comp)，返回为true，表示成功获得下一个全排列，返回false，表示全排列已经全部遍历完毕
*************************/

bool visited[4] = {false, false, false, false};
float digits[4];

bool dfs(int index, float result)
{
    if(index > 4)
    {
        //printf(">4 ");
        return false;
    }
    else if(4==index && fabs(result-24)<0.000001)
    {
        //printf("equal24\t");
        return true;
    }
    else if(index <4)
    {
        ++index;
        for(int i=0; i<4;i++)
        {
            if(false==visited[i])
            {
                visited[i] = true;
                if(dfs(index, result+digits[i]))
                {
                    return true;
                }
                else if(dfs(index, result-digits[i]))
                {
                    return true;
                }
                else if(dfs(index, result*digits[i]))
                {
                    return true;
                }
                else if(dfs(index, result/digits[i]))//这个地方写错了 “result/digits[i]”写成了“result*digits[i]”，浪费了很多时间来排查
                {
                    return true;
                }
                visited[i] = false;
            }
        }
        
        return false;//如果当前节点遍历完所有的可能，要退出，返回false。  在这个地方的排查也浪费了时间
    }
    else
    {
        //printf("false\t");
        return false;
    }
    
}

int main()
{
    while(cin>>digits[0])
    {
        cin>>digits[1]>>digits[2]>>digits[3];
        bool equal24 = false;
        
        memset(visited, 0, 4);//没有这句，会导致前一个通过的例子，影响到后一个例子。这个地方的排查也浪费了时间
        for(int i=0;i<4;i++)
        {
            visited[i]=true;
            equal24 = dfs(1, digits[i]);
            if(equal24)
            {
                //printf("\t1 digits[%d]=%f", i, digits[i]);
                break;
            }
            visited[i]=false;
            
        }
        
        if(equal24)
        {
            cout<<"true"<<endl;
        }
        else
        {
            cout<<"false"<<endl;
        }
    }
}




/************************
    初次AC的方式
    20200730 21:20 40分钟90%
*************************/

/*
bool equal24(float c, float d)
{
    if(fabs(c+d-24)<0.000001)
    {
        return true;
    }
    else if(fabs(c-d-24)<0.000001)
    {
        return true;
    }
    else if(fabs(c*d-24)<0.000001)
    {
        
        return true;
    }
    else if(fabs(c/d-24)<0.000001)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool equal24(float b, float c, float d)
{
    if(equal24(b+c, d))
    {
        return true;
    }
    else if(equal24(b-c, d))
    {
        return true;
    }
    else if(equal24(b*c, d))
    {
        return true;
    }
    else if(equal24(b/c, d))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool equal24(float a, float b, float c, float d)
{
    if(equal24(a+b, c, d))
    {
        return true;
    }
    else if(equal24(a-b, c, d))
    {
        return true;
    }
    else if(equal24(a*b, c, d))
    {
        return true;
    }
    else if(equal24(a/b, c, d))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void calc24(const vector<int> & vint)
{
    for(int i=0;i<4;i++)
    {
        vector<int> temp;
        temp.push_back(vint[i]);
        for(int ii=0;ii<4;ii++)
        {
            if(i!=ii)
            {
                temp.push_back(vint[ii]);
            }
        }
        for(int j=0;j<4;j++)
        {
            for(int k=j+1;k<4;k++)
            {
                vector<int> tempTemp = temp;//因为这里没有再次用已经定过第一个元素顺序的temp的copy来再次排序，导致只能通过90%

                int t = tempTemp[j];
                tempTemp[j]=tempTemp[k];
                tempTemp[k]=t;
                
                
                if(equal24(tempTemp[0], tempTemp[1], tempTemp[2], tempTemp[3]))
                {
                    cout<<"true"<<endl;
                    return;
                }
                
            }
        }
    }

    cout<<"false"<<endl;
    return;
}



int main()
{
    int input=0;
    vector<int> vint;
    while(cin>>input)
    {
        vint.push_back(input);
        for(int i=0;i<3;i++)
        {
            cin>>input;
            vint.push_back(input);
        }

        calc24(vint);
        vint.clear();
    }
}
*/

