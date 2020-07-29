#include<iostream>

using namespace std;


//从这道题可以看出，一个定义过的变量，可以定义数组的维度
int main()
{
    int x = 0, y = 0, z = 0;
    while(cin>>x)
    {
        cin>>y>>z;
        int array1[x][y];
        int array2[y][z];
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<y;j++)
            {
                cin>>array1[i][j];
                //cout<<array1[i][j]<<" ";
            }
            //cout<<"#";
        }
        
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<z;j++)
            {
                cin>>array2[i][j];
                //cout<<array2[i][j]<<" ";
            }
            //cout<<"#";
        }
        
        
        for(int i=0;i<x;i++)
        {
            for(int j=0;j<z;j++)
            {
                int mult = 0;
                for(int k=0;k<y;k++)
                {
                    //cout<<"k="<<k<<"z="<<z<<" "<<array2[k][z]<<"+";
                    mult += array1[i][k]*array2[k][j];
                }
                
                if(z-1==j)
                {
                    cout<<mult<<endl;
                }
                else
                {
                    cout<<mult<<" ";
                }
            }
        }
    }
}