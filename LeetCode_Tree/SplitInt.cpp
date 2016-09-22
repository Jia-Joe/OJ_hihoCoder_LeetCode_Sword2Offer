int atoi(string s){
	stringstream ss;
	ss << s;
	int a;
	ss >> a;
	return a;
}
string atoi(int a){
	stringstream ss;
	ss << a;
	string s = ss.str();
	return s;
}
int mySplit(const string &src, const string &sp, vector<string> &res){
	if (src.size() == 0) return 0;
	size_t po = 0, pn = 0;//oldPos,newPos
	string t;
	int cnt = 0;
	while (1){
		pn = src.find(sp, po);
		if (pn != string::npos){
			t = src.substr(po, pn - po);
			res.push_back(t);
			po = pn + sp.size();
			cnt++;
		}
		else if (po <= src.size()){
			t = src.substr(po);
			res.push_back(t);
			cnt++; break;
		}
		else break;
	}
	return cnt;
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
				res.push_back(-1);
			else
				res.push_back(atoi(t));
			po = pn + sp.size();
			cnt++;
		}
		else if (po <= src.size()){
			t = src.substr(po);
			if (t[0] == 'n')
				res.push_back(-1);
			else
				res.push_back(atoi(t));
			cnt++; break;
		}
		else break;
	}
	return cnt;
}