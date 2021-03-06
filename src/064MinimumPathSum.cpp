#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	int minPathSum(vector<vector<int> >& grid){
		int m = grid.size();
		int n = grid[0].size();
		int **f = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; ++i)
			f[i] = (int *)malloc(sizeof(int) * n);
		
		int upsum, lefrsum;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j){
				if (i > 0) upsum = f[i-1][j]; else upsum = 0;
				if (j > 0) leftsum = f[i][j-1]; else leftsum = 0;
				f[i][j] = grid[i][j] + min(upsum, leftsum);
			}
		
		int rst = f[i-1][j-1];
		for (int i = 0; i < m; ++i)
			free(f[i]);
		free(f);
		
		return rst;
	}
};


int main(){
	
	return 0;
}