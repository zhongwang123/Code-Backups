//****************************************************************************************************************//
//Source: http://codeforces.com/problemset/problem/721/C
//Description: 给定若干点和边，边有边权，求在经过的边权和不超过T的情况下，从1到n经过的最多的点
//Note: 图无环
//Category:DP

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=5000;
const LL INF=1e16;

struct Edge
{
    int to;
    int w;
};

bool vis[maxn+5];
LL dp[maxn+5][maxn+5];
int n,m,T;
vector <int> ans;
vector <Edge> P[maxn+5];

void DP(int x) //dp[x][i]，到达x，经过i个点的最小花费
{
    if (vis[x]) return;

    vis[x]=true;
    for (int j=1;j<=n;++j) dp[x][j]=INF;

    for (int i=0;i<P[x].size();++i)
    {
        Edge& e=P[x][i];
        DP(e.to);
        for (int j=1;j<=n;++j)
        {
            if (dp[e.to][j]!=INF)
            {
                dp[x][j+1]=min(dp[x][j+1],dp[e.to][j]+e.w);
            }
        }
    }
}

void solve(int t,int x,int num) //回溯路径
{
    if (x==1) return;

    for (int i=0;i<P[x].size();++i)
    {
        Edge& e=P[x][i];
        if (dp[e.to][num-1]+e.w==t)
        {
            ans.push_back(e.to);
            solve(dp[e.to][num-1],e.to,num-1);
            break;
        }
    }
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d%d%d",&n,&m,&T);

	int u,v,w;
	for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        P[v].push_back((Edge){u,w});
    }

    for (int i=2;i<=n;++i)
    {
        dp[1][i]=INF;
    }
    dp[1][1]=0;
    vis[1]=true;

    DP(n);
    for (int i=n;i>=1;--i)
    {
        if (dp[n][i]<=T)
        {
            ans.push_back(n);
            solve(dp[n][i],n,i);
            break;
        }
    }

    printf("%d\n",ans.size());
    for (int i=ans.size()-1;i>=0;--i)
    {
        printf("%d ",ans[i]);
    }
}
