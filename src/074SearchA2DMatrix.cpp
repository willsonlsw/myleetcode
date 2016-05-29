#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	bool searchMatrix(vector<vector<int> >& matrix, int target){
		int l, r, mid, row;
		int n = matrix.size(), m = matrix[0].size();
		l = 0; r = n - 1;
		while (l <= r){
			mid = (l + r) >> 1;
			if (matrix[mid][0] <= target && matrix[mid][m-1] >= target) {
				row = mid;
				break;
			}
			if (matrix[mid][0] > target) r = mid - 1;
			else if (matrix[mid][m-1] < target) l = mid + 1;
		}
		if (l > r) return false;
		l = 0; r = m - 1;
		while (l <= r){
			mid = (l + r) >> 1;
			if (matrix[row][mid] == target) return true;
			if (matrix[row][mid] > target) r = mid - 1;
			else l = mid + 1;
		}
		return false;
	}
};


int main(){
	return 0;
}