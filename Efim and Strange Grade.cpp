#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=2e5;

char s[maxn+5];
int ans[maxn+5];
int n,t;
int pos,End;

void inc(int p)
{
    if (ans[p]==-1)
    {
        --p;
        --End;
    }

    ++ans[p];
    if (ans[p]==10)
    {
        --End;
        ans[p]=0;
        inc(p-1);
    }
}
/*
void solve()
{
    int cur=n-1;

    while (t>0 && cur>=pos)
    {
        while (ans[cur+1]<=4)
        {
            --cur;
            if (ans[cur+1]==-1) return;
        }
        if (ans[cur]==-1) --cur;
        //printf("%d\n",cur);
        --t;
        End=cur;
        inc(cur);
        --cur;
    }
    return;
}
*/

void solve()
{
    int cur;

    for (cur=pos;cur<n;++cur)
    {
        if (ans[cur+1]<=4)
        {
            if (cur==n-1) return;
            continue;
        }
        if (ans[cur]==-1) --cur;
        break;
    }

    --t;
    End=cur;
    inc(cur);
    --cur;

    while (t>0)
    {
        if (cur<pos-1) return;
        if (ans[cur+1]>=5)
        {
            --t;
            End=cur;
            inc(cur);
            --cur;
        }
        else
        {
            break;
        }
    }

    return;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d%d",&n,&t);
	scanf("%s",s+1);

	for (int i=1;i<=n;++i)
    {
        if (s[i]!='.') ans[i]=s[i]-'0';
        else
        {
            ans[i]=-1;
            pos=i;
        }
    }
    //for (int i=1;i<=n;++i) printf("%d\n",ans[i]);

    End=n;
    solve();
    End=max(End,pos-1);
    if (ans[0]) printf("%d",ans[0]);
    for (int i=1;i<=End;++i)
    {
        if (ans[i]==-1) printf(".");
        else printf("%d",ans[i]);
    }
}
