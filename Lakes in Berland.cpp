#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int maxn=50;

char mp[maxn+5][maxn+5];
int n,m;
int k;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int vis[maxn+5][maxn+5];
int id[3000];
int num[3000];
vector <int> ans;

queue <pair<int,int> > Q;

bool cmp(int a,int b)
{
    return num[a]<num[b];
}

void pre()
{
    for (int i=1;i<=n;++i)
    {
        Q.push(make_pair(i,0));
        Q.push(make_pair(i,m+1));
        vis[i][0]=-1;
        vis[i][m+1]=-1;
    }
    for (int i=1;i<=m;++i)
    {
        Q.push(make_pair(0,i));
        Q.push(make_pair(n+1,i));
        vis[0][i]=-1;
        vis[n+1][i]=-1;
    }

    while (!Q.empty())
    {
        PII e=Q.front();
        Q.pop();

        int x=e.first;
        int y=e.second;
        //printf("%d %d\n",x,y);
        for (int i=0;i<=3;++i)
        {
            int tx=x+dx[i];
            int ty=y+dy[i];

            if (tx<0 || tx>n+1 || ty<0 || ty>m+1) continue;
            if (vis[tx][ty]) continue;
            if (mp[tx][ty]=='*') continue;
            Q.push(make_pair(tx,ty));
            vis[tx][ty]=-1;
        }
    }
}

void bfs(int x,int y,int id)
{
    vis[x][y]=id;
    for (int i=0;i<=3;++i)
    {
        int tx=dx[i]+x;
        int ty=dy[i]+y;
        /*
        if (tx<0 || tx>=n || ty<0 || ty>=m)
        {
            vis[x][y]=-1;
            return -1;
        }
        */
        if (mp[tx][ty]=='*') continue;
        if (vis[tx][ty])
        {
            continue;
        }
        bfs(tx,ty,id);
    }
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;++i)
    {
        scanf("%s",mp[i]+1);
    }
    pre();

    int mask=0;
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (mp[i][j]=='.' && vis[i][j]==0)
            {
                bfs(i,j,++mask);
            }
        }
    }

    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (vis[i][j]>=1)
            {
                int e=vis[i][j];
                ++num[e];
            }
        }
    }

    for (int i=1;i<=mask;++i) id[i]=i;
    sort(id+1,id+1+mask,cmp);

    int cnt=0;
    for (int i=1;i<=mask-k;++i)
    {
        cnt+=num[id[i]];
        ans.push_back(id[i]);
    }

    for (int i=0;i<ans.size();++i)
    {
        for (int j=1;j<=n;++j)
        {
            for (int k=1;k<=m;++k)
            {
                if (vis[j][k]==ans[i])
                {
                    vis[j][k]=0;
                    mp[j][k]='*';
                }
            }
        }
    }
    printf("%d\n",cnt);
    for (int i=1;i<=n;++i)
    {
        printf("%s\n",mp[i]+1);
    }
}
