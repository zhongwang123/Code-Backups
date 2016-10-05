//****************************************************************************************************************//
//Source:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1106
//Description: 素数检测
//Note:
//Category:数学

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int Times=10;

LL multi(LL a, LL b, LL m)
{
    LL ans=0;
    a%=m;
    while(b)
    {
        if(b & 1)
        {
            ans=(ans + a)%m;
            b--;
        }
        b>>=1;
        a=(a+a)%m;
    }
    return ans;
}

LL quick_mod(LL a, LL b, LL m)
{
    LL ans=1;
    a%=m;
    while(b)
    {
        if(b & 1)
        {
            ans=multi(ans,a,m);
            b--;
        }
        b>>=1;
        a=multi(a,a,m);
    }
    return ans;
}

bool Miller_Rabin(LL n)
{
    if(n==2) return true;
    if(n<2 || !(n & 1)) return false;
    LL m=n-1;
    int k =0;
    while((m & 1)==0)
    {
        k++;
        m>>=1;
    }
    for(int i=0;i<Times;i++)
    {
        LL a=rand()%(n-1)+1;
        LL x=quick_mod(a,m,n);
        LL y=0;
        for(int j=0;j<k;j++)
        {
            y = multi(x,x,n);
            if(y==1 && x!=1 && x!=n-1) return false;
            x=y;
        }
        if(y!=1) return false;
    }
    return true;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int n;
	scanf("%d",&n);

	int x;
	for (int i=1;i<=n;++i)
    {
        scanf("%d",&x);
        if (Miller_Rabin(x)) printf("Yes\n");
        else printf("No\n");
    }
}
