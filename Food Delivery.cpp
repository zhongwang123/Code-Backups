//****************************************************************************************************************//
//Source: http://acm.uestc.edu.cn/#/problem/show/426
//Description:
//Note:
//Category: 区间DP

//****************************************************************************************************************//

/*
题意：
在x轴上存在若干客人和一个饭店，要求规划一个送餐顺序，使得每个客人等待的时间乘以他对应的权值之和最小。

题解
首先明确，一个区间的客人送餐完成后，送餐者要么在左端点，要么在右端点。
所以可以考虑dp[i][j][k]，为[i,j]完成后所有客人等待的最小权值。其中i,j为左右端点，k为0,1表示位于左端点还是右端点。
其中dp[i][j][0]只能由dp[i+1][j][0]和dp[i+1][j][1]来转移。对应的dp[i][j][1]由dp[i][j-1][0]和dp[i][j-1][1]转移
注意，dp[i][j][k]为当前所有客人等待的时间加权之和。
*/

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1000;
const LL inf=1e15;

struct Node
{
    int x;
    int b;

    bool operator < (const Node& a) const
    {
        return x<a.x;
    }
};

int n,v,x;
Node A[maxn+5];
LL dp[maxn+5][maxn+5][2];
LL sum[maxn+5];
LL d[maxn+5];

inline LL f(int x,int y)
{
    return sum[x-1]+sum[n+1]-sum[y];
}

inline int dist(int x,int y)
{
    return abs(A[x].x-A[y].x);
}

void solve()
{
    A[n+1].b=0;
    A[n+1].x=x;
    sort(A+1,A+n+2);

    for (int i=1;i<=n+1;++i)
    {
        sum[i]=sum[i-1]+A[i].b;
    }

    for (int i=1;i<=n+1;++i)
        for (int j=1;j<=n+1;++j)
            for (int k=0;k<=1;++k)
                dp[i][j][k]=inf;

    int s=lower_bound(A+1,A+n+2,(Node){x,0})-A;
    dp[s][s][0]=0;
    dp[s][s][1]=0;

    for (int i=s;i>=1;--i)
    {
        for (int j=s;j<=n+1;++j)
        {
            if (i==j) continue;
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+f(i+1,j)*dist(i,i+1));
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+f(i+1,j)*dist(i,j));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+f(i,j-1)*dist(i,j));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+f(i,j-1)*dist(j-1,j));
        }
    }

    LL ans=min(dp[1][n+1][0],dp[1][n+1][1])*v;
    printf("%lld\n",ans);
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
        scanf("%d%d%d",&n,&v,&x);
        for (int i=1;i<=n;++i)
        {
            scanf("%d%d",&A[i].x,&A[i].b);
        }

        solve();
    }
}