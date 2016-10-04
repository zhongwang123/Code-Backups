//****************************************************************************************************************//
//Source:http://codeforces.com/contest/723/problem/A
//Description: 
//Note:
//Category:

//****************************************************************************************************************//
#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

int main(void)
{
	#ifdef ex
	freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);

	int mi=min(min(a,b),c);
	int ma=max(max(a,b),c);

	printf("%d\n",ma-mi);
}
