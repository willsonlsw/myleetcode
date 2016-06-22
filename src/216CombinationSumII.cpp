#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void getRes(vector<vector<int> > &res, vector<int> &select, int k, int n, int idx){
		if (k < 0 || n < 0) return;
		if (k == 0 && n == 0) {
			res.push_back(select);
			return;
		}
		for (int i = idx; i <= 9; ++i) {
			select.push_back(i);
			getRes(res, select, k-1, n-i, i+1);
			select.pop_back();
		}
	}
	
	vector<vector<int> > combinationSum3(int k, int n) {
		vector<vector<int> > res;
		vector<int> select;
		getRes(res, select, k, n, 1);
		return res;
	}
};

int main(){
	int n, k;
	cin >> k >> n;
	Solution sc;
	vector<vector<int> > res = sc.combinationSum3(k, n);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}