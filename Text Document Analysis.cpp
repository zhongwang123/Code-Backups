//****************************************************************************************************************//
//Source:http://codeforces.com/contest/723/problem/B
//Description:
//Note:
//Category:

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

char s[300];
int len;

vector <int> ans;
vector <int> L;
vector <int> R;

int solve(int l,int r)
{
    //printf("%d %d\n",l,r);
    int res=0;
    int cnt=0;
    for (int i=l;i<=r;++i)
    {
        if (s[i]=='_')
        {
            if (cnt!=0) ++res;
            cnt=0;
        }
        else
        {
            ++cnt;
        }
    }
    if (cnt!=0) ++res;
    return res;
}

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d",&len);
	scanf("%s",s);

	int cnt=0;
	ans.push_back(cnt);

	bool f=false;
	for (int i=0;i<=len-1;++i)
    {
        if (s[i]=='_' || s[i]=='(' || s[i]==')')
        {
            if (!f) ans.push_back(cnt);
            cnt=0;

            if (s[i]=='(') f=true;
            else if (s[i]==')') f=false;
        }
        else
        {
            ++cnt;
        }
    }
    if (cnt!=0) ans.push_back(cnt);           //注意此处，忽略最后的单词导致了一次WA

    int MAX=*max_element(ans.begin(),ans.end());

    for (int i=0;i<=len-1;++i)
    {
        if (s[i]=='(')
        {
            L.push_back(i);
        }
        else if (s[i]==')')
        {
            R.push_back(i);
        }
    }

    int num=0;
    for (int i=0;i<L.size();++i)
    {
        int l=L[i]+1;
        int r=R[i]-1;
        num+=solve(l,r);
    }
    printf("%d %d\n",MAX,num);
}
