int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size(), r = -1, g = 0;
	if (n == 1) return gas[0] < cost[0] ? -1 : 0;
	vector<int> st,dif(n);
	for (int i = 0; i < n; i++){
		dif[i] = gas[i] - cost[i];
		if (dif[i] >= 0)
			st.push_back(i);
	}
	for (int w : st){
		g = dif[w];
		int cur = (w + 1) % n;
		while (g >= 0 && cur != w){
			g = g + dif[cur];
			cur = cur + 1; 
			if (cur == n) cur = 0;
		}
		if (g >= 0 && cur == w){
			//cout << "====" << w;
			r = w;
			break;
		}
	}
	return r;
}

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i=0,left=0,beg=0,total=0;
        while(i<gas.size()){
            left+=gas[i]-cost[i];
            total+=gas[i]-cost[i];
            if(left<0){
                beg=i+1;
                left=0;
            }
            i++;
        }
        if(total>=0) return beg;
        else return -1;    
    }
};