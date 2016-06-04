#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int> > combinationSum2(vector<int> &candidates, int target){
		sort(candidates.begin(), candidates.end());
		vector<vector<int> > res;
		vector<int> select;
		findRes(candidates, select, res, 0, 0, target);
		return res;
	}
	
	void findRes(vector<int> &candidates, vector<int> &select, vector<vector<int> > &res, int idx, int n, int target){
		if (target == 0) {
			vector<int> tmp;
			for (int i = 0; i < n; ++i) tmp.push_back(select[i]);
			res.push_back(tmp);
			return;
		}
		if (target < 0) return;
		if (idx >= candidates.size()) return;
			
		if (select.size() <= n) select.push_back(0);
		int last;
		for (int i = idx; i < candidates.size(); ++i){
			if (i != idx && candidates[i] == last) continue;
			last = candidates[i];
			select[n] = candidates[i];
			findRes(candidates, select, res, i+1, n+1, target-candidates[i]);
		}
	}
};


int main(){
	int n, x, t;
	vector<int> nums;
	cin >> n >> t;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	vector<vector<int> > res = sc.combinationSum2(nums, t);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << ' ';
		cout << endl;
	}
	return 0;
}