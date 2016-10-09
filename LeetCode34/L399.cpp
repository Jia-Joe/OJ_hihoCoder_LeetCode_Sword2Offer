class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
    	int sz = values.size(), qsz = queries.size(),cnt=0;
    	vector<double> re(qsz);
    	unordered_map<string, int> m;
    	for (int i = 0; i < sz; i++){
    		string s1 = equations[i].first, s2 = equations[i].second;
    		if (m.find(s1) == m.end()) m[s1] = cnt++;
    		if (m.find(s2) == m.end()) m[s2] = cnt++;
    	}
    	vector<vector< pair<int, double> >> g(cnt);
    	for (int i = 0; i < sz; i++){
    		string s1 = equations[i].first, s2 = equations[i].second;
    		g[m[s1]].push_back(make_pair(m[s2], values[i]));
    		g[m[s2]].push_back(make_pair(m[s1], 1.0/values[i]));
    	}
    	for (int i = 0; i < qsz; i++){
    		string q1 = queries[i].first, q2 = queries[i].second;
    		if (m.find(q1) == m.end()) { re[i] = -1.0; continue; }
    		if (m.find(q2) == m.end()) { re[i] = -1.0; continue; }
    		int p1 = m[q1], p2 = m[q2];
    		if (q1 == q2) { re[i] = 1.0; continue; }
    		double ri = 1.0;
    		stack<pair<int, double>> st;
    		vector<pair<int, double>> dfstree(cnt, make_pair(-1, 1.0));
    		vector<bool> mk(cnt, 0);
    		st.push(make_pair(p1, 1.0));
    		while (!st.empty()){
    			int pt = st.top().first;
    			if (pt == p2) break;
    			double dt = st.top().second;
    			st.pop();
    			//dfstree[pt] = make_pair(-1, 1.0);
    
    			mk[pt] = 1;
    			for (int j = 0; j < g[pt].size(); j++){
    				int t1 = g[pt][j].first;
    				if (!mk[t1]){
    					st.push(g[pt][j]);
    					dfstree[t1] = make_pair(pt, g[pt][j].second);
    				}					
    			}
    
    		}
    		if (st.empty()) { re[i] = -1.0; continue; }
    		else{
    			int ix = p2;
    			while (dfstree[ix].first!=-1){
    				ri *= dfstree[ix].second;
    				ix = dfstree[ix].first;
    			}
    			re[i] = ri;
    		}
    	}
    	return re;
    }
};

////Non-recursive DFS
//#include
//#include
//#define max_node 20
//#define max 20000
//using namespace std;
//
//int map[max_node][max_node];
//
//void dfs(int start, int n)
//{
//	stack s;
//	int i, vis[max_node], ctop;
//	memset(vis, 0, sizeof(vis));
//	vis[start] = 1;
//	printf("%d ", start);
//	for (i = 1; i <= n; i++)
//	if (!vis[i] && map[i][start] == 1)
//	{
//		vis[i] = 1;
//		s.push(i);
//	}
//	while (!s.empty())
//	{
//		ctop = s.top();
//		vis[ctop] = 1;
//		printf("%d ", s.top());
//		s.pop();
//		for (i = 1; i <= n; i++)
//		if (!vis[i] && map[i][ctop] == 1)
//		{
//			vis[i] = 1;
//			s.push(i);
//		}
//	}
//}
//
//int main()
//{
//	int s, t, n;
//	scanf("%d", &n);
//	memset(map, max, sizeof(map));
//	while (1)
//	{
//		scanf("%d %d", &s, &t);
//		if (s == 0) break;
//		map[s][t] = map[t][s] = 1;
//	}
//	dfs(1, n);
//	return 0;
//}