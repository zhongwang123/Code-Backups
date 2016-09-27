//****************************************************************************************************************//
//Source: http://codeforces.com/problemset/problem/713/B
//Description: 交互式题目，给定两个不互相嵌套的矩形，每次可以询问一个矩形范围，OJ回答该范围内有几个完整的矩形，最后确定两个矩形的左下，右上顶点
//Note: 注意二分时，初始l,r的值
//Category:二分

//****************************************************************************************************************//

#include<bits/stdc++.h>

#define clr(x,y) memset((x),(y),sizeof(x))

using namespace std;
typedef long long LL;

struct Rect
{
    int x1,y1,x2,y2;
};

int check(int X1,int Y1,int X2,int Y2)
{
    int x;
    printf("? %d %d %d %d\n",X1,Y1,X2,Y2);
    fflush(stdout);
    scanf("%d",&x);
    return x;
}

Rect getRect (int X1,int Y1,int X2,int Y2) //
{
    //printf("%d %d %d %d\n",X1,Y1,X2,Y2);
    Rect res;

    int l=X1;
    int r=X2+1;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (check(mid,Y1,X2,Y2)<=0) r=mid;
        else l=mid;
    }
    res.x1=l;

    l=X1-1;
    r=X2;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (check(X1,Y1,mid,Y2)<=0) l=mid;
        else r=mid;
    }
    res.x2=r;

    l=Y1;
    r=Y2+1;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (check(X1,mid,X2,Y2)<=0) r=mid;
        else l=mid;
    }
    res.y1=l;

    l=Y1-1;
    r=Y2;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (check(X1,Y1,X2,mid)<=0) l=mid;
        else r=mid;
    }
    res.y2=r;

    return res;
}

int n;

int main(void)
{
	#ifdef ex
	//freopen ("../in.txt","r",stdin);
	//freopen ("../out.txt","w",stdout);
	#endif

	scanf("%d",&n);

	int l,r;

	l=0;
	r=n;
	while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (check(1,1,mid,n)<=0) l=mid;
        else r=mid;
    }

    if (check(1,1,r,n)==1 && check(r+1,1,n,n)==1) //矩形不互相嵌套，所以矩形要么X轴存在重合部分，要么y轴存在重合部分，要不完全分离
    {
        Rect ans1=getRect(1,1,r,n);
        Rect ans2=getRect(r+1,1,n,n);
        printf("! %d %d %d %d %d %d %d %d\n",ans1.x1,ans1.y1,ans1.x2,ans1.y2,ans2.x1,ans2.y1,ans2.x2,ans2.y2);
        fflush(stdout);
        return 0;
    }

	//我们确定重合的部分之后，就将两个矩形彻底分开，接下来就是已知区域内确定矩形位置的问题了
    l=0;
    r=n;
    while (r-l>1)
    {
        int mid=(l+r)>>1;
        if (check(1,1,n,mid)<=0) l=mid;
        else r=mid;
    }

    Rect ans1=getRect(1,1,n,r);
    Rect ans2=getRect(1,r+1,n,n);
    printf("! %d %d %d %d %d %d %d %d\n",ans1.x1,ans1.y1,ans1.x2,ans1.y2,ans2.x1,ans2.y1,ans2.x2,ans2.y2);
    fflush(stdout);


}
