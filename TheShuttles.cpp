//****************************************************************************************************************//
//Source:SRM 600 div2
//Description:
//Note:
//Category:水题

//****************************************************************************************************************//

#line 2 "TheShuttles.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class TheShuttles
{
    public:
    int getLeastCost(vector <int> cnt, int baseCost, int seatCost)
    {
        int ans=1e9;
        for (int i=1;i<=100;++i)
        {
            int tmp=0;
            int cost=baseCost+i*seatCost;
            for (int j=0;j<cnt.size();++j)
            {
                int num=(cnt[j]+i-1)/i;
                tmp+=num*cost;
            }
            ans=min(ans,tmp);
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
