#pragma once

#include <vector>
#include <string.h>
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

#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define M 102

struct cor
{
	int x, y, z;
	cor(int a, int b, int c) :x(a), y(b), z(c){};
	cor(){};
};

static int id[M*M*M], sz[M*M*M], MM = M*M, MMM = MM*M, TH = MM*(M - 1);
static bool b[M*M*M], zm[M*M*M], v[M*M*M], out, flag;
static cor c[M*M*M];

inline int ti(int x, int y, int z)
{
	return x + y*M + z*MM;
}

bool connect(int x, int y, int z)
{
	if (z == 1) return true;
	return b[ti(x + 1, y, z)] || b[ti(x - 1, y, z)] || b[ti(x, y + 1, z)] || b[ti(x, y - 1, z)] || b[ti(x, y, z + 1)] || b[ti(x, y, z - 1)];
}
void visit(int &w, int next)
{
	if (next == 1) w += MM;
	if (next == 2) w += 1;
	if (next == 3) w -= 1;
	if (next == 4) w += M;
	if (next == 5) w -= M;
	if (next == 6) w -= MM;
}

int find(int p)
{
	while (p != id[p])
	{
		//id[p] = id[id[p]]; //Path compression
		p = id[p];
	}
	return p;
}
void unionPQ(int p, int q)
{
	if (p>TH) zm[p] = true;
	if (q>TH) zm[q] = true;
	int pRoot = find(p), qRoot = find(q);
	if (pRoot == qRoot)
		return;
	if (sz[pRoot] < sz[qRoot])
	{
		id[pRoot] = qRoot;
		sz[qRoot] += sz[pRoot];
		zm[qRoot] = zm[qRoot] || zm[p] || zm[q];
	}
	else
	{
		id[qRoot] = pRoot;
		sz[pRoot] += sz[qRoot];
		zm[pRoot] = zm[pRoot] || zm[p] || zm[q];
	}

}

void dfs(int w)
{
	//if (w>TH) zm[w] = true;
	v[w] = true;
	for (int i = 1; i < 7; i++)
	{
		int wt = w;;
		visit(wt, i);
		if (wt < MMM && !v[wt] && !b[wt])
		{
			//if (wt>TH) zm[wt] = true;
			unionPQ(w, wt);
			dfs(wt);
		}
	}
}


int main(void)
{
	//freopen("q4.txt", "r", stdin);
	int T, N, x, y, z;
	cor tcor;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int w = 0, nn = N;
		out = true;
		FOI(MMM){ sz[i] = 1; id[i] = i; }
		memset(b, 0, MMM*sizeof(bool));
		memset(zm, 0, MMM*sizeof(bool));
		memset(c, 0, MMM*sizeof(cor));
		memset(v, 0, MMM*sizeof(bool));
		;
		FO(i, M)
			FO(k, M)
			b[ti(k, i, 0)] = true;

		while (nn--)
		{
			scanf("%d %d %d", &x, &y, &z);
			c[w++] = cor(x, y, z);
			if (!connect(x, y, z))
			{
				out = false;
			}
			b[ti(x, y, z)] = true;
		}
		if (!out){ cout << "No" << endl; continue; }
		//Build UF with empty cubes
		for (int i = 0; i < MMM; i++)
		{
			if (b[i] || v[i]) continue;
			dfs(i);
		}
		//Dismantle the cubes and increase the edges of UF
		bool flagn = true;
		for (int k = N - 1; k >= 0; k--)
		{
			int iw = ti(c[k].x, c[k].y, c[k].z);
			b[iw] = false;
			for (int i = 1; i < 7; i++)
			{
				int iwt = iw;;
				visit(iwt, i);
				if (!b[iwt])
				{
					unionPQ(iwt, iw);
				}
			}
			if (!zm[find(iw)]) { flagn = false; break; }
		}
		if (flagn)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}

