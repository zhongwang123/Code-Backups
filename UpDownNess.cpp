//****************************************************************************************************************//
//Source: SRM 694
//Description: 给定整数N,K，问N的全排列中，有多少全排列中恰好有K个3元数组(i,j,k)，满足i<j<k且A[i]<A[j]>A[k];
//Note:
//Category:DP

//****************************************************************************************************************//

#line 2 "UpDownNess.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int h=1e9+7;

LL dp[55][5005]; //dp[n][k],n的全排列中多少满足有k个满足题给条件的3元数组

class UpDownNess
{
    public:
    int count(int N, int K)
    {
        dp[1][0]=1;
        for (int i=2;i<=N;++i)
        {
            for (int j=0;j<=K;++j)
            {
                for (int k=0;k<=i-1;++k)
                {
                    int tmp=(i-1-k)*k;
                    if (j>=tmp) dp[i][j]=(dp[i][j]+dp[i-1][j-tmp])%h;//在n-1的全排列的位置k插入n，增加(n-k-1)*k个题给3元数组
                }
            }
        }

        return dp[N][K];
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
