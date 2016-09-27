//****************************************************************************************************************//
//Source: http://acm.split.hdu.edu.cn/showproblem.php?pid=5115
//Description:
//Note:
//Category: 区间DP

//****************************************************************************************************************//

/*
题意：
有一群狼站成一排，每个狼有基础的攻击力，同时有一个辅助攻击力，每个狼的总攻击力是基础攻击力加上相邻的狼给予的辅助攻击力之和.
求杀狼的次序使得受到的总攻击力之和最小。

题解
同 “Multiplication Puzzle”
*/

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=200;
const int inf=1e9;

int A[maxn+5];
int B[maxn+5];
int dp[maxn+5][maxn+5];
int n;

int DP(int l,int r)
{
    if (dp[l][r]!=-1) return dp[l][r];
    if (l==r-1) return dp[l][r]=0;

    dp[l][r]=inf;
    for (int k=l+1;k<=r-1;++k)
    {
        int tmp=A[k]+B[l]+B[r];
        dp[l][r]=min(dp[l][r],DP(l,k)+DP(k,r)+tmp);
    }
    return dp[l][r];
}
void solve(int C)
{
    A[0]=0;
    A[n+1]=0;
    B[0]=0;
    B[n+1]=0;

    clr(dp,-1);
    int ans=DP(0,n+1);

    printf("Case #%d: %d\n",C,ans);
}

int main(void)
{
    #ifdef ex
    freopen ("../in.txt","r",stdin);
    //freopen ("../out.txt","w",stdout);
    #endif

    int T;
    scanf("%d",&T);

    for (int Case=1;Case<=T;++Case)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;++i) scanf("%d",&A[i]);
        for (int i=1;i<=n;++i) scanf("%d",&B[i]);

        solve(Case);
    }
}