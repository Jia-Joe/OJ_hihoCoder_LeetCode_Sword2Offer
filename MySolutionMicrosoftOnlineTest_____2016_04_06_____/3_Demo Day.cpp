#pragma once

#include <vector>
#include <string>
#include <list> 
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
#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define M 105
#define N 105

int m, n, out;
bool b[N][N];
int fd[N][N], fr[N][N];
char c[N][N];

inline int min(int x, int y)
{
	return x < y ? x : y;
}
int main(void)
{
	scanf("%d %d\n", &m, &n);

	FO(i, m)
	{
		FO(k, n)
		{
			scanf("%c", &c[i][k]);
			if (c[i][k] == 'b')
				b[i][k] = true;
		}
		getchar();
		b[i][n] = true;
	}
	FOI(n + 1)
		b[m][i] = true;

	int side = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (b[m - 1][i]){ side++; }
		fr[m - 1][i] = side;
		fd[m - 1][i] = side;
	}
	side = 0;
	for (int i = m - 1; i >= 0; i--)
	{
		if (b[i][n - 1]){ side++; }
		fr[i][n - 1] = side;
		fd[i][n - 1] = side;
	}
	//////////////////////
	/*
	|X|A|
	|B|C|
	*/
	for (int i = m - 2; i >= 0; i--)
	{
		for (int k = n - 2; k >= 0; k--)
		{
			int am = 99999, bm = 99999, add, cmp, findi = i, findk = k;
			int tmin = 0, minf = 99999, mind = 99999;
			for (int q = n - 1; q >= k + 1; q--)
			{
				tmin = 0;
				for (int w = k + 1; w<q; w++)
				{
					if (b[i][w])tmin++;
				}
				//cout << tmin << endl;
				if (b[i][q] && !b[i][q + 1]){ add = 2; }
				else if (!b[i][q] && b[i][q + 1]){ add = 0; }
				else add = 1;
				add += fd[i + 1][q];
				if (minf>tmin + add){ minf = tmin + add; }
			}

			for (int p = m - 1; p >= i + 1; p--)
			{
				tmin = 0;
				for (int w = i + 1; w < p; w++)
				{
					if (b[w][k])tmin++;
				}
				if (b[p][k] && !b[p + 1][k]){ add = 2; }
				else if (!b[p][k] && b[p + 1][k]){ add = 0; }
				else add = 1;
				add += fr[p][k + 1];
				if (mind>tmin + add){ mind = tmin + add; }
			}
			fr[i][k] = b[i][k + 1] ? min(minf, mind) : min(minf, mind + 1);
			fd[i][k] = b[i + 1][k] ? min(minf, mind) : min(minf + 1, mind);
			if (b[i][k])
			{
				fr[i][k]++;
				fd[i][k]++;
			}
		}
	}
	cout <<fr[0][0]<< endl;
	return 0;
}
