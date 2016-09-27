//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=4352
//Description: 10进制下定义数码的LIS，求LIS为k的数的数量
//Note: 注意对于数据组数较大时的优化
//Category: 数位DP

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int max_size=(1<<10);

LL dp[25][max_size+5][10];
int st[max_size+5][10];
int bit[25];
int K;
LL l,r;

void F() //预处理LIS的转移
{
    for (int i=0;i<=max_size-1;++i)
    {
        for (int j=0;j<=9;++j)
        {
            bool f=false;
            for (int k=j;k<=9;++k)
            {
                if (i>>k & 1)
                {
                    st[i][j]=i^(1<<k)|(1<<j);
                    f=true;
                    break;
                }
            }
            if (!f) st[i][j]=i|(1<<j);
            //printf("%d %d %d\n",i,j,st[i][j]);
        }
    }
    st[0][0]=0;
}

int Count(int state)
{
    int res=0;
    while (state)
    {
        if (state&1) ++res;
        state>>=1;
    }
    return res;
}

LL DP(int pos,int state,int len,bool f) //当前位置为pos,前面的数位的LIS状态为state，要求的LIS为Len的方案数
{
    LL& ans=dp[pos][state][len];
    if (ans!=-1 && !f) return ans;

    LL res=0;
    int End=f?bit[pos]:9;
    if (pos==0)
    {
        for (int i=0;i<=End;++i)
        {
            if (state==0 && i==0 && len==1) ++res;
            else if (Count(st[state][i])==len) ++res;
        }
        if (!f) ans=res;
        return res;
    }

    for (int i=0;i<=End;++i)
    {
        res+=DP(pos-1,st[state][i],len,(f && i==End));
    }
    if (!f) ans=res;

    return res;
}

LL calc(LL x)
{

    if (x==0 && K==1) return 1;
    else if (x==0 && K!=1) return 0;

    int cnt=0;
    while (x)
    {
        bit[cnt]=x%10;
        x/=10;
        ++cnt;
    }

    LL res=DP(cnt-1,0,K,true);

    return res;
}

void solve(int C)
{
    scanf("%I64d%I64d%d",&l,&r,&K);
    LL ans=calc(r)-calc(l-1);
    printf("Case #%d: %I64d\n",C,ans);
}

int main(void)
{
	#ifdef ex
	//freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int T;
	scanf("%d",&T);

	F();
	clr(dp,-1);
	for (int i=1;i<=T;++i)
    {
        solve(i);
    }
}
