//****************************************************************************************************************//
//Source: SRM 698
//Description: 给定一个字符串S，通过 1.增加字符，2.删除字符，3.修改字符，三种操作，使得S变成T+T的形式
//Note:
//Category: 朴素DP

//****************************************************************************************************************//

#line 2 "RepeatString.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF=1e9;

int dp[55][55];

int f(string a,string b)
{
    if (a.length()==0) return b.length();
    if (b.length()==0) return a.length();

    for (int i=0;i<=a.length();++i)
    {
        for (int j=0;j<=b.length();++j)
            dp[i][j]=INF;
    }
	
    dp[0][0]=0;
    for (int i=0;i<=a.length();++i)
    {
        for (int j=0;j<=b.length();++j)
        {
            if (i>0 && j>0) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(a[i-1]!=b[j-1])); //注意这里下标从1开始
            if (i>0) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
            if (j>0) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
        }
    }

    return dp[a.length()][b.length()];
}

class RepeatString
{
    public:
    int minimalModify(string s)
    {
        if (s=="") return 0;

        int ans=INF;
        for (int i=0;i<s.length();++i)
        {
            ans=min(ans,f(s.substr(0,i),s.substr(i))); //枚举分界点
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
