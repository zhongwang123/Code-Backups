#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=2e5;

LL m;
LL A[maxn+5];

LL check(LL x)
{
    LL res=0;
    for (int i=2;i<=maxn;++i)
    {
        LL tmp=x/A[i];
        res+=tmp;
    }
    return res;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%I64d",&m);

	for (int i=1;i<=maxn;++i)
    {
        A[i]=i*1LL*i*i;
    }

    LL lb=0;
    LL ub=1e16;

    while (ub-lb>1)
    {
        LL mid=(lb+ub)>>1;
        if (check(mid)>=m) ub=mid;
        else lb=mid;
    }

    if (check(ub)!=m) printf("-1\n");
    else printf("%I64d\n",ub);
}
