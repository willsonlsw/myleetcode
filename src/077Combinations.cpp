#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	vector<vector<int> > combine(int n, int k){
		vector<vector<int> > res;
		vector<int> select;
		addCombination(res, select, n, 1, 0, k);
		return res;
	}
	
	void addCombination(vector<vector<int> > &res, vector<int> &select, int n, int x, int m, int k){
		if (k == m){
			res.push_back(select);
			return;
		}
		
		if (m >= select.size()) select.push_back(0);
		for (int i = x; i <= n-(k-m-1); i++){
			select[m] = i;
			addCombination(res, select, n, i+1, m+1, k);
		}
	}
};

int main(){
	int k, n;
	cin >> n >> k;
	Solution sc;
	vector<vector<int> > res = sc.combine(n, k);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}