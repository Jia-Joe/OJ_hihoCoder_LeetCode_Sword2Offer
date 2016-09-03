class Solution {
public:
	string convert(string s, int numRows) {
		string y = "";
		if (s.size() == 0) return y;
		if (numRows == 1) return s;
		int n = numRows, pd = 2 * n - 2;
		int kp = s.size() / pd, rp = s.size() % pd, icol[1000] = { kp };
		icol[0] = rp>0 ? kp + 1 : kp;
		icol[n - 1] = rp >= n ? kp + 1 : kp;
		for (int i = 1; i < n - 1; i++){
			icol[i] = 2 * kp;
		}
		for (int i = 1; i<n - 1; i++){
			if (rp>i)
				icol[i]++;
			if (rp - n >= i)
				icol[n - i - 1]++;
		}
		for (int i = 0; i<icol[0]; i++)
			y += s[i*pd];
		for (int i = 1; i<n - 1; i++){

			for (int j = 0; j<icol[i]; j++){
				if (j % 2 == 0){
					y += s[i + j / 2 * pd];
				}
				else{
					y += s[i + j / 2 * pd + 2 * (n - 1 - i)];
				}
			}
		}
		for (int i = 0; i<icol[n - 1]; i++)
			y += s[n - 1 + i*pd];
		return y;
	}
};