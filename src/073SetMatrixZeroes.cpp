#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
  	int m = matrix.size(), n = matrix[0].size();
  	bool r0 = false, c0 = false;
  	for (int i = 0; i < m; ++i)
  		if (matrix[i][0] == 0) {
  			c0 = 1;
  			break;
  		}
  		
  	for (int j = 0; j < n; ++j)
  		if (matrix[0][j] == 0) {
  			r0 = 1;
  			break;
  		}
  	
  	for (int i = 0; i < m; i++)
  		for (int j = 0; j < n; j++)
  			if (matrix[i][j] == 0){
  				matrix[0][j] = 0;
  				matrix[i][0] = 0;
  			}
  	
  	for (int i = 1; i < m; i++)
  		if (matrix[i][0] == 0)
  			for (int j = 0; j < n; j++)
  				matrix[i][j] = 0;
  	for (int j = 1; j < n; j++)
  		if (matrix[0][j] == 0)
  			for (int i = 0; i < m; i++)
  				matrix[i][j] = 0;
  	if (r0) for (int i = 0; i < n; i++) matrix[0][i] = 0;
  	if (c0) for (int j = 0; j < m; j++) matrix[j][0] = 0;
	}
};

int main(){
	return 0;
}