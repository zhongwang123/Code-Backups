//****************************************************************************************************************//
//Source: http://codeforces.com/problemset/problem/721/D
//Description: 给定一个序列，每次可以取出一个数，将其+x或者-x，问经过k次这样的操作，整个序列的乘积最小是多少
//Note:
//Category:

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=2e5;

struct Node
{
    LL v;
    int pos;

    bool operator < (const Node& rhs) const
    {
        return abs(v)>abs(rhs.v);
    }
};

int n,k,x;
int A[maxn+5];
LL ans[maxn+5];
priority_queue <Node,vector<Node> >Q;

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d%d%d",&n,&k,&x);
	int num=0;
	for (int i=1;i<=n;++i)
    {
        scanf("%d",&A[i]);
        Q.push((Node){A[i],i});
        if (A[i]<0) ++num; //num维护序列乘积是正数还是负数
    }

    for (int i=1;i<=k;++i)
    {
        Node tmp=Q.top();Q.pop();
        if (num&1)
        {
            if (tmp.v<0) tmp.v-=x;
            else tmp.v+=x;

            Q.push(tmp);
        }
        else
        {
            if (tmp.v<0)
            {
                tmp.v+=x;
                Q.push(tmp);
                if (tmp.v>=0) --num;
            }
            else
            {
                tmp.v-=x;
                Q.push(tmp);
                if (tmp.v<0) ++num;
            }
        }
    }

    while (!Q.empty())
    {
        Node e=Q.top();
        Q.pop();
        ans[e.pos]=e.v;
    }

    for (int i=1;i<=n;++i) printf("%I64d ",ans[i]);
}
