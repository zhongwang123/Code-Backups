//****************************************************************************************************************//
//Source: http://acm.hdu.edu.cn/showproblem.php?pid=5787
//Description: K-wolf数定义为10进制下连续k个数码都不相同的数，求[L,R]中K-wolf数的数量
//Note:注意前导零
//Category:数位DP

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

const int maxn=1e4;

LL L,R;
int K;
int cur=0;
LL dp[20][maxn+5][5][2];
int vis[20][maxn+5][5][2];
int trans[maxn+5][5];
int bit[20];

void Trans()
{
    vector <int> v;
    for (int i=0;i<=maxn;++i)
    {
        for (int k=0;k<=3;++k)
        {
            v.clear();
            int tmp=i;
            for (int j=1;j<=k+1;++j)
            {
                v.push_back(tmp%10);
                tmp/=10;
            }

            trans[i][k]=0;
            for (int j=v.size()-2;j>=0;--j)
            {
                trans[i][k]=trans[i][k]*10+v[j];
            }
            //printf("trans[%d][%d]=%d\n",i,k,trans[i][k]);
        }
    }
}

LL DP(int pos,int s,int num,bool allzero,bool f)
{
    LL& ans=dp[pos][s][num][f];
    int& Vis=vis[pos][s][num][f];

    if (ans!=-1 && Vis==cur) return ans;

    ans=0;
    Vis=cur;
    int End=f?bit[pos]:9;

    int Count[10];
    clr(Count,0);
    int tmp=s;
    if (num==K-1)
    {
        for (int i=1;i<=K-1;++i) //两种处理方式的区别在于前导零与否
        {
            Count[tmp%10]++;
            tmp/=10;
        }
    }
    else
    {
        while (tmp) //两种处理方式的区别在于前导零与否
        {
            Count[tmp%10]++;
            tmp/=10;
        }
    }

    if (pos==0)
    {
        for (int i=0;i<=End;++i)
        {
            if (Count[i]!=0) continue;
            else ++ans;
        }
        return ans;
    }

    for (int i=0;i<=End;++i)
    {
        if (Count[i]!=0) continue;
        if (num<K-1)
        {
            int p=s*10+i;
            bool zero=(allzero && i==0);
            ans+=DP(pos-1,p,num+(!zero),zero,(f && i==End));
        }
        else
        {
            int p=trans[s][K-2]*10+i;
            ans+=DP(pos-1,p,K-1,false,(f && i==End));
        }
    }

    return ans;
}

LL calc(LL x)
{
    if (x==0) return 1;

    int cnt=0;
    while (x)
    {
        bit[cnt]=x%10;
        x/=10;
        ++cnt;
    }

    ++cur;
    LL res=DP(cnt-1,0,0,true,true);
    return res;
}

void solve()
{
    LL ans=calc(R)-calc(L-1);
    printf("%I64d\n",ans);
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../1.txt","w",stdout);
	#endif

	Trans();
	clr(dp,-1);
	while (scanf("%I64d%I64d%d",&L,&R,&K)==3)
    {
        solve();
    }
}
