#include <iostream>
#include <cstdlib>
using namespace std;

class Solution{
public:
	int uniquePaths(int m, int n){
		int **f = (int**)malloc(sizeof(int*) * m);
		for (int i = 0 ; i < m; i++)
			f[i] = (int*)malloc(sizeof(int) * n);
		
		for (int i = 0; i < m; ++i) f[i][0] = 1;
		for (int j = 0; j < n; ++j) f[0][j] = 1;
		
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j){
				f[i][j] = f[i-1][j] + f[i][j-1];
			}
	
		int rst = f[m-1][n-1];
		for (int i = 0; i < m; i++)
			free(f[i]);
		free(f);		
		return rst;
	}
};

int main(){
	Solution sc;
	int a, b;
	while(cin >> a >> b){
		cout << sc.uniquePaths(a, b) << endl;
	}
	return 0;
}