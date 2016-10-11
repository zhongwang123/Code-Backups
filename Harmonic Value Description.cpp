//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=5916
//Description: 给定n,k,对于所有n的排列，求sigma(gcd(p(i),p(i-1))的第k大的值
//Note:
//Category:构造

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

int n,k;

void solve(int iCase)
{
    scanf("%d%d",&n,&k);
    printf("Case #%d:",iCase);

    for (int i=n;i>=2*k;--i)
    {
        printf(" %d",i);
    }
    for (int i=k;i>=1;--i)
    {
        printf(" %d",i);
    }

    for (int i=k+1;i<=2*k-1;++i)
    {
        printf(" %d",i);
    }
    printf("\n");
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int T;
	scanf("%d",&T);

	for (int i=1;i<=T;++i)
    {
        solve(i);
    }
}
