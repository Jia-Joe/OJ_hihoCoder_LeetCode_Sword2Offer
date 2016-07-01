//unordered_map + list
class LRUCache{
public:
	list<pair<int, int>> page;
	unordered_map<int, list<pair<int, int>>::iterator> mp;
	typedef unordered_map<int, list<pair<int, int>>::iterator>::iterator mpit;
	int cap, sz;
	LRUCache(int capacity) {
		cap = capacity;
		sz = 0;
	}

	int get(int key) {
		mpit mit = mp.find(key);
		if (mit == mp.end())
			return -1;
		int ans = mit->second->second;
		page.erase(mit->second);
		page.push_front(make_pair(key, ans));
		mp[key] = page.begin();
		return ans;
	}

	void set(int key, int value) {
		mpit mit = mp.find(key);		
		if (mit == mp.end()){
			if (sz == cap){
				mp.erase(page.back().first);
				page.pop_back();
			}
			else
				sz++;
		}
		else{
			page.erase(mit->second);
		}
		page.push_front(make_pair(key, value));
		mp[key] = page.begin();
	}
};

//TLE Solution:
class LRUCache{
public:
	list<pair<int,int>> page;
	int cap, sz;
	LRUCache(int capacity) {
		cap = capacity;
		sz = 1;
	}

	int get(int key) {
		list<pair<int, int>>::iterator it=
			find_if(page.begin(), page.end(), [key](pair<int, int> pa){ return pa.first == key; });
		if (it == page.end())
			return -1;
		page.push_front(make_pair(key, it->second));
		int ans = it->second;
		page.erase(it);
		return ans;
	}

	void set(int key, int value) {
		list<pair<int, int>>::iterator it =
			find_if(page.begin(), page.end(), [key](pair<int, int> pa){ return pa.first == key; });
		page.push_front(make_pair(key, value));
		if (it == page.end()){			
			if (sz > cap){
				page.pop_back();
			}
			else
				sz++;
		}
		else{
			page.erase(it);
		}
	}
	
};