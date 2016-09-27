//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=5493
//Description: 一些人排队，每个人高度各不相同，每个人直接的排在自己前面的或者排在后面的比自己高的人，求复原原序列使得字典序最小
//Note:
//Category: 二分+树状数组

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1e5;

struct Node
{
    int h;
    int k;
    bool operator < (const Node& a)
    {
        return h<a.h;
    }
};

int n;
Node p[maxn+5];
int ans[maxn+5];
int bit[maxn+5];

int sum(int p)
{
    int s=0;
    int num=p;
    while (p>0)
    {
        s+=bit[p];
        p-=p&(-p);
    }
    return num-s;
}

void add(int p,int x)
{
    while (p<=n)
    {
        bit[p]+=x;
        p+=p&(-p);
    }
}

int getPos(int x) //二分树状数组的sum函数寻找插入点
{
    int l=0;
    int r=n+1;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (sum(mid)>=x+1) r=mid;
        else l=mid;
    }
    return r;
}

void solve(int Case)
{
    scanf("%d",&n);
    int h,k;
    for (int i=1;i<=n;++i)
    {
        scanf("%d%d",&h,&k);
        p[i]=(Node){h,k};
    }
    sort(p+1,p+1+n); //先排序是非常重要的一步

    memset(bit,0,sizeof(int)*(n+1));
    for (int i=1;i<=n;++i)
    {
        int x=min(p[i].k,n-p[i].k-i);
        if (x<0)
        {
            printf("Case #%d: impossible\n",Case);
            return;
        }

        int pos=getPos(x);
        ans[pos]=i;
        add(pos,1);
    }

    printf("Case #%d:",Case);
    for (int i=1;i<=n;++i)
    {
        int id=ans[i];
        printf(" %d",p[id].h);
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
