//****************************************************************************************************************//
//Source:
//Description:给定数n，求将n的左边i位取反后的结果
//Note: i从1开始计数
//Category:

//****************************************************************************************************************//

#include <bits/stdc++.h>
using namespace std;

int bitManipulation3(int n, int i) {
    return n^=((int)((1LL<<i)-1))<<(32-i);//注意(1<<32)==0，因为溢出，要先用1LL然后强行截断为int的位数得到-1
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation3(n, i) << endl;
	}
	return 0;
}
