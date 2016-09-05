class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int ry = matrix.size();
        vector<int> v;
        if (ry == 0) return v;
        int rx = matrix[0].size(), n = 0, di[4] = { 1, rx, -1, -rx };
        for (int cy = 0; cy < min(rx, ry)/2+1; ++cy){
            for (int i = cy; i <rx - cy; i++){
                if (n == rx*ry) break; 
                v.push_back(matrix[cy][i]);
                ++n;
            }
            for (int j = cy + 1; j<ry - cy; j++){
                if (n == rx*ry) break;
                v.push_back(matrix[j][rx-1-cy]);
                ++n;
            }
            for (int i = rx - 2 - cy; i >cy - 1; i--){
                if (n == rx*ry) break;
                v.push_back(matrix[ry-1-cy][i]);
                ++n;
            }
            for (int j = ry - 2 - cy; j > cy; j--){
                if (n == rx*ry) break;
                v.push_back(matrix[j][cy]);
                ++n;
            }
        }
        //for (int x : v)
        //	cout << x << " ";
        return v;
    }
};