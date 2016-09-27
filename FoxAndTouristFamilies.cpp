//****************************************************************************************************************//
//Source: SRM 561
//Description:
//给定一个国家的地图，地图呈树形，在树上的一些结点上住着居民，在节日来临时，居民会随机，独立地选择一个除居住地以外其他的节点作为旅游目的地，
//然后沿着最短路径前往目的地，在这个过程中，树的某些边会被所有居民经过，求这种“关键边”的期望数
//Note:
//Category:树形DP

//****************************************************************************************************************//

#line 2 "FoxAndTouristFamilies.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=50;
vector <int> G[maxn+5];

int dp[maxn+5][maxn+5];
int dp2[maxn+5][maxn+5];
int family[maxn+5];

int dfs(int x,int p)
{
    int& ans=dp[x][p];
    if (ans!=-1) return ans;

    ans=1;
    for (int i=0;i<G[x].size();++i)
    {
        int& e=G[x][i];
        if (e==p) continue;
        ans+=dfs(e,x);
    }
    return ans;
}

int dfs2(int x,int p)
{
    int& ans=dp2[x][p];
    if (ans!=-1) return ans;

    ans=family[x];
    for (int i=0;i<G[x].size();++i)
    {
        int& e=G[x][i];
        if (e==p) continue;
        ans+=dfs2(e,x);
    }
    return ans;
}

class FoxAndTouristFamilies
{
    public:
    double expectedLength(vector <int> A, vector <int> B, vector <int> f)
    {
        memset(dp,-1,sizeof(dp));
        memset(dp2,-1,sizeof(dp2));
        memset(family,0,sizeof(family));

        for (int i=0;i<f.size();++i)
        {
            family[f[i]]++;
        }
        for (int i=0;i<A.size();++i)
        {
            int u=A[i];
            int v=B[i];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        double ans=0;
        int n=A.size()+1;
        for (int i=0;i<A.size();++i)
        {
            int u=A[i];
            int v=B[i];

            int u_tree=dfs(u,v);
            int v_tree=dfs(v,u);
            int u_f=dfs2(u,v);
            int v_f=dfs2(v,u);

            double p1=(n-u_tree)*1.0/(n-1);
            double p2=(n-v_tree)*1.0/(n-1);
            ans+=pow(p1,u_f)*pow(p2,v_f);
        }

        return ans;
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
