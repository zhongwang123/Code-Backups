//****************************************************************************************************************//
//Source:UVAlive 7327
//Description:给定一个数的10进制表示，求将其划分为若干段，每段均能被m整除的方案数
//Note:
//Category:

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=300000;
const int h=1e9+7;

char s[maxn+5];
int n,m;

void solve()
{
    scanf("%s",s);

	LL ans=0;
	LL res=0;
	for (int i=0;i<=n-1;++i)
    {
        res=res*10+s[i]-'0';
        res%=m;
        if (res==0)
        {
            if (ans==0) ans=1;
            else ans=ans*2%h;
        }
    }
    if (res!=0) ans=0;         //这个细节导致了多次WA
    printf("%lld\n",ans);
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	while (scanf("%d%d",&n,&m)==2)
    {
        solve();
    }

}
