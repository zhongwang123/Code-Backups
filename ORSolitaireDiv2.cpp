//****************************************************************************************************************//
//Source: SRM 600 div1
//Description:给定一些数，要求拿去最少的数，使得剩下的数无法通过 OR 操作获得goal
//Note: numbers.size()<=20
//Category: 状压DP

//****************************************************************************************************************//

#line 2 "ORSolitaireDiv2.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=(1<<20)-1;
bool dp[maxn+5];

void check(int st,vector<int>& v,int goal)
{
    int k=0;
    vector <int> tmp;
    for (int i=0;i<v.size();++i)
    {
        if (st & (1<<i))
        {
            k=k|v[i];
            tmp.push_back(i);
        }
    }

    if (k==goal) dp[st]=true;

    for (int i=0;i<tmp.size();++i) //当前状态下，去掉某一个数，如果可以获得合法解，则dp[st]=true，如果无论如何都没有获得合法解，则确实无解
    {
        int st2=(st & ~(1<<tmp[i]));
        if (dp[st2]==true) dp[st]=true;
    }
}

class ORSolitaireDiv2
{
    public:
    int getMinimum(vector <int> numbers, int goal)
    {
        int sz=numbers.size();
        int MAX_SZ=(1<<sz)-1;

        int ans=sz;
        memset(dp,0,sizeof(dp));
        for (int i=0;i<=MAX_SZ;++i)
        {
            check(i,numbers,goal);
        }

        for (int i=0;i<=MAX_SZ;++i)
        {
            if (dp[i]==false) ans=min(ans,sz-__builtin_popcount(i));
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
