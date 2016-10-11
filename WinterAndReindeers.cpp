//****************************************************************************************************************//
//Source: SRM 601
//Description: 给定A,B,C，3个字符串，寻找一个最长的字符串X，使得X是A,B的子序列，同时C是X的子串
//Note:
//Category:DP+LCS

//****************************************************************************************************************//

#line 2 "WinterAndReindeers.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=2500;

string A;
string B;
string C;

int dp[maxn+5][maxn+5],dp2[maxn+5][maxn+5];

int check(string& A,int posA,int posC)
{
    if (posC==C.length()) return posA-1;
    for (int i=posA;i<=A.length()-1;++i)
    {
        if (A[i]==C[posC])
        {
            return check(A,i+1,posC+1);
        }
    }
    return -1;
}

class WinterAndReindeers
{
    public:
    int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)
    {
        for (int i=0;i<allA.size();++i) A=A+allA[i];
        for (int i=0;i<allB.size();++i) B=B+allB[i];
        for (int i=0;i<allC.size();++i) C=C+allC[i];

        //cout<<A<<' '<<B<<' '<<C<<endl;

        for (int i=1;i<=A.length();++i)
        {
            for (int j=1;j<=B.length();++j)
            {
                if (A[i-1]==B[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

        for (int i=A.length();i>=1;--i)
        {
            for (int j=B.length();j>=1;--j)
            {
                if (A[i-1]==B[j-1]) dp2[i][j]=dp2[i+1][j+1]+1;
                else dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1]);
            }
        }

        vector <pair<int,int> > v1,v2;
        for (int i=0;i<=A.length()-1;++i)
        {
            if (A[i]==C[0])
            {
                int k=check(A,i+1,1);
                if (k!=-1) v1.push_back(make_pair(i,k));
            }
        }

        for (int i=0;i<=B.length()-1;++i)
        {
            if (B[i]==C[0])
            {
                int k=check(B,i+1,1);
                if (k!=-1) v2.push_back(make_pair(i,k));
            }
        }

        int ans=0;
        //cout<<v1.size()<<' '<<v2.size()<<endl;
        for (int i=0;i<v1.size();++i)
        {
            for (int j=0;j<v2.size();++j)
            {
                int s1=v1[i].first-1;
                int s2=v2[j].first-1;
                int e1=v1[i].second+1;
                int e2=v2[j].second+1;

                int tmp=C.length()+dp[s1+1][s2+1]+dp2[e1+1][e2+1];
                ans=max(ans,tmp);
            }
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
