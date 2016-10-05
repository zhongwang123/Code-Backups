//****************************************************************************************************************//
//Source:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1086
//Description: 多重背包
//Note:2进制优化的多重背包
//Category:背包DP

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=100;

int n,w;
int cost[maxn+5],value[maxn+5],num[maxn+5];
LL dp[50005];
vector <pair<int,int> > item;

void trans(int i)
{
    int k=0;
    while ((1<<(k+1))<num[i]+1) ++k;

    for (int j=0;j<=k-1;++j)
    {
        int x=1<<j;
        item.push_back(make_pair(cost[i]*x,value[i]*x));
    }
    int re=num[i]-(1<<k)+1;
    item.push_back(make_pair(cost[i]*re,value[i]*re));
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d%d",&n,&w);
	for (int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&cost[i],&value[i],&num[i]);
        trans(i);
    }

    for (int i=0;i<item.size();++i)
    {
        for (int j=w;j>=0;--j)
        {
            if (j>=item[i].first)
            {
                dp[j]=max(dp[j],dp[j-item[i].first]+item[i].second);
            }
        }
    }
    printf("%d\n",dp[w]);
}
