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

#define FOR(I,K,N) for(int (I)=(K);(I)<(N);(I)++)
#define FO(I,N) for(int (I)=0;(I)<(N);(I)++)
#define FOI(N) for(int i=0;i<(N);i++)
#define M 12
#define N 58

typedef unsigned int uint;

int x[N], nn;

#define _CRT_SECURE_NO_WARNINGS
bool ok(vector<vector<int> > array, int target, int xp, int xq, int yp, int yq){
	if (xp > xq) return false;
	int mx = (xp + xq) >> 1, ip = yp, iq = yq, my = (ip + iq) >> 1;
	while (ip <= iq){
		my = (ip + iq) >> 1;
		if (target == array[my][mx]) return true;
		else if (target > array[my][mx])
			ip = my + 1;
		else
			iq = my - 1;
	}
	return ok(array, target, xp, mx - 1, my, yq) || ok(array, target, mx + 1, xq, yp, my);
}
bool Find(vector<vector<int> > array, int target) {
	int ry = array.size();
	if (ry == 0) return false;
	int rx = array[0].size();
	return ok(array, target, 0, rx-1, 0, ry-1);
}

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

double Power(double base, int exponent) {
	if (base == 0){
		if (exponent>0) return 0;
		else if (exponent==0)return NAN;
		else return INFINITY;
	}
	if (base == 1) return 1;
	int exp = abs(exponent);
	double ret=1,big=base;
	while (exp){
		if(exp & 0x00000001)
			ret*=big;
		exp >>= 1;
		big = big*big;
	}
	return exponent>=0? ret:1/ret;
}
void reOrderArray(vector<int> &array) {
	list <int> nd;
	bool fi = true;
	list<int>::iterator it=nd.begin();
	int sz = array.size();
	for (int i = 0; i < sz; i++){
		if (array[i] % 2 == 0){
			nd.push_back(array[i]);
		}
		else{
			if (fi){
				fi = false;
				it = nd.insert(nd.begin(), array[i]);
			}
			else it=nd.insert(++it, array[i]);
		}
	}
	it = nd.begin();
	for (int i = 0; i < sz; i++){
		array[i] = *it;
		++it;
		cout << array[i];
	}
}
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	if (pHead1 == NULL) return pHead2;
	if (pHead2 == NULL) return pHead1;
	ListNode *tp, *ret = pHead1->val < pHead2->val ? pHead1 : pHead2, *p1 = ret, *p2 = ret == pHead1 ? pHead2 : pHead1, *pre = p1;
	p1 = p1->next;
	while (p1&&p2){
		while (p1&&p1->val < p2->val){
			p1 = p1->next;
			pre = pre->next;
		}
		if (p1 == NULL) break;

		tp = p2;
		p2 = p2->next;
		tp->next = p1;
		pre->next = tp;
		pre = p1;
		p1 = p1->next;

	}
	if (p2){
		pre->next = p2;
	}
	return ret;
}
//pre = tp;
//cout << "p1:";
//ListNode *rett = ret;
//while (rett){
//	cout << rett->val;
//	rett = rett->next;
//}
//cout << endl;



vector<int> PrintFromTopToBottom(TreeNode *root) {
	vector<int> v;
	if (root == NULL) return v;
	queue<TreeNode*> qu;
	qu.push(root);
	v.push_back(root->val);
	while (!qu.empty()){
		TreeNode* t = qu.front();
		qu.pop();
		if (t->left) { 
			qu.push(t->left); 
			v.push_back(t->left->val);
		}
		if (t->right) { 
			qu.push(t->right);
			v.push_back(t->right->val);

		}
	}
	return v;
}



bool ok(vector<int> &v, int p, int q){
	if (p >= q) return true;
	int i=p;
	while (i < q&&v[i] < v[q]) i++;
	for (int j = i ; j <= q;j++)
		if (v[j] < v[q]) 
			return false;
	return ok(v, p, i-1) && ok(v, i, q - 1);
}

bool VerifySquenceOfBST(vector<int> sequence) {
	int sz = sequence.size();
	if (sz == 0) return false;
	return ok(sequence, 0, sz-1);
}


