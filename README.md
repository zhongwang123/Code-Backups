[原题链接](http://www.spoj.com/problems/GSS2/en/)

### 题目大意
首先给定一个长度为 *N* 的序列，接下来给出 *Q* 个询问，每个询问有两个整数 *X* ，*Y* ，求在 [X,Y]之间的和最大的连续子串。同时，子串中重复出现的数字只算一次。

### Input
+ 第一行，整数N，1<=N<=100000
+ 第二行，N个整数，每个整数的数据范围是[-100000,100000]
+ 第三行，整数Q，1<=Q<=100000
+ 接下来Q行，两个整数X,Y，满足 1<=X<=Y<=N

### Output
+ 对于每个询问，输出一行代表答案

### 样例
##### Input
9   
4 -2 -2 3 -1 -4 2 2 -6   
3   
1 2   
1 5   
4 9   
##### Output
4   
5   
3   

### 题解
这道题的基本思路是这样的，首先基于离线线段树的思路，将询问区间排序，接下来从左到右，对于每个询问区间的右端点r，我们维护之前所有点i到r的区段和，也就是s[i]=(A[i]+A[i+1]+...+A[r]),那么对于每个询问，也就是求s[l],s[l+1],...,s[r]这些值从操作开始的 *历史* 最大值   
维护s[i]的过程是一个区间更新的过程，那么如何处理同一个数只处理一次这个限制条件呢？我们只需要记下一个数上一次出现的位置pos[i]，将pos[i]作为区间更新的左端点即可   
线段树可以实现求取在整个操作过程中的历史最大值，在线段树维护的变量中增加`max_sum`和`max_lazy`作为历史最大值和历史最大lazy值   
`max_sum`和`max_lazy`在`push_down`函数中的更新过程需要注意

### 代码
```C++
#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int maxn=1e5;
const int inf=1e9;

struct segQuery
{
    int l,r;
    bool operator < (const segQuery& rhs) const
    {
        if (r!=rhs.r) return r<rhs.r;
        else return l<rhs.l;
    }
};

struct Tnode
{
    LL sum,max_sum;
    LL lazy,max_lazy;
};

int n,q,Tsize;
int A[maxn+5],pos[2*maxn+5];
LL ans[maxn+5];
vector <int> v[maxn+5];
segQuery Q[maxn+5];
Tnode T[4*maxn+5];

void push_down(int k)
{
    int l=(k<<1);
    int r=(k<<1)+1;

    int lazy=T[k].lazy;
    int max_lazy=T[k].max_lazy;

    T[l].max_lazy=max(T[l].max_lazy,T[l].lazy+max_lazy);
    T[l].lazy+=lazy;
    T[l].max_sum=max(T[l].max_sum,T[l].sum+max_lazy);
    T[l].sum+=lazy;

    T[r].max_lazy=max(T[r].max_lazy,T[r].lazy+max_lazy);
    T[r].lazy+=lazy;
    T[r].max_sum=max(T[r].max_sum,T[r].sum+max_lazy);
    T[r].sum+=lazy;

    T[k].lazy=0;
    T[k].max_lazy=0;
}

void push_up(int k)
{
    int l=(k<<1);
    int r=(k<<1)+1;
    T[k].sum=max(T[l].sum,T[r].sum);
    T[k].max_sum=max(T[l].max_sum,T[r].max_sum);
}

void update(int k,int cl,int cr,int l,int r,int v)
{
    if (r<cl || cr<l) return;
    else if (l<=cl && cr<=r)
    {
        T[k].lazy+=v;
        T[k].sum+=v;
        T[k].max_sum=max(T[k].max_sum,T[k].sum);
        T[k].max_lazy=max(T[k].max_lazy,T[k].lazy);
        return;
    }
    else
    {
        int mid=(cl+cr)>>1;
        push_down(k);
        update(k<<1,cl,mid,l,r,v);
        update((k<<1)+1,mid+1,cr,l,r,v);
        push_up(k);
    }
}

LL query(int k,int cl,int cr,int l,int r)
{
    if (r<cl || cr<l) return -1;
    else if (l<=cl && cr<=r) return T[k].max_sum;
    else
    {
        push_down(k);
        int mid=(cl+cr)>>1;
        LL res=0;
        res=max(res,query(k<<1,cl,mid,l,r));
        res=max(res,query((k<<1)+1,mid+1,cr,l,r));
        push_up(k);
        return res;
    }
}

void solve(void)
{
    for (int i=1;i<=n;++i)
        scanf("%d",&A[i]);
    for (int i=1;i<=n;++i)
        v[i].clear();

    scanf("%d",&q);
    for (int i=1;i<=q;++i)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        v[Q[i].r].push_back(i);
    }

    memset(pos,0,sizeof(pos));
    memset(T,0,sizeof(T));

    Tsize=1;
    while (Tsize<n) Tsize<<=1;

    for (int i=1;i<=n;++i)
    {
        update(1,1,Tsize,pos[A[i]+maxn]+1,i,A[i]);
        pos[A[i]+maxn]=i;

        for (int j=0;j<v[i].size();++j)
        {
            int e=v[i][j];
            ans[e]=query(1,1,Tsize,Q[e].l,Q[e].r);
        }
    }

    for (int i=1;i<=q;++i)
    {
        printf("%lld\n",ans[i]);
    }
}

int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (scanf("%d",&n)==1)
    {
        solve();
    }
}
```
