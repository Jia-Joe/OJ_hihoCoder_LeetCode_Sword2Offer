class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string ret;
        vector<string> v;
        for (int i = 0; i < numbers.size(); ++i){
            stringstream ss;
            ss << numbers[i];
            string s = ss.str();
            v.push_back(s);
        }
        sort(v.begin(), v.end(), [](string a, string b){return a+b< b+a; });
        for (int i = 0; i < numbers.size(); ++i)
            ret += v[i];
        return ret;
    }
};