void dfs(TreeNode* r, vector<vector<int> > &v, stack<int> &st,int &s, int exp){
	st.push(r->val);
	s += r->val;
	if (r->left == NULL&&r->right == NULL&&s==exp){
		stack<int> sb; vector<int> vb;
		while (!st.empty()){
			sb.push(st.top());
			st.pop();
		}
		while (!sb.empty()){
			vb.push_back(sb.top());
			st.push(sb.top());
			sb.pop();
		}
		v.push_back(vb);
	}
	if (r->left){
		dfs(r->left, v, st, s, exp);
		st.pop();
		s -= r->left->val;
	}
	if (r->right){
		dfs(r->right, v, st, s, exp);
		st.pop();
		s -= r->right->val;
	}
	return;
}

vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
	vector<vector<int> > ret;
	if (root == NULL) return ret;
	stack<int> st;
	int s = 0;
	dfs(root, ret, st, s, expectNumber);
	//for (vector<int> v : ret){
	//	for (int x : v)
	//		cout << x << "  ";
	//	cout << endl;
	//}
	return ret;
}

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* Clone(RandomListNode* pHead)
{
	if (pHead == NULL) return NULL;
	unordered_map<RandomListNode*, int> mp;
	RandomListNode *hd = pHead;
	int n = 0;
	while (hd){
		mp[hd] = n++;
		hd = hd->next;
	}
	RandomListNode** cp = new RandomListNode*[n];
	cp[0] = new RandomListNode(pHead->label);
	hd = pHead->next;
	for (int i = 1; i < n; i++){
		cp[i] = new RandomListNode(hd->label);
		cp[i - 1]->next=cp[i];
		hd = hd->next;
	}
	hd = pHead;
	for (int i = 0; i < n; i++){
		if (hd->random)
			cp[i]->random = cp[mp[hd->random]];
		hd = hd->next;
	}	
	return cp[0];
}

TreeNode* convert(TreeNode* r)
{
	if (r == NULL) return NULL;
	if (r->left == NULL&&r->right == NULL){
		r->left = r; r->right = r;
		return r;
	}
	TreeNode *lt = convert(r->left), *rt = convert(r->right);
	if (lt == NULL)
		lt = r;
	else{
		lt->left->right = r;
		r->left = lt->left;
		r->right = rt ? rt : lt;
	}
	if (rt == NULL)
		lt->left = r;
	else{
		lt->left = rt->left;
		rt->left->right = lt;
		rt->left = r;
	}
	
	return lt;
}
TreeNode* Convert(TreeNode* pRootOfTree){
	TreeNode* ans = convert(pRootOfTree);
	//No cycle
	if (ans){
		ans->left->right = NULL;
		ans->left = NULL;
	}
	return ans;
}
//lt->left->right = r;
//r->left = lt->left;
//r->right = rt;
//rt->left = r;
//lt->left = rt->left;
//rt->right = lt;
vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int> > ans;
	vector<int> v;
	if (pRoot == NULL) return ans;
	queue<pair<TreeNode*,int> > qu;
	qu.push(make_pair(pRoot,0));
	v.push_back(pRoot->val);
	int x = -1;
	while (!qu.empty()){
		TreeNode* t = qu.front().first;
		int c = qu.front().second;
		qu.pop();
		if (c > x){
			ans.push_back(v);
			v.clear();
			++x;
		}
		if (t->left) {
			qu.push(make_pair(t->left, c + 1));
			v.push_back(t->left->val);
		}
		if (t->right) {
			qu.push(make_pair(t->right, c + 1));
			v.push_back(t->right->val);

		}
	}
	return ans;
}
void swap(string &s, int a, int b){
	char t = s[a]; s[a] = s[b]; s[b] = t;
}
void perm(vector<string> &v, string &s, int p, int q){
	if (p >= q) {
		v.push_back(s);
		return;
	}
	unordered_set<char> us;
	for (int i = p; i <= q; ++i){
		if (us.find(s[i]) == us.end()){
			us.insert(s[i]);
			swap(s, i, p);
			perm(v, s, p + 1, q);
			swap(s, i, p);
		}
	}
}
vector<string> Permutation(string str) {
	vector<string> ret;
	if (str.size() == 0) return ret;
	perm(ret, str, 0, str.size() - 1);
	sort(ret.begin(), ret.end());
	//vector<string>::iterator it = unique(ret.begin(), ret.end());
	//ret.erase(it, ret.end());
	return ret;
}

