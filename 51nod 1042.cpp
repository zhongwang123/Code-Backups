//****************************************************************************************************************//
//Source:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1042
//Description:
//Note:
//Category:数位DP

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

LL a,b;
LL ans[2][10];
int bit[20];
LL dp[20][10][2][2];
LL dp2[20][2];

LL Count(int pos,bool f)
{
    if (pos==-1) return 1;

    LL& ans=dp2[pos][f];
    if (ans!=-1) return ans;

    int End=f?bit[pos]:9;
    ans=0;
    for (int i=0;i<=End;++i)
    {
        ans+=Count(pos-1,(f && i==End));
    }
    return ans;
}

LL DP(int pos,int x,bool allzero,bool f)
{
    LL& ans=dp[pos][x][allzero][f];
    if (ans!=-1) return ans;

    ans=0;
    int End=f?bit[pos]:9;

    if (pos==0)
    {
        ans=(x<=End);
        return ans;
    }

    for (int i=0;i<=End;++i)
    {
        if (i==0)
        {
            if (!allzero)
            {
                if (i==x) ans+=Count(pos-1,f && i==End);
                ans+=DP(pos-1,x,false,(f && i==End));
            }
            else
            {
                ans+=DP(pos-1,x,true,(f && i==End));
            }
            continue;
        }
        ans+=DP(pos-1,x,false,(f && i==End));
        if (i==x) ans+=Count(pos-1,f && i==End);
    }
    return ans;
}

void solve(LL x,LL A[])
{
    if (x==0) return;
    int cnt=0;
    while (x)
    {
        bit[cnt]=x%10;
        x/=10;
        ++cnt;
    }

    for (int i=0;i<=9;++i)
    {
        clr(dp,-1);
        clr(dp2,-1);
        A[i]=DP(cnt-1,i,true,true);
    }
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%I64d%I64d",&a,&b);
	solve(a-1,ans[0]);
	solve(b,ans[1]);
	for (int i=0;i<=9;++i)
    {
        printf("%I64d\n",ans[1][i]-ans[0][i]);
    }
}
