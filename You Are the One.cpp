//****************************************************************************************************************//
//Source: http://acm.split.hdu.edu.cn/showproblem.php?pid=4283
//Description:
//Note:
//Category: 区间DP

//****************************************************************************************************************//

/*
题意
给定一个序列，每个元素有一个权值A[i],要求通过一个栈改变序列的顺序，使得出栈顺序满足sigma(i*A[i])最小。

题解
出栈顺序和入栈顺序满足一个关系，即假如第一个元素是第k个出栈，那么[2,k]必然比1先出栈，[k+1,n]必然比1后出栈，[1,n]也就划分成了[2,k],[k+1,n]两个部分
*/

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=100;
const int inf=1e9;

int dp[maxn+5][maxn+5];
int A[maxn+5];
int sum[maxn+5];
int n;

int DP(int l,int r)
{
    if (l>r) return 0;
    if (dp[l][r]!=inf) return dp[l][r];

    for (int k=1;k<=r-l+1;++k)
    {
        int mid=k+l-1;
        dp[l][r]=min(dp[l][r],DP(l+1,mid)+DP(mid+1,r)+(k-1)*A[l]+k*(sum[r]-sum[mid]));
        //printf("%d %d %d\n",l,r,dp[l][r]);
    }
    return dp[l][r];
}
void solve(int Case)
{
    scanf("%d",&n);
    //printf("%d\n",n);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        sum[i]=sum[i-1]+A[i];
    }

    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            dp[i][j]=inf;
    }
    for (int i=1;i<=n;++i)
        dp[i][i]=0;


    int ans=DP(1,n);
    printf("Case #%d: %d\n",Case,ans);
}

int main(void)
{
    #ifdef ex
    freopen ("../in.txt","r",stdin);
    //freopen ("../out.txt","w",stdout);
    #endif

    int T;
    scanf("%d",&T);

    for (int i=1;i<=T;++i)
    {
        solve(i);
    }
}