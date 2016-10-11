//****************************************************************************************************************//
//Source: SRM 600 div1
//Description:给定一些数，要求拿去最少的数，使得剩下的数无法通过 OR 操作获得goal
//Note: numbers.size()<=50
//Category: 思维

//****************************************************************************************************************//

#line 2 "ORSolitaire.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class ORSolitaire
{
    public:
    int getMinimum(vector <int> numbers, int goal) //无法组出goal，只要二进制下goal的某位为1，而剩下的数该位均为0即可
    {
        int ans=numbers.size();
        for (int i=0;i<=31;++i)
        {
            if (goal & (1<<i))
            {
                int tmp=0;
                for (int e:numbers)
                {
                    if ((e & (1<<i)) && (goal & e)==e) ++tmp;
                }
                ans=min(ans,tmp);
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
