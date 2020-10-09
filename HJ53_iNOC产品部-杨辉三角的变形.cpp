//思路：1.找规律，发现，如果用数组表示的话，第1行的1并不是在最左边，而是在第n个元素位置（n代表行号）
//     2.第n行的元素的第一个和最后一个是要提前赋值为1.其他行的元素，除第一个外，按照公式
//      a[i][j]=a[i][j-1]+a[i][j]+a[i][j+1];

//20201009 17:25-17:40(找规律)

#include<iostream>
#include<vector>
using namespace std;

//方法1，找规律
int main1()
{
    int n=0;
    while(cin>>n)
    {
        if(n<3)
        {
            cout<<"-1"<<endl;
        }
        else if(1==n%2)
        {
            cout<<"2"<<endl;
        }
        else if(0==n%4)
        {
            cout<<"3"<<endl;
        }
        else if(2==n%4)
        {
            cout<<"4"<<endl;
        }
    }
}

//方法二，递推，但是存在内存溢出的问题
int main()
{
    int n=0;
    
    while(cin>>n)
    {

        if(n<3)
        {
            cout<<"-1"<<endl;
        }
        else
        {
            int col=2*n-1;
            vector<vector<int>> triangle(n, vector<int>(col,0));
            triangle[0][n-1]=1;
            triangle[n-1][0]=triangle[n-1][col-1]=1;//补偿最后一行的两个端点
            
            for(int i=1;i<n;++i)
            {
                for(int j=1;j<col-1;++j)
                {
                    triangle[i][j]=triangle[i-1][j-1]+triangle[i-1][j]+triangle[i-1][j+1];
                }
            }
            
            for(int i=0;i<col;++i)
            {
                //cout<<triangle[n-1][i]<<"|";
                if(0==triangle[n-1][i]%2)
                {
                    cout<<(i+1)<<endl;
                    break;
                }
            }
            
        }

    }
}