#include<iostream>
#include<set>

using namespace std;

/***********************
难度等级：较难
20200829 16:20-17:08 暴力遍历，只能通过一部分（33.33%），超时了
dfs模板
(是否需要选择一个起点)
dfs(int step)
{
    判断边界条件是否抵达
    {
        (判断是否满足要求)
        相应操作(设置成功标记flag)
    }
    
    对于当前的每一种满足要求的可能
    {
        选择一种可能 solution
        dfs(step+1)
        判断是否成功(成功标记flag)
        {
            成功则return
            不成功则清除solution的印记
        }
    }
    
}
***********************/


int array[9][9];
bool ok = false;

bool isfilled()
{
    bool filled = true;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(0==array[i][j])
            {
                filled = false;
                break;
            }
        }
        if(false == filled)
        {
            break;
        }
    }
    return filled;
}

void sudokuOnce()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(0==array[i][j])
            {
                set<int> dict;

                for(int k=1;k<10;k++)
                {
                    dict.insert(k);
                }
                
                for(int row = 0; row<9;row++)
                {
                    dict.erase(array[row][j]);
                }
                if(1==dict.size())
                {
                    array[i][j] = *dict.begin();
                    continue;
                }
                
                for(int colomn = 0; colomn<9;colomn++)
                {
                    dict.erase(array[i][colomn]);
                }
                if(1==dict.size())
                {
                    array[i][j] = *dict.begin();
                    continue;
                }
                
                int row_strat = i/3*3, colomn_start=j/3*3;
                for(int row = row_strat;row< (row_strat+3);row++)
                {
                    for(int colomn=colomn_start;colomn<(colomn_start+3);colomn++)
                    {
                        dict.erase(array[row][colomn]);
                    }
                }
                
                if(1==dict.size())
                {
                    array[i][j] = *dict.begin();
                    continue;
                }
            }
        }
    }
}


void sudoku()
{
    while(!isfilled())
    {
        sudokuOnce();
    }
    
    for(int i=0;i<9;i++)
    {
        cout<<array[i][0];
        for(int j=1;j<9;j++)
        {
            cout<<" "<<array[i][j];
        }
        cout<<endl;
    }
}


void getCandicate(int row, int col, set<int> &can)
{
     for(int k=1;k<10;k++)
     {
         can.insert(k);
     }
     for(int j = 0; j<9;j++)
     {
          can.erase(array[row][j]);
     }
     /*
     if(1==can.size())
     {
         return;
     }
     */
     for(int j = 0; j<9;j++)
     {
          can.erase(array[j][col]);
     }
     /*
     if(1==can.size())
     {
         return;
     }*/
    
     int row_strat = row/3*3, colomn_start=col/3*3;
     for(int i = row_strat;i< (row_strat+3);i++)
     {
          for(int j=colomn_start;j<(colomn_start+3);j++)
          {
               can.erase(array[i][j]);
          }
      }
                
    return;

}

void dfs(int depth)
{
    if(depth>80)
    {
        if(isfilled())
        {
            ok=true;
        }
        return;
    }
    
    int row = depth/9;
    int colomn = depth%9;
    
    if(array[row][colomn])
    {
        dfs(depth+1);
    }
    else
    {
        set<int> candicate;
        
        getCandicate(row, colomn, candicate);

        for(auto c:candicate)
        {
            array[row][colomn] = c;
            dfs(depth+1);
            if(ok)
            {
                return;
            }
            array[row][colomn] = 0;
        }
    }
    
}


int main()
{
    int input;
    while(cin>>input)
    {
        array[0][0]=input;

        for(int i=1;i<81;i++)
        {
            cin>>array[i/9][i%9];
            
        }
        
        ok=false;
        //sudoku();
        dfs(0);
        
        for(int i=0;i<9;i++)
        {
            cout<<array[i][0];
            for(int j=1;j<9;j++)
            {
                cout<<" "<<array[i][j];
            }
            cout<<endl;
        }
    }
}