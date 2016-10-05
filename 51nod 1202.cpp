//****************************************************************************************************************//
//Source: http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1202
//Description: 给定一个序列，求不同子序列的个数
//Note:
//Category: DP

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1e5;
const int h=1e9+7;

LL dp[maxn+5];
LL sum[maxn+5];
int pos[maxn+5];
int A[maxn+5];

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int n;
	scanf("%d",&n);

	for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
    }

    clr(pos,-1);
    for (int i=1;i<=n;++i) //dp[i]:以位置i的元素为结尾的子序列的个数
    {
        if (pos[A[i]]==-1)
        {
            dp[i]=(sum[i-1]+1);
            sum[i]=(sum[i-1]+dp[i])%h;
        }
        else
        {
            LL tmp=dp[pos[A[i]]];
            dp[i]=(sum[i-1]+1)%h;
            sum[i]=(sum[i-1]+dp[i]-tmp)%h;
        }
        pos[A[i]]=i;
        //printf("%d %d %d\n",i,dp[i],sum[i]);
    }

    printf("%I64d\n",(sum[n]+h)%h);
}
