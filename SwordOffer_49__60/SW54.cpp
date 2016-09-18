class Solution
{
public:
	unordered_map<char, int> mp;
	vector<int> v;
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (mp.find(ch) == mp.end())
			mp[ch] = 1;
		else mp[ch]++;
		v.push_back(ch);
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++){
			if (mp[*it] == 1)
				return *it;
		}
		return '#';
	}
};