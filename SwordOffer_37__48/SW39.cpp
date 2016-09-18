class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot)
    {
        if (pRoot == NULL) return true;
        vector<int> dp;
        stack<TreeNode*> st;
        unordered_map<TreeNode*, int> mp;
        st.push(pRoot);
        mp[pRoot] = 1;
        if (!pRoot->left || !pRoot->right) dp.push_back(1);
        while (!st.empty()) {
            TreeNode* tp = st.top();
            st.pop();
            if (!tp->left&&!tp->right){
                dp.push_back(mp[tp]);
            }

            if (tp->left){
                st.push(tp->left);
                mp[tp->left] = mp[tp] + 1;
            }
            if (tp->right){
                st.push(tp->right);
                mp[tp->right] = mp[tp] + 1;
            }
        }
        return *max_element(dp.begin(), dp.end()) - *min_element(dp.begin(), dp.end())<2;
    }
};