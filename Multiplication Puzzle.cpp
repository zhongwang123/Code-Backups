//****************************************************************************************************************//
//Source: http://poj.org/problem?id=1651
//Description:
//Note:
//Category:区间DP

//****************************************************************************************************************//

/*
题意：

给定一个序列，可以依次从序列中取走除了左右两端点之外的元素，每次取走一个元素，获得该元素乘以它左右两边元素乘积的点数，求可能的最小点数。


题解：

区间DP，首先会想到枚举区间中第一个被取走的元素k,转移dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+A[k]*A[k-1]*A[k+1])

但是这个转移是失败的，因为接下来考虑dp[l][k]时，A[k-1]这个元素被取出时它的右边的元素无法确定。

应该枚举区间中最后被取走的那个元素，转移dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+A[k]*A[l]*A[r])

注意：

k已经被取走，所以dp[l][k]不需要考虑k被取走的情况，保证了DP状态定义的一致性。
*/


//#include<bits/stdc++.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=100;
const int inf=2e8;

int dp[maxn+5][maxn+5];
int A[maxn+5];
int n;

int DP(int l,int r)
{
    if (dp[l][r]!=-1) return dp[l][r];
    if (l==r-1) return dp[l][r]=0;

    dp[l][r]=inf;
    for (int i=l+1;i<=r-1;++i)
    {
        dp[l][r]=min(dp[l][r],DP(l,i)+DP(i,r)+A[i]*A[l]*A[r]);
    }

    return dp[l][r];
}

void solve()
{
    clr(dp,-1);
    printf("%d\n",DP(1,n));
}

int main(void)
{
    #ifdef ex
    freopen ("../in.txt","r",stdin);
    //freopen ("../out.txt","w",stdout);
    #endif

    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;++i)
        {
            scanf("%d",&A[i]);
        }
        solve();
    }
}