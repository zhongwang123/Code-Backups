//****************************************************************************************************************//
//Source: SRM 696
//Description: 给定两个序列A[],B[],以及序列F[]，要求使用F[]中的元素，替换A[]中的某些元素，使得A[],B[]之间对应位置相同元素尽可能多
//Note: F[]中的元素必须全部用完
//思维题

//****************************************************************************************************************//

#line 2 "Arrfix.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int cnt[1005];
int mark[60];

class Arrfix
{
    public:
    int mindiff(vector <int> A, vector <int> B, vector <int> F)
    {
        for (int i=0;i<F.size();++i)
            cnt[F[i]]++;

        int ans=0;
        int num=F.size(); //F[]中剩余未使用元素
        int chance=0;   //所有可能的配对完成之后，剩余未配对的元素数量

        for (int i=0;i<A.size();++i)
        {
            if (A[i]!=B[i])
            {
                if (cnt[B[i]])
                {
                    --num;
                    --cnt[B[i]];
                    mark[i]=1; //标记已经配对
                }
                else ++ans; //无法配对的数量
            }
        }

        for (int i=0;i<A.size();++i)
        {
            if (A[i]==B[i])
            {
                if (cnt[B[i]])
                {
                    --num;
                    --cnt[B[i]];
                }
            }
            else if (!mark[i]) ++chance;
        }

        if (num<=chance) return ans;
        else return ans+num-chance; //因为F[]必须全部用完，剩余元素会把一些已经配对的位置破坏，导致未配对数增加
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
