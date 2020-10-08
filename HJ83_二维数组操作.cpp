#include<iostream>

using namespace std;
//20201006 23:19-23:45
//虽然题目比较繁琐，但是实际上只是检查输入参数是否超限。怀疑是题目本身
/*
    这道题感觉没考查到题目设置人的重点，也可能是改题目的时候刻意改偏了，
    原题可能太难了。就好像题目说的是造航母的事情，结果考察的是航母是船还是飞机的问题。
                                            ----来自Smalltiger1
*/
int main()
{
    int row=0, col=0;
    int rowExchange1 = 0, colExchange1 = 0;
    int rowExchange2 = 0, colExchange2 = 0;
    int rowInsert = 0;
    int colInsert = 0;
    int rowSearch = 0, colSearch = 0;
    while(cin>>row>>col)
    {
        cin>>rowExchange1>>colExchange1;
        cin>>rowExchange2>>colExchange2;
        cin>>rowInsert;
        cin>>colInsert;
        cin>>rowSearch>>colSearch;
        
        if(row>0 && row<=9 && col>0 && col<=9)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
        if(0<=rowExchange1 && rowExchange1<row
          && 0<=colExchange1 && colExchange1<col
          && 0<=rowExchange2 && rowExchange2<row
          && 0<=colExchange2 && colExchange2<col)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
        //if(0<=rowInsert && rowInsert<=row && (row+1)<=9)//从题目上看，对m*n表格，插入行号只允许0~m，插入列号只允许0~n，也就是插入行号可以是m
        if(0<=rowInsert && rowInsert<row && (row+1)<=9)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
        //if(0<=colInsert && colInsert<=col && (col+1)<=9)
        if(0<=colInsert && colInsert<col && (col+1)<=9)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
        if(0<=rowSearch && rowSearch<row
          && 0<=colSearch && colSearch<col)
        {
            cout<<"0"<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
    }
}