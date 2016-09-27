//****************************************************************************************************************//
//Source: http://codeforces.com/contest/149/problem/D
//Description:
//Note:
//Category: 区间DP

//****************************************************************************************************************//

/*
题意：
给一个匹配的括号序列染色，要求
1.括号要么被染色，要么没有被染色，只能染成红蓝两种颜色；
2.对应的两个匹配的括号有且只有一个染色；
3.相邻的括号颜色不同
求可能的染色方案数

 

题解
dp[l,r,lc,rc]指区间[l,r]且两个端点的颜色分别为lc,rc时的方案数。
如果l,r互相匹配，那么[l,r]由[l+1,r-1]转移过来
如果不匹配，则[l,r]由[l,match[l]]*[match[l]+1,r]转移过来
*/

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=700;
const int h=1e9+7;

LL dp[maxn+5][maxn+5][3][3];
int match[maxn+5];
char s[maxn+5];
// 0 black
// 1 blue
// 2 red

int len;

void f()
{
    stack <int> st;
    for (int i=0;i<=len-1;++i)
    {
        if (s[i]=='(')
            st.push(i);
        else
        {
            int pos=st.top();
            st.pop();
            match[pos]=i;
        }
    }
}

LL DP(int l,int r,int lc,int rc)
{
    LL& res=dp[l][r][lc][rc];

    if (res!=-1) return res;
    if (match[l]==r && ((lc && rc) || (!lc && !rc))) return res=0;
    if (l==r-1) return res=1;

    res=0;
    if (match[l]==r)
    {
        if ((lc && rc) || (!lc && !rc)) return res=0;
        for (int i=0;i<=2;++i)
        {
            for (int j=0;j<=2;++j)
            {
                if ((i==lc && i!=0) || (j==rc && j!=0)) continue;
                res=(res+DP(l+1,r-1,i,j))%h;
            }
        }
        return res;
    }

    for (int i=0;i<=2;++i)
    {
        for (int j=0;j<=2;++j)
        {
            if ((i==j) && i!=0) continue;
            res=(res+DP(l,match[l],lc,i)*DP(match[l]+1,r,j,rc)%h)%h;
        }
    }
    return res;
}

int main(void)
{
    #ifdef ex
    freopen ("../in.txt","r",stdin);
    //freopen ("../out.txt","w",stdout);
    #endif

    scanf("%s",s);
    len=strlen(s);

    f();

    LL ans=0;
    clr(dp,-1);
    for (int i=0;i<=2;++i)
    {
        for (int j=0;j<=2;++j)
        {
            ans=(ans+=DP(0,len-1,i,j))%h;
        }
    }
    printf("%I64d\n",ans);
}