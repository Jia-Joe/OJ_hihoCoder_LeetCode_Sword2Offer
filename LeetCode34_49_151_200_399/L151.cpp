    void reverseWords(string &s) {
    	int sz = s.size();
    	if (!sz) return;
    	int k = 0;
    	while (k < sz&&s[k] == ' ') k++;
    	s.erase(0, k);
    	sz = s.size();
    	for (auto it = s.begin(); it != s.end();){
    		if (*it == ' '&&(it + 1) !=s.end()&& *(it + 1) == ' ') 
    			it = s.erase(it);
    		else it++;
    	}
    	sz = s.size();
    	for (int i = sz - 1; i >= 0; i--){
    		if (s[i] == ' ') s.erase(i, 1);
    		else break;
    	}
    	sz = s.size();
    	for (int i = 0, j = 0; j<sz; j++){
    		if (s[j] == ' ' || j == sz - 1){
    			int p1 = i, p2 = j == sz - 1 ? j : j - 1;
    			while (p1 < p2)
    				swap(s[p1++], s[p2--]);
    			i = j + 1;
    		}
    	}
    	for (int i = 0, j = sz - 1; i < j;){
    		swap(s[i++], s[j--]);
    	}
    }