//****************************************************************************************************************//
//Source: SRM 677
//Description: 给定一张图，图的部分节点之间连有边，边的长度为1，且有标签c，求节点0到节点1的最短路径，且路径的标签组成一个回文串
//Note: 本题和14年西安的“The Problem to Make You Happy”有异曲同工之感
//Category: BFS+dp

//****************************************************************************************************************//

#line 2 "PalindromePath.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF=1e8;

struct Node
{
    int x,y,d;
};

int edge[25][25];
int dp[25][25];

queue <Node> Q;
vector <int> G[25];

class PalindromePath
{
    public:
    int shortestLength(int n, vector <int> a, vector <int> b, string c)
    {
        for (int i=0;i<=n-1;++i)
        {
            for (int j=0;j<=n-1;++j)
            {
                edge[i][j]=INF;
                edge[j][i]=INF;
                dp[i][j]=INF;
                dp[j][i]=INF;
            }
            dp[i][i]=0;
            Q.push((Node){i,i,0});
        }

        for (int i=0;i<a.size();++i)
        {
            int& u=a[i];
            int& v=b[i];

            G[u].push_back(v);
            G[v].push_back(u);

            edge[u][v]=c[i]-'a';
            edge[v][u]=c[i]-'a';
            dp[u][v]=1;
            dp[v][u]=1;

            Q.push((Node){u,v,1});
            //Q.push((Node){v,u,1});
        }

        while (!Q.empty() && dp[0][1]==INF) //先将所有回文串加入队列，不断拓展直到无法拓展或者0-1之间已经连有边
        {
            Node now=Q.front();
            Q.pop();

            int u=now.x;
            int v=now.y;
            for (int i=0;i<G[u].size();++i)
            {
                for (int j=0;j<G[v].size();++j)
                {
                    int u1=G[u][i];
                    int v1=G[v][j];
                    if (edge[u][u1]!=INF && edge[u][u1]==edge[v][v1])
                    {
                        if (dp[u1][v1]==INF)
                        {
                            dp[u1][v1]=dp[u][v]+2;
                            dp[v1][u1]=dp[u1][v1];
                            Q.push((Node){u1,v1,dp[u1][v1]});
                        }
                    }
                }
            }
        }

        if (dp[0][1]==INF) return -1;
        else return dp[0][1];
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
