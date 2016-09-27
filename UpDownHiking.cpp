#line 2 "UpDownHiking.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class UpDownHiking
{
    public:
    int maxHeight(int N, int A, int B)
    {
        int ans=0;
        for (int i=0;i<=N;++i)
        {
            int tmp=min(A*i,(N-i)*B);
            ans=max(tmp,ans);
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
