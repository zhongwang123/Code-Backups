//****************************************************************************************************************//
//Source: SRM 600 div2
//Description: 给定一个01矩阵，可以做0，1的变换操作，求最少操作数，使得至少存在若干列和若干行为“回文串”
//Note: 矩阵大小不超过8*8
//Category:

//****************************************************************************************************************//

#line 2 "PalindromeMatrixDiv2.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;

const int maxn=8;

int n,m;
int vis[maxn+5][maxn+5];
int mp[maxn+5][maxn+5];
int row[maxn+5];
int col[maxn+5];
vector <PII> G[maxn+5][maxn+5];

void dfs(int x,int y,int& o,int& z)
{
    vis[x][y]=1;
    if (mp[x][y]==0) ++o;
    else ++z;

    for (int i=0;i<G[x][y].size();++i)
    {
        PII& e=G[x][y][i];
        if (vis[e.first][e.second]) continue;
        else dfs(e.first,e.second,o,z);
    }
}

int solve()
{
    for (int i=0;i<=n-1;++i)
        for (int j=0;j<=m-1;++j) G[i][j].clear();
    memset(vis,0,sizeof(vis));

    for (int i=0;i<=n-1;++i)
    {
        if (row[i]==1)
        {
            for (int j=0;j<=m-1;++j)
            {
                G[i][j].push_back(make_pair(i,m-j-1)); //对于回文串，存在若干相等关系，我们以位置为节点，“=”为边建图，要求连通集全为0或者1。
                                                       //也就求连通集中0和1数量较小的那个，将其变成另外一个
            }
        }
    }

    for (int i=0;i<=m-1;++i)
    {
        if (col[i]==1)
        {
            for (int j=0;j<=n-1;++j)
            {
                G[j][i].push_back(make_pair(n-j-1,i));
            }
        }
    }

    int res=0;
    for (int i=0;i<=n-1;++i)
    {
        for (int j=0;j<=m-1;++j)
        {
            if ((row[i] || col[j]) && !vis[i][j])
            {
                int o=0;
                int z=0;
                dfs(i,j,o,z);
                res+=min(o,z);
            }
        }
    }
    return res;
}

class PalindromeMatrixDiv2
{
    public:
    int minChange(vector <string> A, int rowCount, int columnCount)
    {
        n=A.size();
        m=A[0].length();
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j)
            {
                mp[i][j]=A[i][j]-'0';
            }
        }

        for (int i=0;i<=rowCount-1;++i) row[i]=1;
        for (int i=0;i<=columnCount-1;++i) col[i]=1;

        sort(row,row+n);
        sort(col,col+m);

        int ans=n*m;
        do    //枚举所有的情况，复杂度最多C(8,4)*C(8,4)<=5000
        {
            do
            {
                ans=min(ans,solve());
            }while (next_permutation(row,row+n));
        }while (next_permutation(col,col+m));

        return ans;
    }
};

#ifdef ex
int main()
{
    #ifdef ex1
    freopen ("in.txt","r",stdin);
    #endif

}
#endif
