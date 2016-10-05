//****************************************************************************************************************//
//Source:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1412
//Description:
//Note:
//Category:朴素DP

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=2000;
const int MOD=1e9+7;

LL dp[20][maxn+5];
int A[20];


int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int n;
	scanf("%d",&n);

	dp[0][0]=1;
	dp[1][1]=1;

	for (int i=2;i<=min(n,15);++i) //在这道题，循环化的写法比记忆化的写法更优，更快，更不易写错
    {
        for (int j=1;j<=n;++j)
        {
            for (int k=0;k<=j-1;++k)
            {
                dp[i][j]=(dp[i][j]+dp[i-2][k]*dp[i-1][j-k-1]%MOD)%MOD;
            }
            dp[i][j]=dp[i][j]*2%MOD;
            for (int k=0;k<=j-1;++k)
            {
                dp[i][j]=(dp[i][j]+dp[i-1][k]*dp[i-1][j-k-1]%MOD)%MOD;
            }
        }
    }

	LL ans=0;
	for (int i=1;i<=min(n,15);++i)
    {
        ans=(ans+dp[i][n])%MOD;
    }

    printf("%I64d\n",ans);
}

