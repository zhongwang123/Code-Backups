//****************************************************************************************************************//
//Source: http://codeforces.com/problemset/problem/429/A
//Description: 
//给定一棵树，节点有初始权值0或1，还有目标权值，可以选择某个节点做flip操作，使该节点权值取反，子节点不变，子节点的子节点权值取反，以此类推
//问最小flip次数使得所有节点的权值变成目标权值
//Note:
//Category:Others

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1e5;

vector <int> G[maxn+5];
int A[maxn+5];
int P[maxn+5];
bool vis[maxn+5];
int ans;

void dfs(int x,int p,bool f,bool f2) //这道题不难，体现出的思想是在DFS遍历树使，可以通过一个变量记录父节点的信息，进而用两个变量记录祖父节点的信息
{
    bool fx=f2;

    A[x]^=f2;
    if (A[x]!=P[x])
    {
        fx^=1;
        ++ans;
        vis[x]=true;
    }

    for (int i=0;i<G[x].size();++i)
    {
        int& e=G[x][i];
        if (e==p) continue;
        dfs(e,x,fx,f);
    }
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int n;
	scanf("%d",&n);

    int u,v;
    for (int i=1;i<=n-1;++i)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
    }
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&P[i]);
    }

    dfs(1,0,0,0);

    printf("%d\n",ans);
    for (int i=1;i<=n;++i)
    {
        if (vis[i]) printf("%d\n",i);
    }
}