int FindGreatestSumOfSubArray(vector<int> v) {
	if (v.size()==0) return 0;
	int ma = INT_MIN;
	for (int i = 0, su = 0; i < v.size(); ++i){
		su = max(su + v[i], v[i]);
		ma = max(ma, su);
	}
	return ma;
}
int NumberOf1Between1AndN_Solution(int n)
{
	int ans = 0;
	for (long long i = 1; i <= n; i *= 10){
		int q = n / i, r = n%i;
		if (q%10==1)
			ans += (q / 10 )*i+r+1;
		else if (q%10==0)
			ans += (q / 10)*i;
		else
			ans += (q / 10 + 1)*i;
	}
	return ans;
}
string PrintMinNumber(vector<int> numbers) {
	string ret;
	vector<string> v;
	for (int i = 0; i < numbers.size(); ++i){
		stringstream ss;
		ss << numbers[i];
		string s = ss.str();
		v.push_back(s);
	}
	sort(v.begin(), v.end(), [](string a, string b){return a+b< b+a; });
	for (int i = 0; i < numbers.size(); ++i)
		ret += v[i];
	return ret;
}
int GetUglyNumber_Solution(int index) {
	int sz = log2(INT_MAX) + 1;
	priority_queue<int, vector<int>, greater<int> > v;
	long long x = 1, y = 1, z = 1;
	for (int i = 0; i < sz; ++i){
		if (i == 0) x = 1;
		else x <<= 1;
		if (x>INT_MAX) break;
		for (int j = 0; j < sz; ++j){
			if (j == 0) y = 1;
			else y = (y << 1) + y;
			if (x*y>INT_MAX) break;
			for (int k = 0; k < sz; ++k){
				if (k == 0) z = 1;
				else z = (z << 2) + z;
				long long t = x*y*z;
				if (t>INT_MAX) break;
				else
					v.push(t);
			}
		}
	}
	while (--index)
		v.pop();
	return v.top();
}

void mergesort(vector<int> &v, int p, int q, int &t){
	if (p == q) return;
	int m = (p + q) >> 1,i,j;
	mergesort(v, p, m,t);
	mergesort(v, m + 1, q,t);
	vector<int> vb;
	int w = 0;
	for (i = p, j = m + 1; i <= m&&j <= q;){
		if (v[i] <= v[j]){
			vb.push_back(v[i]); ++i;
			t += w;
		}
		else{
			vb.push_back(v[j]); ++j;
			++w;
		}
	}
	if (i > m)while (j <= q) vb.push_back(v[j++]);
	else if (j > q){
		while (i <= m){
			cout << "vi:" << v[i] << endl;
			vb.push_back(v[i++]);
			t += w;
		}
	}
	for (int i = p; i <= q; ++i)
		v[i] = vb[i - p];
}
int InversePairs(vector<int> data) {
	if (data.size() == 0) return 0;
	int ans = 0;
	mergesort(data, 0, data.size() - 1, ans);
	return ans;
}
int GetNumberOfK(vector<int> data, int k) {
	int ans = 0, sz = data.size(), p = 0,q=sz-1,m=0;
	if (sz == 0) return 0;
	while (p <= q){
		m = (p + q) >> 1;
		if (data[m] == k) {
			ans++; break;
		}
		else if (data[m] < k) p = m + 1;
		else q = m - 1;
	}
	if (p>q) return 0;
	int t = m;
	while (--t >= 0 && data[t] == k) ans++;
	t = m;
	while (++t < sz && data[t] == k) ans++;
	return ans;
}
int TreeDepth(TreeNode* pRoot)
{
	if (pRoot == NULL) return 0;
	return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
}
bool IsBalanced_Solution(TreeNode* pRoot)
{
	if (!pRoot) return true;
	return abs(TreeDepth(pRoot->left) - TreeDepth(pRoot->right))<2;
}
//bool cmp(pair<TreeNode*, int> m1, pair<TreeNode*, int> m2){
//	return m1.second < m2.second;
//}
//bool IsBalanced_Solution(TreeNode* pRoot)
//{
//	vector<int> dp ;
//	if (pRoot == NULL) return 0;
//	stack<TreeNode*> st;
//	unordered_map<TreeNode*,int> mp;
//	st.push(pRoot); 
//	mp[pRoot] = 1;
//	while (!st.empty()) {
//		TreeNode* tp = st.top();
//		st.pop();
//		if (tp->left){
//			st.push(tp->left);
//			mp[tp->left] = mp[tp] + 1;
//		}
//		if (tp->right){
//			st.push(tp->right);
//			mp[tp->right] = mp[tp] + 1;
//		}
//	}
//	return max_element(mp.begin(), mp.end(),cmp)->second - min_element(mp.begin(), mp.end(),cmp)->second<2;
//}
bool myIsBalanced_Solution(TreeNode* pRoot)
{
	if (pRoot == NULL) return 0;
	vector<int> dp;
	stack<TreeNode*> st;
	unordered_map<TreeNode*, int> mp;
	st.push(pRoot);
	mp[pRoot] = 1;
	if (!pRoot->left || !pRoot->right) dp.push_back(1);
	while (!st.empty()) {
		TreeNode* tp = st.top();
		st.pop();
		if (!tp->left&&!tp->right){
			dp.push_back(mp[tp]);
		}

		if (tp->left){
			st.push(tp->left);
			mp[tp->left] = mp[tp] + 1;
		}
		if (tp->right){
			st.push(tp->right);
			mp[tp->right] = mp[tp] + 1;
		}
	}
	return *max_element(dp.begin(), dp.end()) - *min_element(dp.begin(), dp.end())<2;
}
void FindNumsAppearOnce(vector<int> &data, int* num1, int *num2) {
	int sz = data.size();
	if (sz < 2) return;
	unordered_map<int,int> st;
	for (int i = 0; i < sz; ++i){
		auto it = st.find(data[i]);
		if (it == st.end())
			st[data[i]]=i;
		else
			st.erase(it);
	}
	num1 = &data[st.begin()->second];
	num2 = &data[(++st.begin())->second];
}

