#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int majorityElement(vector<int>& nums){
		return findnum(nums, 0, nums.size()-1, (nums.size() - 1) / 2);
	}
	
	int findnum(vector<int>& nums, int l, int r, int k){
		int pivote = nums[l], i = l, j = r;
		while (i < j) {
			while (i < j && nums[j] >= pivote) j--;
			nums[i] = nums[j];
			while (i < j && nums[i] <= pivote) i++;
			nums[j] = nums[i];
		}
		nums[i] = pivote;
		if (i == k) return nums[i];
		if (i > k) return findnum(nums, l, i - 1, k);
		else return findnum(nums, i + 1, r, k);
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
	cout << sc.majorityElement(nums) << endl;
	return 0;
}