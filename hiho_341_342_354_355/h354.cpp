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
#define MA 504
#define KA 32
#define QA 12
#define mkp(A,B) make_pair((A),(B))
#define fi first 
#define se second 

#define pa pair<int, int>
typedef unsigned int uint;
typedef long long LL;
const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };
const int inf = 0x3f3f3f3f;

int X,Y,K,Q,xd[MA],yd[MA],re[QA];
pa kc[KA],hi,ho;
set<pa> sk;
queue<pa> qc;
bool mk[MA][MA], mv[MA][MA];
int dis[MA][MA];
class Edge{
public:
	int dis,x,y;
	Edge(int d, int x1, int y1) :dis(d), x(x1), y(y1){};
	bool operator< (const Edge &e1)const{
		return dis > e1.dis;
	}
};

bool ok1(int x, int y){
	return x > 0 && y > 0 && x <= X&&y <= Y&&!mk[y][x] && !mv[y][x];
}
bool ok2(int x, int y){
	return x > 0 && y > 0 && x <= X&&y <= Y&&!mk[y][x];
}
int dst(int x, int y, int i){
	if (i == 0) return xd[x];
	if (i == 1) return yd[y - 1];
	if (i == 2) return xd[x - 1];
	return yd[y];
}
void dijkstra1(int x, int y){
	priority_queue<Edge> pq;
	memset(mv, 0, sizeof mv);
	memset(dis, 0x3f, sizeof dis);
	dis[y][x] = 0;
	pq.push(Edge(0,x, y));
	while (!pq.empty()){
		Edge er = pq.top();
		int dr = er.dis, xr = er.x, yr = er.y;
		mv[yr][xr] = 1;
		pq.pop();
		FOI(4){
			int xn = xr + dx[i], yn = yr + dy[i];
			if (ok1(xn, yn)){
				int dn = dst(xr, yr, i);
				if (dr + dn < dis[yn][xn]){
					dis[yn][xn] = dr + dn;
					pq.push(Edge(dr + dn, xn, yn));
				}									
			}
		}	
		//cout << pq.size() << endl;;
	}
}
void dijkstra2(int x, int y){
	priority_queue<Edge> pq;
	memset(dis, 0x3f, sizeof dis);
	dis[y][x] = 0;
	pq.push(Edge(0, x, y));
	while (!pq.empty()){
		Edge er = pq.top();
		int dr = er.dis, xr = er.x, yr = er.y;
		pq.pop();
		if (dr != dis[yr][xr]) continue;
		FOI(4){
			int xn = xr + dx[i], yn = yr + dy[i];
			if (ok2(xn, yn)){
				int dn = dst(xr, yr, i);
				if (dr + dn < dis[yn][xn]){
					dis[yn][xn] = dr + dn;
					pq.push(Edge(dr + dn, xn, yn));
				}
			}
		}
		//cout << pq.size() << endl;;
	}
}
int main(){
	ios::sync_with_stdio(false);
	freopen("t1.txt", "r", stdin);
	//freopen("t11.txt", "w", stdout);
	cin >> Y >> X;
	int idn = 0;
	FOI(Y - 1){
		cin >> yd[i + 1];
	}
	FOI(X - 1){
		cin >> xd[i + 1];
	}
	cin >> K;
	FOI(K){
		cin >> kc[i].se >> kc[i].fi;
		mk[kc[i].se][kc[i].fi] = 1;
		sk.insert(kc[i]);
	}
	cin >> Q;
	FOI(Q){
		cin >> hi.se >> hi.fi >> ho.se >> ho.fi;
		dijkstra2(hi.fi, hi.se);
		if (dis[ho.se][ho.fi] == inf) cout << -1 << endl;
		else cout << dis[ho.se][ho.fi] << endl;
	}
	//FOI(Y + 1){
	//	FO(j,X + 1){
	//		cout << dis[i][j] << "  ";
	//	}
	//	cout << endl;
	//}
	return 0;
}
//Edge *e1 = new Edge(1, mkp(1, 2), mkp(1, 2), 1), *e2 = new Edge(10, mkp(1, 2), mkp(1, 2), 1);
//Edge ex(1, mkp(1, 2), mkp(1, 2), 1), ey(10, mkp(1, 2), mkp(1, 2), 1);
//cout << (*e1 < *e2) << ( ex< ey);
//FOI(Q){
//	int re = inf;
//	priority_queue<Edge> pq;
//	memset(mk, 0, sizeof(mk));
//	memset(dis, 0x3f, sizeof(dis));
//	FO(j, K){
//		mk[kc[j].fi][kc[j].se] = 1;
//	}
//	qc.push(hi[i]);
//	mk[hi[i].fi][hi[i].se] = 1;
//	dis[hi[i].fi][hi[i].se] = 0;
//	while (!qc.empty()){
//		pa nw = qc.front(); qc.pop();
//		FO(k, 4){
//			int xo = nw.first, xn = xo + dx[k], yo = nw.second, yn = yo + dy[k];
//			if (xn > 0 && xn <= X&&yn > 0 && yn <= Y&&!mk[xn][yn]){
//				mk[xn][yn] = true;
//				qc.push(mkp(xn, yn));
//				int fr = dis[xo][yo];
//				if (dx[k] == 1)
//					dis[xn][yn] = fr + xd[xn - 1];
//				else if (dx[k] == -1)
//					dis[xn][yn] = fr + xd[xn];
//				else if (dy[k] == 1)
//					dis[xn][yn] = fr + yd[yn - 1];
//				else
//					dis[xn][yn] = fr + yd[yn];
//				printf("--%d--(%d,%d)--%d-->(%d,%d)\n", fr, xo, yo, dis[xn][yn], xn, yn);
//			}
//		}
//	}
//
//	if (re == inf) cout << -1 << endl;
//	else cout << re << endl;
//}