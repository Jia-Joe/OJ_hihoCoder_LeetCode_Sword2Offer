class Solution {
public:
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
};