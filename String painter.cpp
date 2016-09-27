//****************************************************************************************************************//
//Source: http://acm.split.hdu.edu.cn/showproblem.php?pid=2476
//Description:
//Note:
//Category: 区间DP

//****************************************************************************************************************//

/*
题意：
给定两个字符串s1,s2，每次可以对s1的一个区间进行操作，使其一段区间内的所有字符都变成一个字符，问最少操作数使得s1变成s2。

题解
（完全照搬网上题解系列）
首先考虑由空串变成s2，dp[i][j]表示[i,j]和s2相同需要的最小步数。相比朴素地操作数j-i+1，如果s2在区间[i,j]中存在相同的字符，可以一次全部修改，减少操作数。
枚举区间的分界点，if (s2[i]==s2[k]) dp[i][j]=dp[i+1][k]+dp[k+1][j],其中i位置的字符变化可以在k位置变化时同时完成。
*/

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=100;

char s1[maxn+5],s2[maxn+5];
int dp[maxn+5][maxn+5];
int ans[maxn+5];
int len;

void solve()
{
    clr(dp,0);
    clr(ans,0);

    len=strlen(s2+1);

    for (int i=len;i>=0;--i)
    {
        for (int j=i;j<=len;++j)
        {
            dp[i][j]=j-i+1;
            for (int k=i;k<=j;++k)
            {
                if (s2[i]==s2[k] && i!=k)
                    dp[i][j]=min(dp[i][j],dp[i+1][k]+dp[k+1][j]);
                else
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
    }

    for (int i=1;i<=len;++i)
    {
        ans[i]=dp[1][i];
        if (s1[i]==s2[i]) ans[i]=ans[i-1];
        for (int j=1;j<=i-1;++j)
        {
            ans[i]=min(ans[i],ans[j]+dp[j+1][i]);
        }
    }

    printf("%d\n",ans[len]);
}

int main(void)
{
    #ifdef ex
    freopen ("../in.txt","r",stdin);
    //freopen ("../out.txt","w",stdout);
    #endif

    while (scanf("%s%s",s1+1,s2+1)==2)
    {
        solve();
    }
}