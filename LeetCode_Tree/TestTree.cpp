[1,2,2,3,3,3,3,4,4,4,4,4,4,null,null,5,5]
[1,2,3,4,5,6,7,8,9,10,11,12,13,null,null,14,15]
[10,6,16,4,8,13,null,1,5]
/**
Iterator:L173
Serialize and Deserialize:L297
**/
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
#define M 12
#define N 105

typedef unsigned int uint;
typedef long long LL;

int dp[N], dq[N], n;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

void BTPdfs(vector<int> &v, vector<string> &vs, TreeNode* r){
	if (!r) return;
	v.push_back(r->val);
	if (!r->left&&!r->right){
		string re;
		for (int i = 0; i < v.size(); i++){
			stringstream ss;
			ss << v[i];
			string st = ss.str();
			re.append(st);
			if (i != v.size() - 1)
				re.append("->");
		}
		vs.push_back(re);
	}
	if (r->left){		
		BTPdfs(v,vs,r->left);
	}
	if (r->right){
		BTPdfs(v, vs, r->right);
	}
	v.pop_back();
	return;
}

vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> vs;
	vector<int> v;
	BTPdfs(v, vs, root);
	return vs;
}

void getbk(unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* r){
	if (r->left){
		mp[r->left] = r;
		getbk(mp, r->left);
	}	
	if (r->right){
		mp[r->right] = r;
		getbk(mp, r->right);
	}
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root) return 0;
	unordered_map<TreeNode*, TreeNode*> mp;
	mp[root] = 0;
	vector<TreeNode*> vp, vq;
	vp.push_back(p); vq.push_back(q);
	TreeNode* t = p;
	getbk(mp, root);
	while (mp[t]){
		t = mp[t];
		vp.push_back(t); cout << t->val<<" ";
	}
	t = q;
	while (mp[t]){
		t = mp[t];
		vq.push_back(t); cout << t->val<<"-";
	}
	int i = vp.size() - 1, j = vq.size() - 1;
	for (; vp[i] == vq[j]; i--, j--){
		if (i == 0) return vp[0];
		if (j == 0) return vq[0];
	}cout << vp[i+1]->val;
	return vp[i+1];
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if (!root) return 0;
	if (root == p || root == q) return root;
	if (!root->left) return lowestCommonAncestor(root->right, p, q);
	if (!root->right) return lowestCommonAncestor(root->left, p, q);
	if (p->val <= root->left->val&&q->val <= root->left->val)
		return lowestCommonAncestor(root->left, p, q);
	if (p->val >= root->left->val&&q->val >= root->left->val)
		return lowestCommonAncestor(root->right, p, q);
	return root;
}
int main(){
	freopen("t1.txt", "r", stdin);


	//freopen("t11.txt", "w", stdout);
	TreeNode *tr1 = new TreeNode(1), *tr2 = new TreeNode(2), *tr3 = new TreeNode(3), *tr4 = new TreeNode(4), *tr5 = new TreeNode(5);
	TreeNode *tr6 = new TreeNode(6), *tr7 = new TreeNode(7), *tr8 = new TreeNode(8), *tr9 = new TreeNode(9), *tr10 = new TreeNode(10);
	tr1->left = tr2; tr1->right = tr3;
	tr2->left = tr4; 
	tr2->right = tr5;
	tr3->left = tr6;

	lowestCommonAncestor(tr1, tr4, tr4);

	return 0;
}