//****************************************************************************************************************//
//Source: https://hihocoder.com/problemset/problem/1391
//Description:
//两个国家互相发射导弹，同时都拥有防御系统，在启动防御系统的时间内，所有攻击该国的导弹会被反弹。
//现在已知所有导弹的发射时间，空中飞行时间，伤害值，以及B国防御系统的启动时间，持续时间，求A国何时启动防御系统可以使自己受到的伤害最小。
//Note: 存在导弹在两国之间不断来回飞行的情况
//Category: 区间覆盖类问题

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int maxn=1e4;

struct Node
{
    int start;
    int time;
    int v;
};

int la,lb;
int X;
int n,m;

vector <Node> mi;
vector <PII> seg;
vector <PII> item;

void solve()
{
    scanf("%d",&X);
    scanf("%d%d",&n,&m);

    mi.clear();
    int start,time,v;
    for (int i=1;i<=n+m;++i)
    {
        scanf("%d%d%d",&start,&time,&v);
        if (i<=n && start+time>=X && start+time<=X+lb) //算出可能击中A国的导弹第一次飞临A国的时刻
        {
            mi.push_back((Node){start+2*time,time,v});
        }
        else if (i>n)
        {
            mi.push_back((Node){start+time,time,v});
        }
    }

    int ans=0;
    seg.clear();
    for (int i=0;i<mi.size();++i)
    {
        Node& e=mi[i];
        ans+=e.v;
        if (e.start+e.time<X || e.start+e.time>X+lb) seg.push_back(make_pair(e.start,e.start));
        else
        {
            int k=floor((X+lb-e.start+e.time)*1.0/(2*e.time)); //算出要想不被该导弹击中，防御系统必须存在的时间区间
            seg.push_back(make_pair(e.start,e.start+2*k*e.time));
        }
	}

    item.clear();
    for (int i=0;i<seg.size();++i)
    {
        PII& e=seg[i];
        if (e.first+la<e.second) continue;
        else
        {
            int st=e.second-la;
            int et=e.first;   //想要不被该导弹击中，防御系统的开启时间必须在[st,et]的区间内
            //printf("%d %d\n",st,et);
            item.push_back(make_pair(st,mi[i].v));
            item.push_back(make_pair(et+1,-mi[i].v)); //增加两个事件，前缀和思想。注意et+1
			//此处有个小细节，可能不同事件时间重合的情况，考虑pair的<定义，应该make_pair(st,mi[i].v)，make_pair(et+1,-mi[i].v)
			//而不是make_pair(st,mi[i].v)，make_pair(et+1,mi[i].v)
        }
    }

    sort(item.begin(),item.end());

    int MAX=0;
    int sum=0;
    for (int i=0;i<item.size();++i)
    {
        sum+=item[i].second; //前缀和
        MAX=max(MAX,sum);
    }

    printf("%d\n",ans-MAX);
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	while (scanf("%d%d",&la,&lb)==2)
    {
        solve();
    }
}
