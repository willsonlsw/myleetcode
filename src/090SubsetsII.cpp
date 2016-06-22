#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int> > subsetsWithDup(vector<int> &nums){
		sort(nums.begin(), nums.end());
		vector<vector<int> > res;
		vector<int> select;
		getSolution(nums, res, select, 0);
		return res;
	}
	
	void getSolution(vector<int> &nums, vector<vector<int> > &res, vector<int> &select, int idx){
		res.push_back(select);
		int i = idx;
		while (i < nums.size()){
			select.push_back(nums[i]);
			getSolution(nums, res, select, i + 1);
			select.pop_back();
			while (i + 1 < nums.size() && nums[i] == nums[i+1]) i++;
			i++;
		}
	}
};

int main(){
	int n, x;
	cin >> n;
	vector<int> nums;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	vector<vector<int> > res = sc.subsetsWithDup(nums);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}