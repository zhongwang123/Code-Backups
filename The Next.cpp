//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=5491
//Description: 定义一个数的L为二进制下1的个数，给定数D，求大于D的最小的数，该数的L满足s1<=L<=s2
//Note:
//Category:贪心+思维

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

int s1,s2;
LL d;

LL check(LL x) //如果当前的数1较多，则从二进制低位开始找到第一个为1的位置i，加上(1<<i)，否则找到第一个非1的位置i，加上(1<<i)
{
    int bits=__builtin_popcount(x);

    if (bits>=s1 && bits<=s2) return x;
    else if (bits<s1)
    {
        for (int i=0;i<=62;++i)
        {
            if (!(x>>i & 1))
            {
                x|=(1<<i);
                return check(x);
            }
        }
    }
    else
    {
        for (int i=0;i<=62;++i)
        {
            if ((x>>i & 1))
            {
                x+=(1<<i);
                return check(x);
            }
        }
    }
}

void solve(int iCase)
{
    scanf("%I64d%d%d",&d,&s1,&s2);

    LL ans=check(d+1);
    printf("Case #%d: %I64d\n",iCase,ans);
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