vector<vector<int> > FindContinuousSequence(int sum) {
	vector<vector<int> > res;
	sum <<= 1;
	for (int i = 2; i * i <= sum; ++i) if (sum % i == 0){
		int j = sum / i, t = (j - i + 1);
		if (!(t & 1)){
			res.push_back(vector<int>());
			vector<int>& v = res[res.size() - 1];
			t >>= 1;
			for (int a = t; a <= j - t; ++a) v.push_back(a);
		}
	}
	reverse(res.begin(), res.end());
	//for (int i = 0, j = int(res.size()) - 1; i < j; ++i, --j) swap(res[i], res[j]);
	return res;
}

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	vector<int> ret;
	int sz = array.size(), i = 0, j = sz - 1;
	int di[3] = { 0, 1, 0 }, dj[3] = { 0, 0, -1 };
	if (sz < 2) return ret;
	while (i < j){
		int su = array[i] + array[j];
		if (su == sum){
			ret.push_back(array[i]);
			ret.push_back(array[j]);
			return ret;
		}
		else if (su < sum) ++i;
		else --j;
	}

	return ret;
}
string ReverseSentence(string str) {
	int sz = str.size();
	if (sz == 0) return "";
	string ret;
	int i = sz - 2, j = sz - 1;
	while (i >= 0){
		while (i >= 0 && str[i] != ' ')--i;
		ret += str.substr(i + 1, j - i);
		if (i >= 0) ret += ' ';
		--i;
		j = i;
	}
	return ret;
}

bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5) return false;
	vector<int> v=numbers;
	int w = count(v.begin(), v.end(), 0);
	for (vector<int>::iterator it = v.begin(); it != v.end();){
		if (*it == 0) it = v.erase(it);
		else it++;
	}
	if (v.size() < 2) return true;
	sort(v.begin(), v.end());
	if (unique(v.begin(), v.end()) != v.end()) return false;	
	return v[v.size()-1]-v[0]<5;
}

