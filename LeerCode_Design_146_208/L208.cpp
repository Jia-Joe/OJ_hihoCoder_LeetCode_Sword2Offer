class TrieNode {
public:
	// Initialize your data structure here.
	char data;
	bool isword;
	TrieNode *child[26];

	TrieNode():data(0),isword(false) {		
		for (int i = 0; i < 26; i++)
			child[i] = NULL;		
	}
	TrieNode(char a) :data(a), isword(false) {
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
	}
	
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		int sz = word.size();
		TrieNode *pt = root;
		
		for (int i = 0 ; i < sz; i++){
			int ix = word[i] - 'a';
			if (!pt->child[ix]){
				pt->child[ix] = new TrieNode(word[i]);
			}
			pt = pt->child[ix];
			if (i == sz - 1)
				pt->isword = true;
		}

	}

	// Returns if the word is in the trie.
	bool search(string word) {
		int sz = word.size();
		bool ret = true;
		TrieNode *pt = root;
		for (int i = 0; i < sz; i++){
			int ix = word[i] - 'a';
			if (!pt->child[ix]){
				ret = false;
				break;
			}
			else
				pt=pt->child[ix];
			if (i == sz - 1 && !pt->isword) ret = false;
		}

		return ret;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		int sz = prefix.size();
		bool ret = true;
		TrieNode *pt = root;
		for (int i = 0; i < sz; i++){
			int ix = prefix[i] - 'a';
			if (!pt->child[ix]){
				ret = false;
				break;
			}
			else
				pt=pt->child[ix];
		}

		return ret;
	}

private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");