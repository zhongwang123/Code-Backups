//****************************************************************************************************************//
//Source: SRM 562
//Description: 给定数keyCount和两个vector,求0-keyCount的全排列中，两个vector对应位置的数都不相邻的概率
//Note:
//Category: 状压DP

//****************************************************************************************************************//

#line 2 "RandomOption.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=(1<<15)-1;

bool c[20][20];
LL dp[maxn+5][20];

class RandomOption
{
    public:
    double getProbability(int keyCount, vector <int> badLane1, vector <int> badLane2)
    {
        for (int i=0;i<badLane1.size();++i)
        {
            c[badLane1[i]][badLane2[i]]=true;
            c[badLane2[i]][badLane1[i]]=true;
        }

        for (int i=0;i<=keyCount-1;++i)
        {
            dp[(1<<i)][i]=1;
        }

        int MAX=(1<<keyCount)-1;
        for (int s=1;s<=MAX;++s)  //dp[s][i]，已经使用了s这些数，并且以i结尾的方案数
        {
            for (int i=0;i<=keyCount-1;++i)
            {
                if (s & (1<<i))
                {
                    for (int j=0;j<=keyCount-1;++j)
                    {
                        if (!(s & (1<<j)) && !c[i][j])
                        {
                            dp[s|(1<<j)][j]+=dp[s][i]; //刷表法
                        }
                    }
                }
            }
        }

        LL num=0;
        for (int i=0;i<=keyCount-1;++i)
        {
            num+=dp[MAX][i];
        }

        double ans=num*1.0;
        for (int i=1;i<=keyCount;++i) ans/=i;

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
