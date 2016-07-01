class NumMatrix {
public:
	int **su;
	NumMatrix(vector<vector<int>> &matrix) {
		int ay = matrix.size();
		if (ay != 0){
			int ax = matrix[0].size();
			su = new int*[ay + 1];
			for (int i = 0; i<ay + 1; i++)
				su[i] = new int[ax + 1];
			for (int i = 0; i<ax + 1; i++)
				su[0][i] = 0;
			for (int i = 1; i<ay + 1; i++)
				su[i][0] = 0;
			for (int i = 1; i<ay + 1; i++)
			for (int j = 1; j < ax + 1; j++){
				su[i][j] = matrix[i - 1][j - 1] + su[i - 1][j] + su[i][j - 1] - su[i - 1][j - 1];
			}
		}				
	}
	int sumRegion(int row1, int col1, int row2, int col2) {
		return su[row2+1][col2+1] - su[row2+1][col1] - su[row1][col2+1] + su[row1][col1];
	}
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);