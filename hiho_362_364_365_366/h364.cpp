#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <list> 
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <utility>
#include <hash_set>
#include <sstream>
#include <functional> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define MA 2007
#define N 1005

typedef unsigned int uint;
typedef long long LL;

int n, m;
int w[N], p[N];
int wt[N], val[N];
LL u[MA][MA];
LL dp[N], dt[N], dp2[N][N];


vector<int> backpack2d(int W, int n, int wt[], int val[]){
	vector<int> ret;
	for (int i = 0; i < n; i++){
		for (int w = 0; w <= W; w++){
			if (w >= wt[i])
				dp2[i + 1][w] = max(dp2[i][w], dp2[i][w - wt[i]] + val[i]);
			else
				dp2[i + 1][w] = dp2[i][w];
		}
	}
	//return dp2[n][W];

	int ib = n, wb = W;
	//FOI(n+1){
	//	FO(j,W+1){
	//		cout << dp2[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	while (ib > 0 && wb > 0){
		while (wb > 0 && dp2[ib][wb] == dp2[ib][wb - 1]){
			wb--;
		}
		if (wb == 0) break;
		while (ib > 0 && dp2[ib][wb] == dp2[ib - 1][wb]){
			ib--;
		}
		if (ib == 0) break;
		//cout << ib - 1 << "  " << val[ib - 1]<<endl;
		ib--;
		wb -= wt[ib];
		ret.push_back(val[ib]);

	}
	return ret;
}


int backpack1v(int W, int n, int wt[], int val[]){
	for (int i = 0; i < n; i++){
		for (int w = W; w >= wt[i]; w--){
			dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
		}
	}
	return dp[W];

}
//int backpack2v(int W, int n, int wt[], int val[]){
//	for (int i = 0; i < n; i++){
//		for (int w = wt[i]; w <= W; w++){
//			dp[w] = max(dt[w], dt[w - wt[i]] + val[i]);
//		}
//		for (int w = 0; w <= W; w++) dt[w] = dp[w];
//	}
//
//	return dp[W];
//}
void change(LL w, LL p)
{
	for (int i = m; i >= w; i--)
	{
		dp[i] = max(dp[i], dp[i - w] + p);
	}
}
int main()
{
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	cin >> m >> n;
	FOI(n){
		scanf("%d %d", &wt[i], &val[i]);
	}
	int sum = 0;
	vector<int> vr=backpack2d(m, n, wt, val);
	for (int i = 0; i < vr.size(); i++){
		sum += vr[i];
	}
	cout << "sum " << sum << endl;
	cout << backpack1v(m, n, wt, val);
	//FOI(n){
	//	scanf("%d", &w[i]);
	//}
	//FOI(n){
	//	scanf("%d", &p[i]);
	//}
	memset(u, 0, sizeof(u));
	for (int i = 0; i<n; i++)
	{

		u[w[i]][p[i]]++;

	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 2005; i++)
	{
		for (int j = 0; j <= 2005; j++)
		{
			int tem = 1;
			while (u[i][j]>0)
			{
				LL num;
				if (u[i][j] >= tem) u[i][j] -= tem, num = tem;
				else num = u[i][j], u[i][j] = 0;
				tem *= 2;
				change(i*num, j*num);
			}
		}
	}
	double ret = dp[m];
	ret = 3.123;
	printf("%.1f", ret / 10);
	//cout << ret / 10 << endl;
	return 0;
}

#pragma once

#include <vector>
#include <string>
#include <string.h>
#include <list> 
#include <map>
#include <set>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <utility>
#include <hash_set>
#include <sstream>
#include <functional> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define MA 207
#define N 100005

typedef unsigned int uint;
typedef long long LL;
#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
int n, m;
LL w[N], p[N];
int wt[N], val[N];
LL u[MA][MA];
LL dp[N];


void change(LL w, LL p){
	for (int i = m; i >= w; i--){
		dp[i] = max(dp[i], dp[i - w] + p);
	}
}
int main()
{
	freopen("t1.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	memset(u, 0, sizeof(u));
	for (int i = 0; i<n; i++){
		int w, p;
		scanf("%d%d", &w, &p);
		u[w][p]++;
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			int tem = 1;
			while (u[i][j]>0)
			{
				int num;
				if (u[i][j] >= tem) u[i][j] -= tem, num = tem;
				else num = u[i][j], u[i][j] = 0;
				tem *= 2;
				change(i*num, j*num);
			}
		}
	}

	printf("%d\n", dp[m]);
	return 0;
}
//FOI(n + 1){
//	FO(j, n + 1){
//		cout << u[i][j] << " ";
//	}
//	cout << endl;
//}