#line 2 "LastDigit.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL A[20],B[20];
int cnt;
LL ans;

void pre(LL S)
{
    A[0]=1;
    B[0]=1;
    for (int i=1;i<=18;++i)
    {
        A[i]=A[i-1]*10;
        B[i]=A[i]+B[i-1];
    }

    cnt=0;
    while (S)
    {
        S/=10;
        ++cnt;
    }
}

bool dfs(int pos,LL S)
{
    if (pos==-1)
    {
        if (S==0) return true;
        else return false;
    }

    int p=S/B[pos];
    //printf("%d %d\n",pos,p);
    if (p>=10) return false;
    ans+=A[pos]*p;
    return dfs(pos-1,S-p*B[pos]);
}

class LastDigit
{
    public:
    long long findX(long long S)
    {
        ans=0;
        pre(S);
        if (dfs(cnt-1,S))
        {
            return ans;
        }
        else return -1;
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
