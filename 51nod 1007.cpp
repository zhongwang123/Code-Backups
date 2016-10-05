//****************************************************************************************************************//
//Source:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1007
//Description:
//Note:
//Category:

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1e4;

bool dp[maxn+5];
bool nd[maxn+5];

int A[100+5];

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

    int sum=0;
    dp[0]=true;
    for (int i=1;i<=n;++i)
    {
        sum+=A[i];
        for (int j=0;j<=sum;++j)
        {
            if (dp[j]==true)
            {
                nd[j+A[i]]=true;
                nd[sum-j]=true;
            }
        }
        memcpy(dp,nd,sizeof(nd));
    }

    int ans=maxn;
    for (int i=0;i<=sum;++i)
    {
        if (dp[i]==true)
        {
            ans=min(abs(sum-2*i),ans);
        }
    }
    printf("%d\n",ans);
}
