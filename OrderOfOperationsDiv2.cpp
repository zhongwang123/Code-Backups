//****************************************************************************************************************//
//Source:
//Description: 
//计算机有m个内存单元，有n个进程，每个进程会调用若干内存，试安排进程执行的顺序，使得进程的花销最小
//进程的花销定义为所有进程调用时新使用的内存数的平方和
//即：对于进程i,所调用的内存中，有k个内存在前i-1个进程中未被调用，那么它的花销贡献为k*k；
//Note: wait for totally understand
//Category: 状压DP

//****************************************************************************************************************//

#line 2 "OrderOfOperationsDiv2.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=(1<<20);
const int inf=1e8;

int dp[maxn+5];
int A[25];
int n,m;
class OrderOfOperationsDiv2
{
    public:
    int minTime(vector <string> s)
    {
        int sum=0;
        n=s.size();
        m=s[0].length();
        for (int i=0;i<s.size();++i)
        {
            for (int j=0;j<s[i].length();++j)
            {
                if (s[i][j]=='1') A[i]|=(1<<j);
            }
            sum|=A[i];
        }

        for (int i=1;i<=(1<<m)-1;++i) dp[i]=inf;
        dp[0]=0;

        for (int mask=0;mask<=(1<<m)-1;++mask)
        {
            for (int i=0;i<=n-1;++i)
            {
                int new_mask=mask|A[i];
                int k=__builtin_popcount(new_mask-mask);
                dp[new_mask]=min(dp[new_mask],dp[mask]+k*k);
            }
        }
        return dp[sum];
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
