//****************************************************************************************************************//
//Source: SRM 683
//Description: 给定一棵树，定义子树为该树的一个连通子集，求该树所有子树的大小之和，树的大小为节点个数。
//Note:
//Category: 树形DP

//****************************************************************************************************************//

#line 2 "SubtreesCounting.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=1e5;
const int h=1e9+7;

LL A[maxn+5];
LL dp[maxn+5]; //以节点i为根的树，包含i的所有子树的大小之和
LL num[maxn+5]; //以节点i为根的树的所有子树的数量
vector <int> G[maxn+5];

LL ans=0;

void DP(int x,int p)
{
    if (dp[x]!=-1) return;

    dp[x]=1;
    num[x]=1;
    for (int i=0;i<G[x].size();++i)
    {
        int& e=G[x][i];
        if (e==p) continue;
        DP(e,x);

        dp[x]=(dp[x]*(num[e]+1)%h+dp[e]*num[x]%h)%h;
		num[x]=(num[x]*(num[e]+1))%h;
		//这里使用了空间优化，实际上，dp[x][i]表示x为根的考虑前i个分支的解
		//dp[x][i-1]的部分，将会在答案中出现num[e]+1次，而dp[e]的部分，将会出现num[x]次（x必须出现，不能为空）
		//这里隐含了把前i棵子树看成一颗子树的思想
    }
    ans=(ans+dp[x])%h;

    return;
}

class SubtreesCounting
{
    public:
    int sumOfSizes(int n, int a0, int b, int c, int m)
    {
        A[0]=a0;
        for (int i=1;i<=n-2;++i)
        {
            A[i]=(b*A[i-1]+c)%m;
        }
        for (int i=1;i<=n-1;++i)
        {
            int j=A[i-1]%i;
            G[i].push_back(j);
            G[j].push_back(i);
        }

        memset(dp,-1,sizeof(dp));
        DP(0,-1);

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
