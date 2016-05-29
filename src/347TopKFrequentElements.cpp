#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
	static bool cmp(pair<int, int> &a, pair<int, int> &b){
		return a.first > b.first;
	}
	
	vector<int> topKFrequent(vector<int>& nums, int k){
		int x, n = nums.size(), count = 0;
		vector<pair<int, int> > nc;
		sort(nums.begin(), nums.end());
		x = nums[0];
		for (int i = 0; i < n; ++i){
			if (nums[i] == x) count++;
			else {
				pair<int, int> p(count, x);
				nc.push_back(p);
				count = 1;
				x = nums[i];
			}
		}
		pair<int, int> p(count, x);
		nc.push_back(p);
		sort(nc.begin(), nc.end(), cmp);
		vector<int> rst;
		for (int i = 0; i < k; ++i)
			rst.push_back(nc[i].second);
		return rst;
	}
};


int main(){
	int n, x, k;
	vector<int> nums;
	cin >> n >> k;
	for (int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	vector<int> rst = sc.topKFrequent(nums, k);
	for (int i = 0; i < rst.size(); ++i)
		cout << rst[i] << " ";
	cout << endl;
	return 0;
}