//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=3709
//Description: 定义平衡树为以某个数位为支点，左右两边的数码*到支点的距离之和相等，求平衡数的个数
//Note: 注意一个数如果不是全0，至多有一个合法的支点
//Category: 数位DP

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

LL dp[20][2000][20][2];
int len;
int bit[20];

LL DP(int pos,int val,int pivot,bool f)
{
    if (val<0) return 0;

    LL &ans=dp[pos][val][pivot][f];
    if (ans!=-1) return ans;

    ans=0;
    int end=f==true?bit[pos]:9;

    if (pos==1)
    {
        for (int i=0;i<=end;++i)
        {
            int v=(pivot-pos)*i;
            if (v==val) ++ans;
        }
        return ans;
    }

    for (int i=0;i<=end;++i)
    {
        int v=val-(pivot-pos)*i;
        bool flag=f && (i==end);
        ans+=DP(pos-1,v,pivot,flag);
    }
    //printf("%d %d %d %I64d\n",pos,val,pivot,ans);
    return ans;
}

LL solve(LL x)
{
    if (x==0) return 1;
    if (x<0) return 0;

    len=0;
    while (x>0)
    {
        ++len;
        bit[len]=x%10;
        x/=10;
    }

    LL ans=0;
    clr(dp,-1);
    for (int i=1;i<=len;++i)
    {
        ans+=DP(len,0,i,1); //枚举支点位置
    }
    ans-=(len-1);					//消除0的重复计数
    //printf("%I64d\n",ans);
    return ans;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int T;
	scanf("%d",&T);

	LL l,r;
	while (T--)
    {
        scanf("%I64d%I64d",&l,&r);
        LL ans=solve(r)-solve(l-1);
        printf("%I64d\n",ans);
    }
}
