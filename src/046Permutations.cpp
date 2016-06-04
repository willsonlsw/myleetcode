#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > permute(vector<int> &nums){
		vector<vector<int> > res;
		vector<bool> flag(nums.size(), 0);
		vector<int> select(nums.size(), 0);
		addNum(res, nums, flag, select, nums.size());
		return res;
	}
	
	void addNum(vector<vector<int> > &res, vector<int> &nums, vector<bool> &flag, vector<int> &select, int n){
		if (n == 0){
			res.push_back(select);
			return;
		}
		for (int i = 0; i < nums.size(); ++i)
			if (!flag[i]) {
				select[n-1] = nums[i];
				flag[i] = 1;
				addNum(res, nums, flag, select, n-1);
				flag[i] = 0;
			}
	}
};

int main(){
	int n, x;
	vector<int> nums;
	cin >> n;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	vector<vector<int> > res = sc.permute(nums);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;	
}