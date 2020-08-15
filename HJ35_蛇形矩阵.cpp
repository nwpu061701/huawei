#include<iostream>
#include<cstring>
//做这个题有两种思路，第一种思路是从值的角度思考问题，找单个一行值之间的递增规律、每行第一个值的递增规律
//第二种思路，从位置的角度思考问题，单纯看位置是怎么移动的。本解法采用第二种思路。

//另外，可以一开始就计算出一个比较大的蛇形矩阵，然后查表输出。这种事节省了一定的计算量。
using namespace std;

int array[100][100];

int main()
{
    int num;
    while(cin>>num)
    {
        memset(array, 0, sizeof(int)*100*100);
        
        int digit=0;
        //在整个蛇形矩阵中，赋值是按照，(0,0)->(1,0)->(0,1)->(2,0)->(1,1)->(0,2)->...的顺序递增
        //把(0,0)看做一组，(1,0)、(0,1)看做一组，(2,0)->(1,1)->(0,2)看做一组,...
        //每一组的x和y坐标的和是一个常数
        for(int i=0;i<num;i++)
        {
            for(int colomn=0; colomn<=i;colomn++)
            {
                int row=i-colomn;
                array[row][colomn]=++digit;
            }
        }
        //printf("num=%d|", num);
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num-i;j++)
            {
                cout<<array[i][j]<<" ";
            }
            cout<<endl;
        }

            
    }
}