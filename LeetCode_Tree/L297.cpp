/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    int atoi(string s){
    	stringstream ss;
    	ss << s;
    	int a;
    	ss >> a;
    	return a;
    }
    string itoa(int a){
    	stringstream ss;
    	ss << a;
    	string s = ss.str();
    	return s;
    }
    int mySplitInt(const string &src, const string &sp, vector<int> &res){
    	if (src.size() == 0) return 0;
    	size_t po = 0, pn = 0;//oldPos,newPos
    	string t;
    	int cnt = 0;
    	while (1){
    		pn = src.find(sp, po);
    		if (pn != string::npos){
    			t = src.substr(po, pn - po);
    			if (t[0] == 'n')
    				res.push_back(INT_MAX);
    			else
    				res.push_back(atoi(t));
    			po = pn + sp.size();
    			cnt++;
    		}
    		else if (po <= src.size()){
    			t = src.substr(po);
    			if (t[0] == 'n')
    				res.push_back(INT_MAX);
    			else
    				res.push_back(atoi(t));
    			cnt++; break;
    		}
    		else break;
    	}
    	return cnt;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    	if (!root) return "[]";
    	string res = "[";
    	queue<TreeNode*> qu;
    	qu.push(root);
    	while (!qu.empty()){
    		int sz = qu.size();
    		for (int i = 0; i < sz; i++){
    			TreeNode* t = qu.front();
    			qu.pop();
    			if (t){
    				qu.push(t->left);
    				qu.push(t->right);			
    				res = res + itoa(t->val) + ",";
    			}
    			else{
    				res += "null,";
    			}					
    		}
    	}
    	int sz = res.size() - 2;
    	while (sz > 4 && res[sz] == 'l') sz -= 5;
    	res = res.substr(0, sz+1);
    	res += "]";
    	return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="[]") return NULL;
    	vector<int> v;
    	mySplitInt(data.substr(1, data.size() - 1), ",", v);
    	queue<TreeNode*> qu;
    	TreeNode *root = new TreeNode(v[0]);
    	qu.push(root);
    	int ix = 0, vz = v.size();
    	while (!qu.empty()){
    		int sz = qu.size();
    		for (int k = 0; k < sz; k++){
    			TreeNode **t = &qu.front();
    			if (ix + 1 < vz){
    				ix++;
    				if (v[ix] != INT_MAX){
    					(*t)->left = new TreeNode(v[ix]);
    					qu.push(((*t)->left));
    				}					
    			}
    			if (ix + 1 < vz){
    				ix++;
    				if (v[ix] != INT_MAX){
    					(*t)->right = new TreeNode(v[ix]);
    					qu.push((*t)->right);
    				}					
    			}
    			qu.pop();
    			if (ix >= vz-1) break;
    		}
    		if (ix >= vz-1) break;
    	}
    
    	return root;
    }
};
TreeNode* deserialize(string data) {
	vector<int> v;
	mySplitInt(data.substr(1, data.size() - 1), ",", v);
	if (v.size() == 0) return NULL;
	queue<TreeNode*> qu;
	TreeNode *root = new TreeNode(v[0]);
	qu.push(root);
	int ix = 0, vz = v.size();
	while (!qu.empty()){
		int sz = qu.size();
		for (int k = 0; k < sz; k++){
			TreeNode *t = qu.front();
			//TreeNode **t = &tr;
			qu.pop();
			if (ix + 1 < vz){
				ix++;
				if (v[ix] != INT_MAX){
					t->left = new TreeNode(v[ix]);
					qu.push((t->left));
				}					
			}
			if (ix + 1 < vz){
				ix++;
				if (v[ix] != INT_MAX){
					t->right = new TreeNode(v[ix]);
					qu.push(t->right);
				}					
			}
			if (ix >= vz-1) break;
		}
		if (ix >= vz-1) break;
	}

	return root;
}
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));