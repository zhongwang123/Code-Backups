//****************************************************************************************************************//
//Source: SRM 676
//Description: 
//Alice和Bob下棋，棋盘上有一个棋子，存在空格子，障碍，出口等，棋子有一个初始值k,Alice和Bob轮流移动棋子，每一回合棋子上的数字减一，
//数字归零或者棋子走到出口时，棋子离开棋牌。如果某人的回合里，无法移动棋子或者棋子已经离开棋盘，判负。
//Note:
//Category: DP,SG,BFS

//****************************************************************************************************************//

#line 2 "BoardEscapeDiv2.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int n,m;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char mp[60][60];
bool dp[60][60][105];
int vis[60][60][105];

bool DP(int x,int y,int k)
{
    if (vis[x][y][k]) return dp[x][y][k];

    vis[x][y][k]=1;
    if (k==0) return dp[x][y][k]=false;
    if (mp[x][y]=='E') return dp[x][y][k]=false;

    dp[x][y][k]=false; //初始化为必败状态
    for (int i=0;i<=3;++i)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if (tx<0 || tx>=n || ty<0 || ty>=m) continue;
        if (mp[tx][ty]=='#') continue;
        if (!DP(tx,ty,k-1))
            return dp[x][y][k]=true; //后继状态存在必败态，则当前状态为必胜态
    }

    return dp[x][y][k];
}

class BoardEscapeDiv2
{
    public:
    string findWinner(vector <string> s, int k)
    {
        int sx,sy;
        n=s.size();
        m=s[0].length();
        for (int i=0;i<s.size();++i)
        {
            for (int j=0;j<s[i].length();++j)
            {
                mp[i][j]=s[i][j];
                if (mp[i][j]=='T')
                {
                    sx=i;
                    sy=j;
                }
            }
        }

        memset(vis,0,sizeof(vis));
        bool f=DP(sx,sy,k);

        if (f) return "Alice";
        else return "Bob";
    }
};

#ifdef ex
int main()
{
    #ifdef ex1
    freopen ("in.txt","r",stdin);
    #endif

}
#endif
