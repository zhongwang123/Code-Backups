//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=5900
//Description: 
//给定n个数对，数对由一个权值一个键值组成，如果两个相邻数对的键值不互质，那么可以取掉这两个数对，并且增加这组数对权值之和的分数
//求可以取得的分数的最大值
//Note: 取掉一组数对之后，剩下的数对将拼接在一起
//Category: 区间DP

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

struct Node
{
    int key;
    int v;
};

const int maxn=300;

int n;
Node A[maxn+5];
LL dp[maxn+5][maxn+5];
LL sum[maxn+5];

vector <int> pos[maxn+5];

int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}

LL DP(int L,int R) //区间[L,R]可以取到的最大值,思路是枚举左端点的配对情况
{
    if (L>=R) return 0;
    if (dp[L][R]!=-1) return dp[L][R];

    int p=upper_bound(pos[L].begin(),pos[L].end(),R)-pos[L].begin();

    if (L==R-1)
    {
        if (p!=0 && pos[L][p-1]==R)
        {
            dp[L][R]=A[L].v+A[R].v;
            return dp[L][R];
        }
    }

    dp[L][R]=0;
    for (int i=0;i<=p-1;++i)
    {
        int x=pos[L][i];
        if (DP(L+1,x-1)==sum[x-1]-sum[L]) dp[L][R]=max(dp[L][R],A[L].v+A[x].v+DP(L+1,x-1)+DP(x+1,R)); //当且仅当[L+1,x-1]完全取完才可以使L,x配对
    }
    dp[L][R]=max(dp[L][R],DP(L+1,R));//需要考虑L不配对的情况

    return dp[L][R];
}

void solve()
{
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i].key);
    }
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i].v);
        sum[i]=sum[i-1]+A[i].v;
    }

    for (int i=1;i<=n;++i)
    {
        pos[i].clear();
        for (int j=i+1;j<=n;++j)
        {
            if (gcd(A[i].key,A[j].key)!=1)
            {
                pos[i].push_back(j);
            }
        }
    }

    clr(dp,-1);
    printf("%lld\n",DP(1,n));
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
