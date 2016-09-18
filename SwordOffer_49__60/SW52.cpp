class Solution {
public:
bool okm(char* s, char* p, int s1, int s2, int p1, int p2){
	if (p1 == p2) return s1 == s2 && (p[p1] == s[s1] || p[p1] == '.');
	if (s1>s2){
		if (p1 > p2) return true;
		if (p[p1] == '*'&&p[p2] != '*') return false;
		for (int i = p2; i>0; i--){
			if (p[i] != '*'&&p[i - 1] != '*') return false;
		}
		return true;
	}
	if (p1 > p2) return false;
	if (p[p2] == '.'){
		return okm(s, p, s1, s2 - 1, p1, p2 - 1);
	}
	else if (p[p2] == '*'){
		if ((p[p2 - 1] == s[s2] || p[p2 - 1] == '.'))
			return okm(s, p, s1, s2 - 1, p1, p2) || okm(s, p, s1, s2 - 1, p1, p2 - 2) || okm(s, p, s1, s2, p1, p2 - 2);
		else if (p[p2 - 1] == '*')
			return okm(s, p, s1, s2 - 1, p1, p2) || okm(s, p, s1, s2 - 1, p1, p2 - 1) || okm(s, p, s1, s2, p1, p2 - 1);
		else
			return okm(s, p, s1, s2, p1, p2 - 2);
	}
	else
		return s[s2] == p[p2] && okm(s, p, s1, s2 - 1, p1, p2 - 1);
}
bool match(char* str, char* pattern)
{
	return okm(str,pattern,0,strlen(str)-1, 0, strlen(pattern)-1);
}
};