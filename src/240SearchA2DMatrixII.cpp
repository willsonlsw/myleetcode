#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool searchMatrix(vector<vector<int> >& matrix, int target){
		int n = matrix.size();
		if (n == 0) return false;
		int m = matrix[0].size();
		if (m == 0) return false;
		findTarget(matrix, 0, n-1, m-1, target);
	}
	
	bool findTarget(vector<vector<int> >& matrix, int c, int n, int r, int target){
		if (c > n || r < 0) return false;
		if (matrix[c][r] == target) return true;
		while (r >= 0 && matrix[c][r] > target) r--;
		while (c <= n && matrix[c][r] < target) c++;
		findTarget(matrix, c, n, r, target);
	}
};

int main(){
	return 0;
}