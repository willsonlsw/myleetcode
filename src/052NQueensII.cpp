#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int totalNQueens(int n){
		int res = 0;
		vector<bool> flag(n, 0), leftd(n, 0), rightd(n, 0);
		addSolution(res, n, flag, leftd, rightd, 0);
		return res;
	}
	
	void addSolution(int &res, int n, vector<bool> &flag, vector<bool> &leftd, vector<bool> &rightd, int idx){
		if (idx == n) {
			res++;
			return;
		}
		for (int i = 0; i < n; ++i)
			if (!flag[i] && !leftd[idx+i] && !rightd[idx+n-i]) {
				flag[i] = leftd[idx+i] = rightd[idx+n-i] = 1;
				addSolution(res, n, flag, leftd, rightd, idx+1);
				flag[i] = leftd[idx+i] = rightd[idx+n-i] = 0;
			}
	}
};

int main(){
	int n;
	cin >> n;
	Solution sc;
	cout << sc.totalNQueens(n) << endl;
	return 0;
}