//****************************************************************************************************************//
//Source: https://hihocoder.com/problemset/problem/1048
//Description:
//Note:
//Category:状压DP

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int h=1e9+7;
const int maxn=1000;
const int st=(1<<5);

int n,m;
int dp[maxn+5][5][st+5][st+5];

int DP(int x,int y,int s1,int s2)
{
    if (x==n) return 1;
    if (y==m)
    {
        return DP(x+1,0,s2,0);
    }

    int& res=dp[x][y][s1][s2];
    if (res!=-1) return res;

    if (s1 & (1<<y))
    {
        return DP(x,y+1,s1,s2);
    }

    res=0;
    if (x<n-1)
    {
        res=(res+DP(x,y+1,s1|(1<<y),s2|(1<<y)))%h;
    }
    if (y<m-1 && !(s1 & (1<<(y+1))))
    {
        res=(res+DP(x,y+2,s1|(1<<y)|(1<<(y+1)),s2))%h;
    }

    //printf("dp[%d][%d][%d][%d]=%d\n",x,y,s1,s2,res);
    return res;
}

void solve()
{
    clr(dp,-1);
	printf("%d\n",DP(0,0,0,0));
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	while (scanf("%d%d",&n,&m)==2)
    {
        if (n==0 && m==0) break;
        solve();
    }
}