int StrToInt(string str) {
	for (int i = 0; i < str.size(); ++i){
		if (!(str[i] >= '0'&&str[i] <= '9' || str[i] == '+' || str[i] == '-' || str[i] == '.' || str[i] == ' '))
			return 0;
	}
	long long sum = 0, cnt = 0, i = 0;
	int sz = str.size();
	bool zerobegin = true, neg = false;
	while (str[i] == ' ') i++;
	if (str[i] == '+') i++;
	else if (str[i] == '-') { i++; neg = true; }

	for (; i<sz&&str[i] >= '0'&&str[i] <= '9'; i++){
		if (str[i] == '.') break;
		if (zerobegin&&str[i] == '0')
			continue;
		else
			zerobegin = false;
		sum = (sum << 3) + (sum << 1) + str[i] - 48;
		cnt++;
	}


	if (neg){
		if (-sum<INT_MIN || cnt>10)
			return INT_MIN;
		else
			return -sum;
	}
	else{
		if (sum>INT_MAX || cnt>10)
			return INT_MAX;
		else
			return sum;
	}
}
//int LastRemaining_Solution(unsigned int n, unsigned int m)
//{
//	if (n < 1 || m < 1) return 0;
//	list<int> lt;
//	for (int i = 0; i < n; ++i)
//		lt.push_back(i);
//	list<int>::iterator it = lt.begin();
//	int sz = n,i=0;
//	while (lt.size()>1){
//		if (i%m == m - 1) {
//			i = 0;
//			it = lt.erase(it);
//			for (int x : lt)
//				cout << x << " ";
//			cout << endl;
//		}			
//		else {
//			i++;
//			it++;
//		}		
//		if (it == lt.end())
//			it = lt.begin();
//
//	}
//	return *lt.begin();
//}
int LastRemaining_Solution(unsigned int n, unsigned int m)
{
	if (n < 1 || m < 1) return 0;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i]=i;
	int sz = n, i = 0;
	while (sz>1){
		//for (int x = 0; x < sz; x++)
		//	cout << a[x] <<" " ;
		//cout << endl;
		int k = (i + (m-1)%sz) % sz;
		for (int j = k; j < sz-1 ; ++j)
			a[j] = a[j + 1];
		i = k;
		sz--;
	}
	return a[0];
}
//0 1 3 4 5 6 7 8 9
//0 1 3 4 6 7 8 9
//0 1 3 4 6 7 9
//0 3 4 6 7 9
//0 3 4 7 9
//3 4 7 9
//3 4 9
//3 9
//3
//ret3
//int Add1(int num1, int num2)
//{
//	int ret=0,i=31,c=0,d=0;
//	for(int i=0;i<31;++i){
//		int a = num1 & 1, b = num2 & 1;
//		if (a == 0 && b == 0) { d = c; c = 0; }
//		else if (a == 1 && b == 1) { d = c; c = 1; }
//		else{ d = !c; }
//		ret += d << i;
//		num1 >>= 1; num2 >>= 1;
//	}
//	return ret;
//}
int Add(int a, int b)
{
	int c = a&b, d = a^b;
	while (c)
	{
		int cx = c << 1;
		c = d&cx;
		d = d^cx;
	}
	return d;
}
bool oksym(TreeNode *tr1, TreeNode *tr2){
	if (!tr1&&!tr2) return true;
	if (!tr1 || !tr2) return false;
	return tr1->val == tr2->val&&oksym(tr1->left, tr2->right) && oksym(tr1->right, tr2->left);
}
bool isSymmetrical(TreeNode* pRoot)
{
	if (!pRoot) return true;
	return oksym(pRoot->left, pRoot->right);
}
bool duplicate(int numbers[], int length, int* duplication) {
	if (length < 2) return false;
	int *a = new int[length];
	for (int i = 0; i < length; ++i) a[i] = 0;
	for (int i = 0; i < length; ++i){
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
		else{
			a[numbers[i]]++;
			if (a[numbers[i]]>1){
				*duplication = numbers[i];
				return true;
			}
		}			
	}
	numbers[0] += 100;
	for (int i = 0; i < length; ++i) cout<<a[i]<<endl;
	return false;
}
vector<int> multiply(const vector<int>& A) {
	int sz = A.size();
	vector<int> v;
	int *a = new int[sz], *b = new int[sz];
	if (sz < 2) return v;
	int x = 1, y = 1;
	for (int i = 0; i < sz; ++i){
		x *= A[i];
		y *= A[sz - 1 - i];
		a[i] = x;
		b[sz - 1 - i] = y;
	}
	v.push_back(b[1]);
	for (int i = 1; i < sz-1; ++i){
		v.push_back(a[i-1]*b[i+1]);
	}
	v.push_back(a[sz - 2]);
	return v;
}

