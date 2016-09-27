//****************************************************************************************************************//
//Source: SRM 696
//Description:
//给定一些点之间的关系，包括点对之间确定没有边，确定有边以及不确定，对于不确定的边，最多有k个，可能的图有2^k种
//对于这2^k张图，分别求出其最大完全子图的大小，最后求和。
//Note: wait for totally understand
//Category: 状压DP
//****************************************************************************************************************//

#line 2 "Clicountingd2.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=(1<<20);

int dp[maxn+5];
int mark[30][30];
int n;
vector <int> v;

void update()
{
    int st=0;
    for (int i=0;i<v.size();++i)
    {
        for (int j=i+1;j<v.size();++j)
        {
            int& e1=v[i];
            int& e2=v[j];
            if (mark[e1][e2]==-1) return;
            else if (mark[e1][e2]>=0) st|=(1<<mark[e1][e2]);
        }
    }

    dp[st]=max(dp[st],(int)v.size());
}

class Clicountingd2
{
    public:
    int count(vector <string> g)
    {
        n=g.size();
        int sz=0;
        for (int i=0;i<=n-1;++i)
        {
            for (int j=i;j<=n-1;++j)
            {
                if (g[i][j]=='?') mark[i][j]=sz++;
                else if (g[i][j]=='0') mark[i][j]=-1;
                else mark[i][j]=-2;

                mark[j][i]=mark[i][j];
            }
        }

        int Max_mask=(1<<n)-1;
        for (int mask=0;mask<=Max_mask;++mask)
        {
            v.clear();
            for (int i=0;i<=n-1;++i)
                if (mask>>i & 1) v.push_back(i);

            update();
        }

        int ans=0;
        int Max_state=(1<<sz)-1;
        for (int mask=0;mask<=Max_state;++mask)
        {
            for (int i=0;i<=sz-1;++i)
            {
                int tmp=mask|(1<<i);
                dp[tmp]=max(dp[tmp],dp[mask]);
            }
            ans+=dp[mask];
        }

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
