//****************************************************************************************************************//
//Source: http://acm.split.hdu.edu.cn/showproblem.php?pid=5877
//Description: 给定一棵树，树上节点有权值，问多少对存在祖先后代关系的节点，其权值之积小于K
//Note:
//Category:树状数组

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1e5;
const LL inf=1e10;

int n;
LL k;
int A[maxn+5];
int deg[maxn+5];
int pos[maxn+5];
int bit[maxn+5];

LL ans;
int cnt;
vector <int> G[maxn+5];

void add(int p,int v)
{
    int i=p;
    while (i<=n)
    {
        bit[i]+=v;
        i+=i&(-i);
    }
}

LL sum(int p)
{
    int i=p;
    LL res=0;
    while (i>0)
    {
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

void dfs(int x,int f) //核心思想：在dfs过程中维护祖先的值，返回时消去影响
{
    LL v=A[x]==0?inf:k/A[x];
    int p1=upper_bound(pos+1,pos+1+cnt,v)-pos-1;
    ans+=sum(p1);

    int p2=lower_bound(pos+1,pos+1+cnt,A[x])-pos;
    add(p2,1);

    for (int i=0;i<G[x].size();++i)
    {
        int& e=G[x][i];
        if (e==f) continue;
        dfs(e,x);
    }
    add(p2,-1);
}

void solve()
{
    scanf("%d%I64d",&n,&k);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        pos[i]=A[i];
    }

    sort(pos+1,pos+1+n);
    cnt=0;
    for (int i=1;i<=n;++i)
    {
        if (i==1 || pos[i]!=pos[i-1]) pos[++cnt]=pos[i];
    }

    for (int i=1;i<=n;++i) G[i].clear();
    clr(deg,0);
    clr(bit,0);

    int u,v;
    for (int i=1;i<=n-1;++i)
    {
        scanf("%d%d",&u,&v);
        G[u].push_back(v);
        ++deg[v];
    }

    ans=0;
    for (int i=1;i<=n;++i)
    {
        if (!deg[i])
        {
            dfs(i,-1);
            printf("%I64d\n",ans);
            return;
        }
    }
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int T;
	scanf("%d",&T);

	while (T--)
    {
        solve();
    }
}
