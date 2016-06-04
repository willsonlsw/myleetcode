#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int> > permuteUnique(vector<int> &nums){
		sort(nums.begin(), nums.end());
		vector<vector<int> > res;
		vector<int> select(nums.size(), 0);
		vector<bool> flag(nums.size(), 0);
		addNum(res, nums, select, flag, 0);
		return res;
	} 
	
	void addNum(vector<vector<int> > &res, vector<int> &nums, vector<int> &select, vector<bool> &flag, int idx){
		if (idx == nums.size()){
			res.push_back(select);
			return;
		}
		
		int last;
		int i = 0; 
		while (i < nums.size()){
			if (flag[i]) {
				i++;
				continue;
			}
			select[idx] = nums[i];
			flag[i] = 1;
			addNum(res, nums, select, flag, idx+1);
			flag[i] = 0;
			last = nums[i];
			while (i < nums.size() && nums[i] == last) i++;
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
	vector<vector<int> > res = sc.permuteUnique(nums);
	for (int i = 0; i < res.size(); ++i){
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}