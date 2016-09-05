class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        int szi = pushV.size(), szo = popV.size();
        if (szi != szo||szi==0) return false;
        unordered_map<int, int> mpi;
        for (int i = 0; i < szi; i++)
            mpi[pushV[i]] = i;
        int *v = new int[szi];
        for (int i = 0; i < szi; i++){
            if (mpi.find(popV[i]) == mpi.end())
                return false;
            v[i] = mpi[popV[i]];
        }
        
        if (szi < 3) return true;
        stack<int> st;
        for (int i = 0; i < szi; i++){
            if (st.empty() || v[i]>st.top()){
                st.push(v[i]);
            }
            else{
                int ma = st.top();
                st.pop();
                while (!st.empty() && v[i] < st.top()){
                    if (st.top() != --ma) return false;
                    st.pop();
                }
                if (v[i] != --ma) return false;
                st.push(v[i]);
            }
        }
        return true;
    }
};