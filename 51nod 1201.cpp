//****************************************************************************************************************//
//Source:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1201
//Description: 给定一个数，求多少种不同的方式将他划分为若干不同的整数
//Note:
//Category:DP

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=50000;
const int MOD=1e9+7;

LL dp[maxn+5][325];

int n;

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d",&n);

	dp[0][0]=1;
	for (int i=1;i<=n;++i) //dp[i][j],将i划分问j个不同的数的方案数
    {
        for (int j=1;j<=320;++j)
        {
            if (i>=j) dp[i][j]=(dp[i-j][j]+dp[i-j][j-1])%MOD;
        }
    }

    LL ans=0;
    for (int i=1;i<=320;++i)
    {
        ans=(ans+dp[n][i])%MOD;
    }
    printf("%I64d\n",ans);
}
