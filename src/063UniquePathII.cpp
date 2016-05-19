#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		int **f = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; ++i)
			f[i] = (int*)malloc(sizeof(int*) * n);
			 
		for (int i = 0; i < m; ++i) f[i][0] = 0;
		for (int j = 0; j < n; ++j) f[0][j] = 0;
		
		if (obstacleGrid[0][0] != 1) f[0][0] = 1;
		else return 0;
		
		int upN, leftN;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j){
				if (obstacleGrid[i][j] == 1) f[i][j] = 0;
				else {
				    if (i == 0 && j == 0) f[i][j] == 1;
				    else{
				        if (i > 0) upN = f[i-1][j]; else upN = 0;
				        if (j > 0) leftN = f[i][j-1]; else leftN = 0;
				        f[i][j] = upN + leftN;
				    }
				}
			}
		
		int rst = f[m-1][n-1];
		for (int i = 0; i < m; ++i)
			free(f[i]);
		free(f);
		
		return rst;        
    }
	}
};


int main(){

}