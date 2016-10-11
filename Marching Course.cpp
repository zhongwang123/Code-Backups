//****************************************************************************************************************//
//Source: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2722
//Description: 给定一张图，图的道路有v，w两个权值，走过道路需要时间w，在道路上花单位时间，可以得到v/w的分数，求从1出发的最大分数
//Note:最优解下，路径呈链状，并且所有多余的时间均花在最后一条道路上
//Category:

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int INF = 1000000000;
const int maxn = 200 + 10;

struct Edge {
  int to,dist,v;
};


vector <Edge> G[maxn+5];
double dp[maxn+5][1005];
bool vis[maxn+5][1005];

double DP(int x,int time) //到达x，还剩时间time，最多可以获得的分数
{
    if (vis[x][time]) return dp[x][time];

    double& ans=dp[x][time];
    vis[x][time]=1;
    ans=0;

    for (int i=0;i<G[x].size();++i)
    {
        Edge& e=G[x][i];
        ans=max(ans,time*1.0*e.v/e.dist);
        if (time>e.dist)
        {
            ans=max(ans,DP(e.to,time-e.dist)+e.v);
        }
    }
    return ans;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);

	int s,t,d,v;
	for (int i=1;i<=m;++i)
    {
        scanf("%d%d%d%d",&s,&t,&d,&v);
        d*=2;
        v*=2;
        G[s].push_back((Edge){t,d,v});
        G[t].push_back((Edge){s,d,v});
    }

    clr(vis,0);
    double ans=DP(1,p);
    printf("%.13f\n",ans);
}
