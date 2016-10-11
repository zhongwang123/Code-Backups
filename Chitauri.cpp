//****************************************************************************************************************//
//Source: XVI Open Cup named after E.V. Pankratiev Grand Prix of Yekaterinburg, Div 1, Sunday, November 1, 2015
//Description:海盗分金
//Note:
//Category:递推

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

int n,k;
int ans[1005];

void solve()
{
    if (n==1)
    {
        ans[1]=k;
        return;
    }
    ans[1]=0;
    ans[2]=k;

    for (int i=3;i<=n;++i)
    {
        int cnt=0;
        for (int j=1;j<=i-1;++j)
        {
            if (ans[j]==-1) ++cnt;
        }
        if ((k+cnt+1)*2<i) ans[i]=-1;
        else
        {
            int tmp=k;
            for (int j=i-1;j>=1;--j)
            {
                if (ans[j]==0 && (cnt+1)*2<i)
                {
                    ans[j]=1;
                    --tmp;
                    ++cnt;
                }
                else if (ans[j]==-1) ans[j]=0;
                else if (ans[j]>=1) ans[j]=0;
            }
            ans[i]=tmp;
        }
    }
}

int main(void)
{
    #ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif
	scanf("%d%d",&n,&k);

	solve();
    for (int i=n;i>=1;--i)
    {
        printf("%d ",ans[i]);
    }
}
