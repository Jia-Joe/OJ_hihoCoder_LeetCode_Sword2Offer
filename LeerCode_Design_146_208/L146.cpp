class LRUCache{
//TLE
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
		else
			return it->second;
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