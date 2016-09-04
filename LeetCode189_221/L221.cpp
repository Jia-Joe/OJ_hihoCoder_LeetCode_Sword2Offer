//DP
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ret = 0; bool f=0;
	    int yr = matrix.size(); if (yr == 0) return 0;
	    int xr = matrix[0].size();
	    int **dp=new int*[yr];
	    for(int i=0;i<yr;i++){
	        dp[i]=new int[xr];
	    }
	    for(int i=0;i<xr;i++){
	        if(matrix[0][i]=='0'){
	            dp[0][i]=0;
	        }
	        else{
	            dp[0][i]=1; f=1;
	        }
	    }
	    for(int i=0;i<yr;i++){
	        if(matrix[i][0]=='0'){
	            dp[i][0]=0;
	        }
	        else{
	            dp[i][0]=1; f=1;
	        }
	    }
	    if(f) ret++;
	    for(int i=1;i<yr;i++){
	        for(int j=1;j<xr;j++){
	            if(matrix[i][j]=='0') dp[i][j]=0;
	            else{
	                int t0=dp[i-1][j-1],t1=dp[i-1][j],t2=dp[i][j-1];
	                if(t0>t1) t0=t1;
	                if(t0>t2) t0=t2; t0++;
	                dp[i][j]=t0;
	                if(ret<t0) ret=t0;
	            }
	        }
	    }
	    return ret*ret;
    }
};

class Solution {
public:
    bool ok(vector<vector<char>>& v, int x, int y, int mx, int my, int n){
    	if (x + n > mx || y + n > my) return 0;
    	for (int i = y; i<y + n&&i<my; i++){
    		for (int j = x; j<x + n&&j<mx; j++){
    			if (v[i][j] == '0'){
    				return 0;
    			}
    		}
    	}
    	return 1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
    	int ret = 0, k = 1;
    	int yr = matrix.size(); if (yr == 0) return 0;
    	int xr = matrix[0].size();
    	for (int i = 0; i<=yr - k; i++){
    		for (int j = 0; j<=xr - k; j++){
    			while (1){
    				if (ok(matrix, j, i, xr, yr, k)){
    					cout << "i " << i << "j " << j << "k " << k << endl;
    					k++;
    				}
    					
    				else
    					break;
    			}
    		}
    
    	}
    	ret = (k - 1)*(k - 1);
    	return ret;
    }
};