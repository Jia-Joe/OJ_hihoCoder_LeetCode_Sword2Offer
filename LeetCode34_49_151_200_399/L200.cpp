int find(vector<int> &uf, int x){
	while (uf[x] != x) x = uf[x];
	return x;
}
int numIslands(vector<vector<char>>& grid) {
	int yz = grid.size(), n = 0;
	if (yz == 0) return 0;
	int xz = grid[0].size();
	vector<int> uf(yz*xz), vz(yz*xz, 1);
	for (int i = 0; i<yz*xz; i++){
		uf[i] = i;
	}
	for (int i = 0; i<yz; i++){
		for (int j = 0; j<xz; j++){
			if (grid[i][j] == '1'){
				int wo = i*xz + j;
				int f = 0;
				if (j>0 && grid[i][j - 1] == '1'){					
					int w = i*xz + j - 1, fd = find(uf, w);
					uf[wo] = fd;
					vz[fd]++;
					f++;
				}
				if (i>0 && grid[i - 1][j] == '1'){
					
					int w = (i - 1)*xz + j, fo = find(uf, wo), fd = find(uf, w);
					if (fo != fd){
						if (vz[fo]<vz[fd]){
							uf[fo] = fd;
							vz[fd] += vz[fo];
						}
						else{
							uf[fd] = fo;
							vz[fo] += vz[fd];
						}
						if(f) 
							n--;
					}
					else{
						uf[fo] = fd;
						vz[fd]++;
					}
					f++;
				}
				if (!f){
					n++;
					//cout << i << " " << j << endl;
				}
			}
		}
	}
	return n;
}