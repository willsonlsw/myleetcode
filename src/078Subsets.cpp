#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
	
	int getsum(int n){
		int sum = 0;
		for (int i = 0; i < n; ++i)
			sum = (sum << 1) + 1;
		return sum;
	}
	
	vector<int> getSubset(vector<int>& nums, int n){
		int i = 0;
		bool flag;
		vector<int> tmp;
		while (n > 0){
			flag = n & 1;
			if (flag) tmp.push_back(nums[i]);
			n >>= 1;
			i++;
		}
		return tmp;
	}
	
	vector<vector<int> > subsets(vector<int>& nums){
		sort(nums.begin(), nums.end());
		int setN = getsum(nums.size());
		vector<vector<int> > res;
		for (int i = 0; i <= setN; ++i)
			res.push_back(getSubset(nums, i));
		return res;
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
	vector<vector<int> > res = sc.subsets(nums);
	for (int i = 0; i < res.size(); ++i){ 
		for (int j = 0; j < res[i].size(); ++j)
			cout << res[i][j] << " ";
		cout << endl; 
	}
	return 0;
}