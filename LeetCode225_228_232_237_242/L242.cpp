class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        const char *ss=s.c_str(),*tt=t.c_str();
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(ss[i])==mp.end())
                mp[ss[i]]=1;
            else
                mp[ss[i]]++;
        }
        for(int i=0;i<s.size();i++){
            if(mp.find(tt[i])==mp.end())
                return false;
            mp[tt[i]]--;
            if(mp[tt[i]]<0) return false;
        }
        return true;
    }
    
};

//sort
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<char> vs,vt;
        int sz=s.size();
        for(int i=0;i<sz;i++){
            vs.push_back(s[i]);
            vt.push_back(t[i]);
        }
        sort(vs.begin(),vs.end());
        sort(vt.begin(),vt.end());
        for(int i=0;i<sz;i++){
            if(vs[i]!=vt[i])
                return false;
        }
        return true;
    }
    
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> letters(26, 0);
        for (int c : s) letters[c - 'a'] ++;
        for (int c : t) letters[c - 'a'] --;
        for (int n : letters) if (n != 0) return false;
        return true;
    }
};