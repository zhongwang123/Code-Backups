//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=5532
//Description:  给定一个序列，判断是否可以通过移除序列的某个元素，使得序列有序
//Note:
//Category: 思维题

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1e5;

int A[maxn+5];

bool solve() //思路是考量有序序列的“小于号”和“大于号”至少有一个为0
{
    int n;
    scanf("%d",&n);

    for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
    }

    if (n<=3) return true;

    int op1=0;
    int op2=0;
    for (int i=2;i<=n;++i)
    {
        if (A[i]>A[i-1]) ++op1;
        else if (A[i]<A[i-1]) ++op2;
    }

    int x1,x2;
    for (int i=2;i<=n-1;++i)
    {
        x1=op1;//<
        x2=op2;//>

        if (A[i]>A[i-1]) --x1;
        else if (A[i]<A[i-1]) --x2;
        if (A[i+1]>A[i]) --x1;
        else if (A[i+1]<A[i]) --x2;

        if (A[i+1]>A[i-1]) ++x1;
        else if (A[i+1]<A[i-1]) ++x2;

        if (x1==0 || x2==0) return true;
    }

    x1=op1;
    x2=op2;
    if (A[2]>A[1]) --x1;
    else if (A[2]<A[1]) --x2;
    if (x1==0 || x2==0) return true;

    x1=op1;
    x2=op2;
    if (A[n]>A[n-1]) --x1;
    else if (A[n]<A[n-1]) --x2;
    if (x1==0 || x2==0) return true;

    return false;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int T;
	scanf("%d",&T);

	while (T--)
    {
        if (solve()) printf("YES\n");
        else printf("NO\n");
    }
}
