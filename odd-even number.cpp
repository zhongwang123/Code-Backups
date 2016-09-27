//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=5898
//Description: 问[L,R]之间有多少数满足，10进制下连续的偶数数码长度为奇数，连续的奇数数码为偶数
//Note:
//Category: 数位DP

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=22;

LL dp[22][2][2][2][2];
int bit[30];

LL DP(int pos,bool odd,bool l,bool allzero,bool f) //注意前导零的问题
{
    if (pos==-1)
    {
        if (allzero) return 1;
        else
        {
            if (odd && (!l)) return 1;
            if ((!odd) && l) return 1;
        }
        return 0;
    }

    LL& ans=dp[pos][odd][l][allzero][f];

    if (ans!=-1) return ans;

    ans=0;
    int End=f?bit[pos]:9;

    if (odd && l)
    {
        for (int i=1;i<=End;i+=2)
        {
            ans+=DP(pos-1,true,false,false,(f && i==End));
        }
    }
    else if (odd && (!l))
    {
        for (int i=0;i<=End;++i)
        {
            ans+=DP(pos-1,(i%2),true,false,(f && i==End));
        }
    }
    else if ((!odd) && l)
    {
        for (int i=0;i<=End;++i)
        {
            bool ll;
            if (i%2) ll=true;
            else ll=false;
            ans+=DP(pos-1,(i%2),ll,false,(f && i==End));
        }
    }
    else if ((!odd) && (!l))
    {
        if (allzero)
        {
            ans+=DP(pos-1,false,false,allzero,(f && 0==End));
            for (int i=1;i<=End;++i)
            {
                ans+=DP(pos-1,(i%2),true,false,(f && i==End));
            }
        }
        else
        {
            for (int i=0;i<=End;i+=2)
            {
                ans+=DP(pos-1,false,true,false,(f && i==End));
            }
        }
    }
    return ans;
}

LL f(LL x)
{
    if (x==0) return 1;
    int cnt=0;
    while (x)
    {
        bit[cnt]=x%10;
        x/=10;
        ++cnt;
    }

    clr(dp,-1);
    return DP(cnt-1,false,false,true,true);
}

void solve(int Case)
{
    LL L,R;
    scanf("%lld%lld",&L,&R);

    LL ans=f(R)-f(L-1);
    printf("Case #%d: %lld\n",Case,ans);
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
