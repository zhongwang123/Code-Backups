//****************************************************************************************************************//
//Source: http://acm.uestc.edu.cn/#/problem/show/1321
//Description:
//Note:
//Category: 区间DP

//****************************************************************************************************************//

/*
题意：
给定一个括号序列，问删去一个子集，得到一个非空的合法序列的方案数。

题解
题目实际上就是问给定序列中存在多少非空子集为合法序列
首先想到的是枚举分界点，dp[l][r]=sigma(dp[l][k]*dp[k+1][r],l<=k<=r)，但是必然存在重复计数的情况。
考虑区间左端点的配对括号，以左端点配对的括号作为分界点，可以保证无重复同时不遗漏
dp[l][r]表示[l,r]中合法的子集数。

如果s[l]为右括号，那么dp[l][r]=dp[l+1][r]
如果s[l]为左括号：
1.如果s[l]不参与配对，dp[l][r]+=dp[l+1][r]。
2.如果s[l]参与配对，那么dp[l][r]=sigma(dp[l+1][k-1]*dp[k+1][r],s[k]与s[l]配对）
*/

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=300;
const int h=1e9+7;

LL dp[maxn+5][maxn+5];
char s[maxn+5];
int n;

bool match(int i,int j)
{
    if (s[i]=='(' && s[j]==')') return true;
    if (s[i]=='[' && s[j]==']') return true;

    return false;
}

LL DP(int l,int r)
{
    if (dp[l][r]!=-1) return dp[l][r];
    if (l>=r) return dp[l][r]=0;
    if (s[l]==')' || s[l]==']') return dp[l][r]=DP(l+1,r);

    dp[l][r]=DP(l+1,r);
    for (int k=l+1;k<=r;++k)
    {
        if (match(l,k))
            dp[l][r]=(dp[l][r]+(DP(l+1,k-1)+1)*(DP(k+1,r)+1)%h)%h;
    }

    return dp[l][r];
}

int main(void)
{
    #ifdef ex
    freopen ("../in.txt","r",stdin);
    //freopen ("../out.txt","w",stdout);
    #endif

    scanf("%d",&n);
    scanf("%s",s+1);

    clr(dp,-1);
    LL ans=DP(1,n);
    printf("%lld\n",ans);
}