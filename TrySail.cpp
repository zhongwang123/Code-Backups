//****************************************************************************************************************//
//Source: SRM 694
//Description: 
//有n个学生，每个学生有力量值，将他们分为非空的3组，每个组的力量为组内学生的力量值的异或和。
//总的力量值为3个组的力量值之和，最大化总力量值
//Note:
//Category: 
//因为当前状态只取决于上一轮的状态，下面第一份代码是数组实现的，第二份代码是队列滚动
//注意，虽然要求每个组非空，但是存在空组的情况不会是最大值，证明略
//虽然要保存3个组的状态，但是实际上只要保存两组，第3组可以推出来

//****************************************************************************************************************//

#line 2 "TrySail.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=(1<<8);

bool dp[maxn+5][maxn+5];
bool nd[maxn+5][maxn+5];

class TrySail
{
    public:
    int get(vector <int> strength)
    {
        dp[0][0]=true;
        int all=0;
        for (int i=0;i<strength.size();++i)
        {
            all^=strength[i];
            for (int j=0;j<=maxn;++j)
            {
                for (int k=0;k<=maxn;++k)
                {
                    if (dp[j][k])
                    {
                        nd[j][k]=true;
                        nd[j^strength[i]][k]=true;
                        nd[j][k^strength[i]]=true;
                    }
                }
            }
            memcpy(dp,nd,sizeof(dp));
        }

        int ans=0;
        for (int i=0;i<=maxn;++i)
        {
            for (int j=0;j<=maxn;++j)
            {
                if (dp[i][j])
                ans=max(ans,i+j+(all^i^j));
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

/*
#line 2 "TrySail.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=(1<<8);

struct Node
{
    int m[2];
};

int inq[maxn+5][maxn+5];
queue <Node> Q[2];

class TrySail
{
    public:
    int get(vector <int> strength)
    {
        int cnt=0;

        Node tmp;
        for (int i=0;i<=1;++i)
        {
            tmp.m[i]=0;
        }
        Q[cnt].push(tmp);

        memset(inq,-1,sizeof(inq));

        int all=0;
        for (int i=0;i<strength.size();++i)
        {
            all^=strength[i];

            queue <Node>& Q1=Q[cnt];
            queue <Node>& Q2=Q[cnt^1];
            while (!Q1.empty())
            {
                Node tmp=Q1.front();
                Q1.pop();

                for (int j=0;j<=1;++j)
                {
                    tmp.m[j]^=strength[i];
                    if (inq[tmp.m[0]][tmp.m[1]]!=i)
                    {
                        inq[tmp.m[0]][tmp.m[1]]=i;
                        Q2.push(tmp);
                    }
                    tmp.m[j]^=strength[i];
                }
                if (inq[tmp.m[0]][tmp.m[1]]!=i)
                {
                    inq[tmp.m[0]][tmp.m[1]]=i;
                    Q2.push(tmp);
                }
            }
            cnt^=1;
        }

        int ans=0;
        while (!Q[cnt].empty())
        {
            Node now=Q[cnt].front();
            Q[cnt].pop();
            ans=max(ans,now.m[0]+now.m[1]+(all^(now.m[0])^(now.m[1])));
        }
        return ans;
    }
};

#ifdef ex
int main()
{
    #ifdef ex
    freopen ("in.txt","r",stdin);
    #endif
}
#endif
*/
