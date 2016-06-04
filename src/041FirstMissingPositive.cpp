#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	int firstMissingPositive(vector<int>& nums){
		int n = nums.size(), tmp, idx;
		for (int i = 0; i < n; ++i){
			if (nums[i] > 0 && nums[i] < i+1){
				idx = nums[i] - 1;
				if (nums[idx] == nums[i]) continue; 
				tmp = nums[idx];
				nums[idx]  = nums[i];
				nums[i] = tmp;
				if (nums[i] < i + 1) i--;
			}
		}
		
		for (int i = 0; i < nums.size(); ++i)
			cout << nums[i] << ' ';
		cout << endl;
		
		for (int i = 0; i < n; ++i)
			if (nums[i] != i + 1) return i + 1;
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
	cout << sc.firstMissingPositive(nums) << endl;
	return 0;
}