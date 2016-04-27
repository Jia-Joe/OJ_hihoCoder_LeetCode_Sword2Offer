#include <vector>
#include <string>
#include <list> 
#include <map>
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iomanip>

using namespace std;
typedef map<int, int>::iterator p1;

#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define M 12

int a[1005],f[100],b[1005];

int main(void)
{
//	freopen("q1.txt", "r", stdin);
	int T, N, P, W, H;

	cin >> T;
	FO(tt, T)
	{
		int p=1;
		scanf("%d %d %d %d", &N, &P, &W, &H);
		FO(nn, N)
		{
			cin >> a[nn];
		}
		int x = 1;
		for (x = 1; x <= W && x <= H; ++x)
		{
			int sum = 0;
			int w = W / x, h = H / x;
				//break;
			FOI(N)
			{
				if (a[i] % w == 0)
					b[i] = a[i] / w;
				else
					b[i] = a[i] / w + 1;
				sum += b[i];
			}
			if (sum%h == 0)
				p = sum / h;
			else
				p = sum / h + 1;
			if (p > P)
				break;
		}
		f[tt] = --x;
	}
	FOI(T)
	{
		cout << f[i] << endl;
	}
//	fclose(stdin);
	system("pause");
	return 0;
}