bool okm(char* s, char* p, int s1, int s2, int p1, int p2){
	if (p1 == p2) return s1 == s2 && (p[p1] == s[s1] || p[p1] == '.');
	if (s1>s2){
		if (p1 > p2) return true;
		if (p[p1] == '*'&&p[p2] != '*') return false;
		for (int i = p2; i>0; i--){
			if (p[i] != '*'&&p[i - 1] != '*') return false;
		}
		return true;
	}
	//if (s1 == s2){
	//	if (p1 > p2) return false;
	//	for (int i = p2; i>0; i--){
	//		if (p[i] != '*'&&p[i - 1] != '*') return false;
	//	}
	//	if (s1 == s2)
	//	for (int i = p1; i <= p2; i++){
	//		if (p[i] == s[i]) return true;;
	//	}
	//	return true;
	//}
	if (p1 > p2) return false;
	if (p[p2] == '.'){
		return okm(s, p, s1, s2 - 1, p1, p2 - 1);
	}
	else if (p[p2] == '*'){
		if ((p[p2 - 1] == s[s2] || p[p2 - 1] == '.'))
			return okm(s, p, s1, s2 - 1, p1, p2) || okm(s, p, s1, s2 - 1, p1, p2 - 2) || okm(s, p, s1, s2, p1, p2 - 2);
		else if (p[p2 - 1] == '*')
			return okm(s, p, s1, s2 - 1, p1, p2) || okm(s, p, s1, s2 - 1, p1, p2 - 1) || okm(s, p, s1, s2, p1, p2 - 1);
		else
			return okm(s, p, s1, s2, p1, p2 - 2);
	}
	else
		return s[s2] == p[p2] && okm(s, p, s1, s2 - 1, p1, p2 - 1);
}
bool match(char* str, char* pattern)
{
	return okm(str,pattern,0,strlen(str)-1, 0, strlen(pattern)-1);
}

bool isInt(char* s, int &fi, int q, bool &dot){
	if (fi > q) return false;
	for (; fi <= q; fi++){
		if (s[fi] == ' ') continue;
		if (s[fi] == '.') dot = true;
		if (!(s[fi] >= '0'&&s[fi] <= '9') && s[fi] != '+'&&s[fi] != '-'&&s[fi] != '.') {
			return false;
		}
		else  break;
	}
	if (fi+1 > q && (s[fi] < '0'||s[fi] > '9')) return false;
	fi++;
	return true;
}
bool isNumeric(char* string)
{
	int sz = strlen(string);
	if (sz == 0) return false;
	int fi=0;
	char *s = string;
	bool dot = false, ep = false;
	if (!isInt(s, fi, sz - 1,dot)) return false;
	for (; fi < sz; fi++){
		if (dot){
			if (!(s[fi] >= '0'&&s[fi] <= '9') && s[fi] != 'e'&&s[fi] != 'E') return false;
		}			
		else{
			if (!(s[fi] >= '0'&&s[fi] <= '9') && s[fi] != 'e'&&s[fi] != 'E' && s[fi] != '.') return false;
		}			
		if (s[fi] == '.') {
			dot = true;
		}
		if (s[fi] == 'e' || s[fi] == 'E') {
			ep = true; break;
		}
	}
	dot = false;
	if (ep) {
		fi++;
		if(!isInt(s, fi, sz - 1,dot)) return false;
		if (dot == true) return false;
		for (; fi <sz ; fi++){
			if (!(s[fi] >= '0'&&s[fi] <= '9')) return false;
		}
	}
	return true;
}
class Solution1
{
public:
	unordered_map<char, int> mp;
	vector<int> v;
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (mp.find(ch) == mp.end())
			mp[ch] = 1;
		else mp[ch]++;
		v.push_back(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
			if (mp[*it] == 1)
				return *it;
		}
		return '#';
	}
};
ListNode* deleteDuplication(ListNode* pHead)
{
	if (pHead == NULL || pHead->next == NULL) return pHead;
	bool fi = 1;
	ListNode* p1 = pHead, *p2 = pHead->next, *pf = p1,  *pr = NULL,*pt=p1;
	if (p1->val != p2->val){ pr = p1; fi = 0; }
	else{
		for (pt = p1; pt->next->next != NULL; pt = pt->next){
			if (pt->val != pt->next->val&&pt->next->val != pt->next->next->val){
				pr = pt->next; fi = 0; break;
			}
		}
	}
	if (fi){
		if (pt->val == pt->next->val) return pr;
		else return pt->next;
	}
	pf = pr;
	ListNode* prf = pr;
	for (pt = pr; pt->next->next != NULL; pt = pt->next){
		if (pt->val != pt->next->val&&pt->next->val != pt->next->next->val){
			pf->next = pt->next;
			pf = pt->next;
		}
	}
	if (pt->val != pt->next->val){
		pf->next = pt->next;
	}
	else pf->next = NULL;
	return pr;
}
ListNode* redeleteDuplication(ListNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	if (pHead != NULL && pHead->next == NULL)
		return pHead;

	ListNode* current;

	if (pHead->next->val == pHead->val){
		current = pHead->next->next;
		while (current != NULL && current->val == pHead->val)
			current = current->next;
		return deleteDuplication(current);
	}

	else {
		current = pHead->next;
		pHead->next = deleteDuplication(current);
		return pHead;
	}
}

struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode* GetNext(TreeLinkNode* pNode)
{
	if (pNode == NULL) return NULL;
	TreeLinkNode* pr = pNode, *rg = NULL;
	while (pr->next){
		if (pr->right&&pr->right!=rg) break;
		if (pr->next){
			rg = pr;
			pr = pr->next;
			if (pr->left&&pr->left == rg)
				return pr;
		}
	}
	if (pr->next==NULL&&pr->right == rg||pr->right==NULL)
		return NULL;
	pr = pr->right;
	while (pr->left)
		pr = pr->left;
	return pr;
}

class Solution {
public:
	vector<int> v;
	int sz=0;
	void Insert(int num)
	{
		v.push_back(num);
		sz++;
		for (int i = sz - 2; i >= 0; --i){
			if (v[i] > v[i + 1]) swap(v[i], v[i + 1]);
			else break;
		}
	}

	double GetMedian()
	{
		if (sz & 1 == 1) return v[sz >> 1];
		else return (v[sz >> 1] + v[(sz >> 1) - 1]) / 2.0;
	}

};
bool okblock(int rows, int cols,int k){
	int cp = 0;
	while (rows){
		cp += rows % 10;
		rows /= 10;
	}
	while (cols){
		cp += cols % 10;
		cols /= 10;
	}
	return cp <= k;
}
int movingCount(int threshold, int rows, int cols)
{
	if (rows < 1 || cols < 1 || threshold < 1) return 0;
	int ans = 0, dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
	stack<pair<int, int>> st;
	vector<vector<bool> > vb(rows, vector<bool>(cols,false));
	st.push(make_pair(0, 0));
	vb[0][0] = true;
	while (!st.empty()){
		int y = st.top().first, x = st.top().second;
		st.pop();
		ans++;
		cout << y << "," << x << endl;
		for (int i = 0; i < 4; ++i){
			int yi = y + dy[i], xi = x + dx[i];
			if (yi>-1 && yi<rows&&xi>-1&&xi<cols&&!vb[yi][xi]&&okblock(yi,xi,threshold)){
				vb[yi][xi] = true;
				st.push(make_pair(yi, xi));
			}
		}		
	}
	return ans;
}
int main(void)
{
	TreeNode *tr = new TreeNode(101), *tr5 = new TreeNode(5), *tr3 = new TreeNode(3), *tr1 = new TreeNode(1), *tr8 = new TreeNode(8), *tr2 = new TreeNode(2);
	tr->left = tr5; tr->right = tr8; tr5->left = tr3; tr5->right = tr1; tr1->right = tr2;
	tr8->left = tr2; tr8->right = tr; tr2->left = tr1; tr2->right = tr3; tr1->right = tr5;
	int x[9] = { 5, 2, 3, 4, 1, 6, 7, 0, 8 };
	Solution sl;
	for (int a : x){
		sl.Insert(a);
		cout << sl.GetMedian() << "  ";
	}
	cout << movingCount(1,1,1) << endl;
	vector<vector<int> > vvx(3, vector<int>(4, 317));
	for (vector<int> v : vvx){
		for (int x : v)
			cout << x << " ";
		cout << endl;
	}
	cout << okblock(123, 124, 3);
	int c = 0;
	int a[5] = { 2, 1, 3, 1, 4 },*pq=&c;
	vector<int> y=multiply({ 1, 2, 3 });
	char *s[20] = { "123.45e+6","-.123", "5e2", "+100", "-123", "-1E-16", "3.1416", "12e", "1a3.14", "1.2.3", "+-5", "12e+4.3" };
	for (int i = 0; i < 11; i++){
		puts(s[i]);
		if (isNumeric(s[i])) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	unordered_map<int, int> mp;
	mp[15];
	ListNode  p1(1), p2(1), p3(3), p5(5), p7(7), p9(7), *pr;
	p1.next = &p2;
	p2.next = &p3;
	p3.next = &p5;
	p5.next = &p7;
	p7.next = &p9;
	pr=deleteDuplication(&p1);
	while (pr){
		cout << pr->val << "-->";
		pr = pr->next;
	}

	vector<int> v = { 2, 4, 3, 6, 3, 2, 5, 5 };//{ 6, -3, -2, 7, -5, 1, 3, 2 };
	sort(v.begin(), v.end());
	cout<< GetNumberOfK(v, 8) << GetNumberOfK({ 8 }, 8) << endl;;
	vector<vector<int> > vv = FindContinuousSequence(9);
	for (vector<int> v : vv){
		for (int x : v)
			cout << x << " ";
		cout << endl;
	}
	string ss = "I am a student.";
	cout << IsContinuous({0,0,1,2,0}) << endl;

	cout << FindGreatestSumOfSubArray({0}) << endl;;
	//vector<string> vss = Permutation(s);
	//for (string ss : vss)
	//	cout << ss << endl;
	//int mx = 0x80000000;
	
	//TreeNode *tr = new TreeNode(2), *tr5 = new TreeNode(5), *tr3 = new TreeNode(3), *tr1 = new TreeNode(1), *tr8 = new TreeNode(8), *tr2 = new TreeNode(2), *tr4 = new TreeNode(4), *tr6 = new TreeNode(6);
	//tr->left = tr5; tr->right = tr8; tr5->left = tr3; tr5->right = tr1; tr1->right = tr2;
	//tr1->left = tr2; tr1->right = tr3; tr2->left = tr4; tr2->right = tr5; tr5->left = tr6;
	//cout << IsBalanced_Solution(tr1) << endl;

	//FindPath(tr, 10);
	stack<int> st;
	st.push(2);
	cout << st.top() << endl;
	vector<vector<int> > vo = Print(tr);
	for (vector<int> v : vo){
		for (int x : v)
			cout << x << " ";
		cout << endl;
	}

	TreeNode *trq = new TreeNode(1), *trw = new TreeNode(5);
	tr->right = tr1; tr1->right = tr3; tr3->right= tr8;
	trq->left = trw;
	TreeNode *hh=Convert(tr),*pp=hh->right;
	cout << hh->val << "  ";
	while (pp != NULL){
		cout << pp->val << "  ";
		pp = pp->right;
	}
	

	pr = Merge(&p1, &p2);
	while (pr->next){
		cout << pr->val;
		pr = pr->next;
	}
		


	//4 5 1 2 6 7 3 0
	vector<int>  vt = { -2, 0, 3, -5, 2, -1 }, v1 = { 1,2,3,4,5,6,7,8,9,10 },ve;//sumRange(0, 2), sumRange(2, 5), sumRange(0, 5), vv = { 3, 2, 4 }, vw = { 5, 75, 25 }, re(2), vs = { 2, 4, 6, 11, 15, 19 },
	vector<int>	vx1 = { 1, 2 }, vx2 = { 1, 2, 5 }, //p = twoSum(v, 6);
	vt1 = { 2, 7 }, vt2 = { 2, 11  };
	string s1 = "ab   +004500";
	string s2 = "abcdefg";
	vector<vector<int>> vm;
	vector<int> vc = v;
	sort(vc.begin(), vc.end());
	vc.push_back(999);
	vm.push_back(v);
	vm.push_back(v1);//4,8,6,12,16,14,10
	int **p=new int*[2];
	for (int i = 0; i < 2; i++){
		p[i] = new int[10];
	}
	FOI(2)
	for (int k = 0; k < 10; k++)
		p[i][k] = 10 * i + k;
	vector < vector<int> >mv0 = { { 1, 4 ,2, 5 } }; vector< vector<int> >mv1 = { { 1 }, { 2 }, { 4 }, { 5 } };
	vector < vector<int> >mvv = { { 1, 4, 7, 11, 15 }, { 2, 5, 8, 12, 19 } }, vr = { { 1, 2, 6 }, { 3, 6, 10 }, { 7, 11, 12 }, { 9, 12, 13 } };
	vector<int> vb = { 1, 3, 2, 6, 8, 9, 7, 5, 4 };
	return 0;
}