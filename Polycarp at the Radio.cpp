//****************************************************************************************************************//
//Source:http://codeforces.com/contest/723/problem/C
//Description:
//Note:
//Category:

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=2000;

int n,m;
int A[maxn+5];
int cnt[maxn+5];
vector <int> res;

bool check(int x)
{
    return x*m<=n;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
    }

    int lb=0;
    int ub=2*maxn+1;

    while (ub-lb>1)
    {
        int mid=(ub+lb)>>1;
        if (check(mid)) lb=mid;
        else ub=mid;
    }

    int MAX=lb;

    int num=0;
    for (int i=1;i<=n;++i)
    {
        if (A[i]<=m)
        {
            ++cnt[A[i]];
        }
    }
    for (int i=1;i<=m;++i)
    {
        if (cnt[i]<MAX)
        {
            num+=(MAX-cnt[i]);
            res.push_back(i);
        }
    }


    int cur=0;
    for (int i=1;i<=n;++i)
    {
        if (cur==res.size()) break;
        int e=res[cur];
        if (A[i]>m)
        {
            A[i]=e;
            ++cnt[e];
            if (cnt[e]==MAX) ++cur;
        }
        else if (A[i]<=m && cnt[A[i]]>MAX)
        {
            --cnt[A[i]];
            A[i]=e;
            ++cnt[e];
            if (cnt[e]==MAX) ++cur;
        }
    }

    printf("%d %d\n",MAX,num);
    for (int i=1;i<=n;++i) printf("%d ",A[i]);
}
