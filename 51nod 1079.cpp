//****************************************************************************************************************//
//Source:http://www.51nod.com/onlineJudge/questionCode.html#!problemId=1079
//Description: 中国剩余定理裸题
//Note:
//Category:数学

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

int A[20];
int p[20];

void ext_gcd(LL a,LL b,LL &d,LL &x,LL &y)
{
	if (!b)
	{
		d=a;x=1;y=0;
	}
	else
	{
		ext_gcd(b,a%b,d,y,x);
		y-=x*(a/b);
	}
}

LL CRT(int a[],int m[],int n) //a[]是模数序列，m[]是对应的余数序列
{
    LL M=1;
    LL ans=0;
    for(int i=1;i<=n;i++)
        M*=m[i];
    for(int i=1;i<=n;i++)
    {
        LL x,y,d;
        LL Mi=M/m[i];
        ext_gcd(Mi,m[i],d,x,y);
        ans=(ans+(Mi*x)%M*a[i])%M;
    }
    if(ans<0) ans+=M;
    return ans;
}

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
        scanf("%d%d",&p[i],&A[i]);
    }

    printf("%I64d\n",CRT(A,p,n));
}
