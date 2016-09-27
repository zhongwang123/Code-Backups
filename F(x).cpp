//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=4734
//Description:
//Note: 
//Category: 数位DP
//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=10*(1<<9);
int dp[10][maxn];
int A,B;
int bit[10];

//注意，对于dp的初始化只进行一次，dp只记录f==false时的情况，对于f==true，直接递归计算。
//对于数据组数较大的情况，可以极大提高效率

int DP(int pos,int val,bool f) 
{
    int& ans=dp[pos][val];

    if (ans!=-1 && !f) return ans;

    int res=0;
    int End=f?bit[pos]:9;

    if (pos==0)
    {
        for (int i=0;i<=End;++i)
        {
            if (i<=val) ++res;
        }
        if (!f) ans=res;
        return res;
    }

    for (int i=0;i<=End;++i)
    {
        int tmp=i*(1<<pos);
        if (tmp>val) break;

        res+=DP(pos-1,val-tmp,(f && i==End));
    }
    if (!f) ans=res;
    return res;
}

int f(int X)
{
    if (X==0) return 0;
    int cnt=0;
    int res=0;
    while (X)
    {
        res+=(X%10)*(1<<cnt);
        ++cnt;
        X/=10;
    }
    return res;
}

int calc()
{
    if (f(A)>=maxn) return B+1;
    if (B==0) return 1;

    int cnt=0;
    while (B)
    {
        bit[cnt]=B%10;
        B/=10;
        ++cnt;
    }

    return DP(cnt-1,f(A),true);
}

void solve(int C)
{
    scanf("%d%d",&A,&B);

    int ans=calc();
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

	clr(dp,-1);
	for (int i=1;i<=T;++i)
    {
        solve(i);
    }
}
