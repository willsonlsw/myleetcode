#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	int findKthLargest(vector<int>& nums, int k){
		int n = nums.size()-1;
		k = n - k + 1;
		return kLargest(nums, 0, n, k);
	}
	
	int kLargest(vector<int>& nums, int l, int r, int k){
		int i=l, j=r, pivote=nums[l];
		while (i < j){
			while (i < j && pivote <= nums[j]) j--;
			nums[i] = nums[j];
			while (i < j && nums[i] <= pivote) i++;
			nums[j] = nums[i];
		}
		nums[i] = pivote;
		if (i==k) return nums[i];
		else if (i < k) return kLargest(nums, i+1, r, k);
		else return kLargest(nums, l, i-1, k);
	} 
};


int main(){
	int n, x, k;
	vector<int> nums;
	cin >> n >> k; 
	for(int i = 0; i < n; ++i){
		cin >> x;
		nums.push_back(x);
	}
	Solution sc;
	cout << sc.findKthLargest(nums, k) << endl;
	return 0;
}