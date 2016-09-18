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
#include<functional> 
#include <unordered_map>
#include <unordered_set>
using namespace std;

class IndexedPQ{
public:
	IndexedPQ(){
		v.push_back(INT_MIN);
		id.push_back(-1);
		cnt = 0;
	}
	IndexedPQ(vector<int> vin){
		v.push_back(INT_MIN);
		id.push_back(-1);
		cnt = 0;
		for (; cnt<vin.size(); cnt++){
			v.push_back(vin[cnt]);
			id.push_back(cnt+1);
		}
		N = vin.size();
		for (int i = N; i > 0; --i)
			sink(i);
	}
	void push(int a){
		v.push_back(a);
		++N;
		++cnt;
		swim(N);
	}
	void pop(){
		if (N == 0) return;
		swap(v[1], v[N]);
		v.erase(v.begin() + N);
		--N;
		sink(1);	
	}
	int top(){
		if (N == 0) return -1;
		return v[1];
	}

	bool empty() { return N == 0; }
	int size(){ return N; }
	void print();
private:
	vector<int> h;   //h.size()==N+1
	vector<int> id;  //id.size() won't decrease. id[h[i]]=i 
	vector<int> v;	 //v is the priority if i
	int N;
	int cnt;
	void swim(int ix){
		while (ix != 1 && v[ix] < v[ix >> 1]){
			swap(v[ix], v[ix >> 1]);
			ix >>= 1;
		}
	}
	void sink(int ix){
		int iy = 0;
		while (ix << 1< N - 2){
			iy = v[ix << 1]<v[(ix << 1) + 1] ? ix << 1 : (ix << 1) + 1;
			if (v[ix]>v[iy]){
				swap(v[ix], v[iy]);
				ix = iy;
			}
			else break;
		}
		if (ix << 1 == N&&v[ix] > v[N]) swap(v[ix], v[N]);
		else if (ix << 1 == N - 1 && v[ix] > min(v[N], v[N - 1])){
			if (v[N] == min(v[N], v[N - 1])) swap(v[ix], v[N]);
			else swap(v[ix], v[N - 1]);
		}

	}
};
int main(){
	vector<int> v(1);
	vector<int> x1 = { 223, 12, 221, 33, 632, 7, 8, 921, 1 }, x = {};
	IndexedPQ pq(x1);
	cout << pq.size() << endl;
	pq.print();
	for (int i = 0; i < 9; i++){
		cout << pq.top() << " ";
		pq.pop();
		//pq.print();
	}
	
	return 0;
}

class PQ{
public:
	PQ(){
		v.push_back(INT_MIN);
	}
	PQ(vector<int> vin){
		v.push_back(INT_MIN);
		for (int x : vin) v.push_back(x);
		N = vin.size();
		for (int i = N; i > 0; --i)
			sink(i);
	}
	void push(int a){
		v.push_back(a);
		++N;
		swim(N);
	}
	void pop(){
		if (N == 0) return;
		swap(v[1], v[N]);
		v.erase(v.begin() + N);
		--N;
		sink(1);
	}
	int top(){
		if (N == 0) return -1;
		return v[1];
	}

	bool empty() { return N == 0; }
	int size(){ return N; }

private:
	vector<int> v;
	int N;
	void swim(int ix){
		while (ix != 1 && v[ix] < v[ix >> 1]){
			swap(v[ix], v[ix >> 1]);
			ix >>= 1;
		}
	}
	void sink(int ix){
		int iy = 0;
		while (ix << 1< N - 2){
			iy = v[ix << 1]<v[(ix << 1) + 1] ? ix << 1 : (ix << 1) + 1;
			if (v[ix]>v[iy]){
				swap(v[ix], v[iy]);
				ix = iy;
			}
			else break;
		}
		if (ix << 1 == N&&v[ix] > v[N]) swap(v[ix], v[N]);
		else if (ix << 1 == N - 1 && v[ix] > min(v[N], v[N - 1])){
			if (v[N] == min(v[N], v[N - 1])) swap(v[ix], v[N]);
			else swap(v[ix], v[N - 1]);
		}

	}
};
void IndexedPQ::print() {
	//void print(vector<int> v) {
	int n = v.size() - 1;
	if (n < 1) return;
	int Depth = log((double)n) / log(2.0) + 1;
	stack<int> dis;
	dis.push(1);
	int tmp = 0;
	for (int i = 1; i<Depth - 1; i++)
	{
		dis.push(2 * dis.top());
	}
	for (int i = 1; i<Depth; i++)
	{
		int d = dis.top();
		dis.pop();
		for (int j = 0; j<d - 1; j++)
		{
			cout << '\t';
		}
		int k = (int)pow(2.0, i - 1);
		for (int j = 0; j<k; j++)
		{
			cout << '\t' << v[k + j];
			if (j != k - 1)
			{
				for (int m = 0; m<2 * d - 1; m++)
				{
					cout << '	';
				}
			}
		}
		cout << endl;
	}
	for (int i = (int)pow(2.0, Depth - 1); i<n + 1; i++)
	{
		cout << "    " << v[i] << '\t';
	}
	cout << endl;
}