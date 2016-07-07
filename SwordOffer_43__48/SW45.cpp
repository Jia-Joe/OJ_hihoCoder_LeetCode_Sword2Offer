class Solution {
public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.size() != 5) return false;
        vector<int> v=numbers;
        int w = count(v.begin(), v.end(), 0);
        for (vector<int>::iterator it = v.begin(); it != v.end();){
            if (*it == 0) it = v.erase(it);
            else it++;
        }
        if (v.size() < 2) return true;
        sort(v.begin(), v.end());
        if (unique(v.begin(), v.end()) != v.end()) return false;	
        return v[v.size()-1]-v[0]<5;
    }
};