#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	void rotate(vector<vector<int> > &matrix){
		int n = matrix.size();
		partRotate(matrix, 0, n-1, 0, n-1);
	}
	
	void partRotate(vector<vector<int> > &matrix, int sv, int ev, int sh, int eh){
		if (sv >= ev ||sh >= eh) return;
		int v1, v2, v3, v4;
		for (int i = sh; i < eh; ++i) {
			v1 = matrix[sv][i];
			v2 = matrix[i][eh];
			v3 = matrix[ev][eh-(i-sh)];
			v4 = matrix[ev-(i-sh)][sh];
			matrix[sv][i] = v4;
			matrix[i][eh] = v1;
			matrix[ev][eh-(i-sh)] = v2;
			matrix[ev-(i-sh)][sh] = v3;			
		}
		partRotate(matrix, sv+1, ev-1, sh+1, eh-1);
	}
};

int main(){
	int n, x;
	cin >> n;
	vector<vector<int> > matrix(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			cin >> x;
			matrix[i][j] = x;
		}
	Solution sc;
	sc.rotate(matrix);
	for (int i = 0; i < matrix.size(); ++i){
		for (int j = 0; j < matrix.size(); ++j)
			cout << matrix[i][j] << ' ';
		cout << endl;
	}
	return 0;
}