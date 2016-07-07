//XOR

class Solution {
public:
    void FindNumsAppearOnce(vector<int> &data, int* num1, int *num2) {
        int sz = data.size();
        if (sz < 2) return;
        unordered_map<int,int> st;
        for (int i = 0; i < sz; ++i){
            auto it = st.find(data[i]);
            if (it == st.end())
                st[data[i]]=i;
            else
                st.erase(it);
        }
        *num1 = data[st.begin()->second];
        *num2 = data[(++st.begin())->second];
    }
};