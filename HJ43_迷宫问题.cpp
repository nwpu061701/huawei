#include<iostream>
#include<vector>
using namespace std;

typedef  struct{
    int x;
    int y;
}position;

vector<position> current, nearest;

void dfs(int x, int y, vector<vector<int>> &maze)
{
    position pos ={x, y};//聚合类是可以用初始化列表来初始化的
    maze[x][y] = -1;//标记路已经走过，否则会形成死循环
    current.push_back(pos);
    
    //cout<<x<<" "<<y<<"| ";
    
    if(x==maze.size()-1 && y==maze[x].size()-1 )//到达终点
    {
        if(0==nearest.size() || current.size()<nearest.size())
        {
            nearest = current;
        }
        return;
    }
    
    position posTemp[4]={{x+1,y}, {x,y+1}, {x-1,y}, {x, y-1}};
    
    for(int i=0;i<4;++i)
    {
        int xTemp = posTemp[i].x, yTemp = posTemp[i].y;
        if(xTemp>=0 && xTemp<maze.size() && yTemp>=0 && yTemp<maze[x].size()&& 0==maze[xTemp][yTemp])//潜在可走的路的状态，不要忘记判断
        {
            dfs(xTemp, yTemp, maze);
            maze[xTemp][yTemp] = 0;
            current.pop_back();
        }
        
    }
}


int main()
{
    int n = 0;
    int m = 0;
    while(cin>>n>>m)
    {
        vector<vector<int>> maze(n, vector<int>(m,0));
        current.clear();
        nearest.clear();
        for(int x=0; x<n; ++x)
        {
            for(int y=0;y<m;++y)//你妹的，这里写成了y<n，导致一个段错误
            {
                cin>>maze[x][y];
            }
        }
        dfs(0,0, maze);
        
        for(auto pos:nearest)
        {
            cout<<"("<<pos.x<<","<<pos.y<<")"<<endl;
        }
    }
}