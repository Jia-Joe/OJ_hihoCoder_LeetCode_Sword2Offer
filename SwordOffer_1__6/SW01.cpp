bool ok(vector<vector<int> > array, int target, int xp, int xq, int yp, int yq){
	if (xp > xq) return false;
	int mx = (xp + xq) >> 1, ip = yp, iq = yq, my = (ip + iq) >> 1;
	while (ip <= iq){
		my = (ip + iq) >> 1;
		if (target == array[my][mx]) return true;
		else if (target > array[my][mx])
			ip = my + 1;
		else
			iq = my - 1;
	}
	return ok(array, target, xp, mx - 1, my, yq) || ok(array, target, mx + 1, xq, yp, my);
}
bool Find(vector<vector<int> > array, int target) {
	int ry = array.size();
	if (ry == 0) return false;
	int rx = array[0].size();
	return ok(array, target, 0, rx-1, 0, ry-1);
}