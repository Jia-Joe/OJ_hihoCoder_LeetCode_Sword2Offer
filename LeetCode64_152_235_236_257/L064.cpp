class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ry=grid.size(),rx=grid[0].size();
        vector<vector<int>> d(ry+1,vector<int>(rx+1,INT_MAX));
        if(rx==1&&ry==1) return grid[0][0];
        if(rx>1) d[0][1]=0;
        if(ry>1) d[1][0]=0;
        for(int i=1;i<=ry;i++){
            for(int j=1;j<=rx;j++){
                d[i][j]=min(d[i-1][j],d[i][j-1])+grid[i-1][j-1];
            }
        }
        for(int i=0;i<=ry;i++){
            for(int j=0;j<=rx;j++){
                cout<<d[i][j]<<" ";
            }
            cout<<endl;
        }
        return d[ry][rx];
    }
};